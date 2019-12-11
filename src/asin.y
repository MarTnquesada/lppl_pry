/*****************************************************************************/
/**  GRUPO 12:                                                              **/                                                                            
/**  Martin Quesada Zaragoza                                                **/
/**  Nahuel Unai Rosello Beneitez                                           **/
/**  Manuel Rosello Oviedo                                                  **/                                    
/*****************************************************************************/
%{
#include <stdio.h>
#include <string.h>
#include "header.h"
#include "libtds.h"
#include "libgci.h"
%}

%union {
    char *id;
    int cte;
    int tipo;
    LCSTRUCT lcstr;
    CTESTRUCT ctestr;
}

%token STRUCT_ INT_ BOOL_ READ_ PRINT_ WHILE_ FOR_ IF_ ELSE_ TRUE_ FALSE_
%token SEP_ SEMICOL_ MAS_ MENOS_ NOT_ POR_ DIV_ MOD_ MASMAS_ MENOSMENOS_ 
%token APAR_ CPAR_ ACOR_ CCOR_ ALLAV_ CLLAV_ AND_ OR_
%token ASIG_ MASASIG_ MENOSASIG_ PORASIG_ DIVASIG_
%token ASIGASIG_ NOTASIG_ MAYOR_ MENOR_ MAYORASIG_ MENORASIG_
%token <id> ID_
%token <cte> CTE_

%type <ctestr> constante
%type <ctestr> expresion expresionAditiva expresionIgualdad expresionLogica
%type <ctestr> expresionMultiplicativa expresionRelacional expresionSufija expresionUnaria
%type <ctestr> operadorUnario
%type <tipo> tipoSimple
%type <lcstr> listaCampos
%type <tipo> operadorAditivo operadorMultiplicativo operadorIncremento

%%

programa                : ALLAV_ { dvar = 0; si = 0; } secuenciaSentencias CLLAV_ { if (verTDS) { verTdS(); } }
                        ;
secuenciaSentencias     : sentencia
                        | secuenciaSentencias sentencia
                        ;
sentencia               : declaracion
                        | instruccion
                        ;
declaracion             : tipoSimple ID_ SEMICOL_
                            {
                                SIMB sim = obtTdS($2);
                                if (sim.tipo != T_ERROR) {
                                    yyerror("Error en la declaracion de la variable: variable ya declarada.");
                                }
                                else {
                                    insTdS($2, $1, dvar, -1);
                                    dvar += TALLA_TIPO_SIMPLE;
                                }
                            }
                        | tipoSimple ID_ ASIG_ constante SEMICOL_
                            {
                                SIMB sim = obtTdS($2);
                                if (sim.tipo != T_ERROR) {
                                    yyerror("Error en la declaracion de la variable: variable ya declarada.");
                                }
                                else if ($1 != $4.tipo) {
                                    yyerror("Error en la declaracion de la variable: error de incompatibilidad de tipos.");
                                }
                                else {EIGUAL
                                    insTdS($2, $1, dvar, -1);
                                    dvar += TALLA_TIPO_SIMPLE;
                                }
                            }
                        | tipoSimple ID_ ACOR_ CTE_ CCOR_ SEMICOL_
                            {
                                SIMB sim = obtTdS($2);
                                if (sim.tipo != T_ERROR) {
                                    yyerror("Error en la declaracion del vector: vector ya declarado.");
                                }
                                else if ($4 <= 0) {
                                    yyerror("Error en la declaracion del vector: talla inapropiada.");
                                }
                                else {
                                    int arrayRef = insTdA($1, $4);
                                    insTdS($2, T_ARRAY, dvar, arrayRef);
                                    dvar += TALLA_TIPO_SIMPLE * $4;
                                }
                            }
                        | STRUCT_ ALLAV_ listaCampos CLLAV_ ID_ SEMICOL_
                            {
                                SIMB sim = obtTdS($5);
                                if (sim.tipo != T_ERROR) {
                                    yyerror("Error en la declaracion de la estructura: estructura ya declarada.");
                                }
                                else {
                                    insTdS($5, T_RECORD, dvar, $3.regRef);
                                    dvar += $3.talla;
                                }
                            }
                        ;
tipoSimple              : INT_
                            {
                                $$ = T_ENTERO;
                            }
                        | BOOL_
                            {
                                $$ = T_LOGICO;
                            }
                        ;
listaCampos             : tipoSimple ID_ SEMICOL_
                            {
                                int regRef = insTdR(-1, $2, $1, 0);
                                $$.talla = TALLA_TIPO_SIMPLE;
                                $$.regRef = regRef;
                            }
                        | listaCampos tipoSimple ID_ SEMICOL_
                            {
                                CAMP sim = obtTdR($1.regRef, $3);
                                if (sim.tipo != T_ERROR) {
                                    yyerror("Error en la declaracion de la estructura: campo duplicado");
                                }
                                /* No se tiene que comprobar si ya existe en la tabla
                                de simbolos, porque es un campo del registro y no una
                                variable del programa */
                                insTdR($1.regRef, $3, $2, $1.talla);
                                $$.talla += TALLA_TIPO_SIMPLE;
                                $$.regRef = $1.regRef;
                            }
                        ;
instruccion             : ALLAV_ CLLAV_
                        | ALLAV_ listaInstrucciones CLLAVEIGUAL
                        | instruccionEntradaSalida
                        | instruccionSeleccion
                        | instruccionIteracion
                        | instruccionExpresion
                        ;
listaInstrucciones      : instruccion
                        | listaInstrucciones instruccion
                        ;
instruccionEntradaSalida : READ_ APAR_ ID_ CPAR_ SEMICOL_EIGUAL
                            {
                                SIMB sim = obtTdS($3);
                                if (sim.tipo == T_ERROR) {
                                    yyerror("Error en la instruccion de lectura: variable no declarada.");
                                }
                                else if (sim.tipo != T_ENTERO) {
                                    yyerror("Error en la instruccion de lectura: la variable no es de tipo entero.");
                                }
                                else {
                                    
                                }
                            }
                        | PRINT_ APAR_ expresion CPAR_ SEMICOL_
                            {
                                if ($3.tipo == T_ERROR) {
                                    // Ninguna salida por pantalla, ya la hemos hecho donde toca
                                }
                                else if ($3.tipo != T_ENTERO) {
                                    yyerror("Error en la instruccion de escritura: la variable no es de tipo entero.");
                                }
                                else {
                                    // Pensamos que si es una variable hay que usar crArgPos()
                                    // y si es una constante hay que usar crArgEnt()
                                    emite(EWRITE, crArgNul(), crArgNul(), crArgPos($3.pos));
                                }
                            }
                        ;
instruccionSeleccion    : IF_ APAR_ expresion CPAR_
                            {
                                // TODO: meter código a mitad de regla xd
                                // Si hay $$ a mitad de regla no va a la parte izquierda de la regla!!
                                // Cómo ir a la parte izquierda?
                                // Solución: bison crea un no-terminal @1, @2, ..., por lo que OJO! Los $<número> se modifican
                                // Hay que especificar el tipo de $$ en cada secuencia a mitad de regla tal que así:
                                // $< <tipo-variable> >$.[...]
                                // Y después podemos usar este bloque de código tal que así. Imaginando que nos referimos al primer bloque (nuevo no-terminal 2):
                                // $< <tipo-variable> >2.[...]
                                if ($3.tipo == T_ERROR) {
                                    // Ninguna salida por pantalla, ya la hemos hecho donde toca
                                }
                                else if ($3.tipo != T_LOGICO) {
                                    yyerror("Error en la expresion condicional: expresion no valida en la guarda.");
                                }
                            }
                        instruccion ELSE_ instruccion
                        ;
instruccionIteracion    : WHILE_ APAR_ expresion CPAR_
                            {
                                // TODO: meter código a mitad de regla xd
                                if ($3.tipo == T_ERROR) {
                                    // Ninguna salida por pantalla, ya la hemos hecho donde toca
                                }
                                else if ($3.tipo != T_LOGICO) {
                                    yyerror("Error en la expresion de bucle: expresion no valida en la guarda.");
                                }
                            }
                        instruccion
                        ;
instruccionExpresion    : expresion SEMICOL_
                        | SEMICOL_
                        ;
expresion               : expresionLogica
                            {
                                $$.tipo = $1.tipo;
                                $$.pos = $1.pos;
                            }
                        | ID_ operadorAsignacion expresion
                            {
                                $$.tipo = T_ERROR;
                                SIMB sim = obtTdS($1);
                                if (sim.tipo == T_ERROR) {
                                    yyerror("Error en la asignacion: variable no declarada.");
                                }
                                else if ($3.tipo == T_ERROR) {
                                    // Ninguna salida por pantalla, ya la hemos hecho donde toca
                                }
                                else if (sim.tipo != $3.tipo) {
                                    yyerror("Error en la asignacion: error de incompatibilidad de tipos.");
                                }
                                else {
                                    $$.tipo = T_VACIO;
                                }
                            }
                        | ID_ ACOR_ expresion CCOR_ operadorAsignacion expresion
                            {
                                $$.tipo = T_ERROR;
                                SIMB sim = obtTdS($1);
                                if (sim.tipo == T_ERROR) {
                                    yyerror("Error en la asignacion: vector no declarado.");
                                }
                                else if (sim.tipo != T_ARRAY) {
                                    yyerror("Error en la asignacion: la variable no ha sido declarada como un vector.");
                                }
                                else {
                                    DIM arr = obtTdA(sim.ref);
                                    if (arr.telem == T_ERROR) {
                                        yyerror("Error en la asignacion: la variable no es un vector valido.");
                                    }
                                    else if ($3.tipo != T_ENTERO) {
                                        yyerror("Error en la asignacion: el indice del vector no es de tipo entero.");
                                    }
                                    else if ($6.tipo == T_ERROR) {
                                        // Ninguna salida por pantalla, ya la hemos hecho donde toca
                                    }
                                    else if (arr.telem != $6.tipo) {
                                        yyerror("Error en la asignacion: error de incompatibilidad de tipos.");
                                    }
                                    else {
                                        $$.tipo = T_VACIO;
                                    }
                                }
                            }
                        | ID_ SEP_ ID_ operadorAsignacion expresion
                            {
                                $$.tipo = T_ERROR;
                                SIMB sim = obtTdS($1);
                                if (sim.tipo == T_ERROR) {
                                    yyerror("Error en la asignacion: estructura no declarada.");
                                }
                                else if (sim.tipo != T_RECORD) {
                                    yyerror("Error en la asignacion: la variable no es de tipo 'struct'.");
                                }
                                else {
                                    CAMP camp = obtTdR(sim.ref, $3);
                                    if (camp.tipo == T_ERROR) {
                                        yyerror("Error en la asignacion: el campo referenciado no es un campo de la estructura.");
                                    }
                                    else if ($5.tipo == T_ERROR) {
                                        // Ninguna salida por pantalla, ya la hemos hecho donde toca
                                    }
                                    else if (camp.tipo != $5.tipo) {
                                        yyerror("Error en la asignacion: error de incompatibilidad de tipos.");
                                    }
                                    else {
                                        $$.tipo = T_VACIO;
                                    }
                                }
                            }
                        ;
expresionLogica         : expresionIgualdad
                            {
                                $$.tipo = $1.tipo;
                            }
                        | expresionLogica operadorLogico expresionIgualdad
                            {
                                $$.tipo = T_ERROR;
                                if ($1.tipo == T_ERROR || $3.tipo == T_ERROR) {
                                    // Ninguna salida por pantalla, ya la hemos hecho donde toca
                                }
                                else if ($1.tipo != T_LOGICO) {
                                    yyerror("Error en la expresion logica: el primer operando no es de tipo logico.");
                                }
                                else if ($3.tipo != T_LOGICO) {
                                   yyerror("Error en la expresion logica: el segundo operando no es de tipo logico."); 
                                }
                                else {
                                    $$.tipo = T_LOGICO;
                                }
                            }
                        ;
expresionIgualdad       : expresionRelacional
                            {
                                $$.tipo = $1.tipo;
                            }
                        | expresionIgualdad operadorIgualdad expresionRelacional
                            {
                                $$.tipo = T_ERROR;
                                if ($1.tipo == T_ERROR || $3.tipo == T_ERROR) {
                                    // Ninguna salida por pantalla, ya la hemos hecho donde toca
                                }
                                else if ($1.tipo != $3.tipo) {
                                    yyerror("Error en la expresion de igualdad: error de incompatibilidad de tipos.");
                                }
                                else {
                                    $$.tipo = T_LOGICO;
                                }
                            }
                        ;
expresionRelacional     : expresionAditiva
                            {
                                $$.tipo = $1.tipo;
                            }
                        | expresionRelacional operadorRelacional expresionAditiva
                            {
                                $$.tipo = T_ERROR;
                                if ($1.tipo == T_ERROR || $3.tipo == T_ERROR) {
                                    // Ninguna salida por pantalla, ya la hemos hecho donde toca
                                }
                                else if ($1.tipo != T_ENTERO) {
                                    yyerror("Error en la expresion relacional: el primer operando no es de tipo entero.");
                                }
                                else if ($3.tipo != T_ENTERO) {
                                   yyerror("Error en la expresion relacional: el segundo operando no es de tipo entero."); 
                                }
                                else {
                                    $$.tipo = T_LOGICO;
                                    // Si se cumple exprRel opRel exprAd, entonces ponemos 1. Si no, ponemos 0
                                    $$.pos = creaVarTemp();

                                    // Paso 0: si se cumple exprRel opRel exprAd, entonces saltamos a Paso 3.
                                    emite($2, crArgPos($1.pos), crArgPos($3.pos), crArgEtq(si + 3));
                                    // Paso 1: lo de arriba era falso. Ponemos falso.
                                    emite(EASIG, crArgEnt(FALSE), crArgNul(), crArgPos($$.pos));
                                    // Paso 2: Saltamos al Paso 4
                                    emite(GOTOS, crArgNul(), crArgNul(), crArgEtq(si + 2));
                                    // Paso 3: lo de arriba era verdadero. Ponemos verdadero.
                                    emite(EASIG, crArgEnt(TRUE), crArgNul(), crArgPos($$.pos));
                                    // Paso 4: se continúa la ejecución
                                }
                            }
                        ;
expresionAditiva        : expresionMultiplicativa
                            {
                                $$.tipo = $1.tipo;
                            }
                        | expresionAditiva operadorAditivo expresionMultiplicativa
                            {
                                $$.tipo = T_ERROR;
                                if ($1.tipo == T_ERROR || $3.tipo == T_ERROR) {
                                    // Ninguna salida por pantalla, ya la hemos hecho donde toca
                                }
                                else if ($1.tipo != T_ENTERO) {
                                    yyerror("Error en la expresion aditiva: el primer operando no es de tipo entero.");
                                }
                                else if ($3.tipo != T_ENTERO) {
                                   yyerror("Error en la expresion aditiva: el segundo operando no es de tipo entero."); 
                                }
                                else {
                                    $$.tipo = T_ENTERO;
                                    $$.pos = creaVarTemp();
                                    emite($2, crArgPos($1.pos), crArgPos($3.pos), crArgPos($$.pos));
                                }
                            }
                        ;
expresionMultiplicativa  : expresionUnaria 
                            {
                                $$.tipo = $1.tipo;
                            }
                        | expresionMultiplicativa operadorMultiplicativo expresionUnaria
                            {
                                $$.tipo = T_ERROR;
                                if ($1.tipo == T_ERROR || $3.tipo == T_ERROR) {
                                    // Ninguna salida por pantalla, ya la hemos hecho donde toca
                                }
                                else if ($1.tipo != T_ENTERO) {
                                    yyerror("Error en la expresion multiplicativa: el primer operando no es de tipo entero.");
                                }
                                else if ($3.tipo != T_ENTERO) {
                                   yyerror("Error en la expresion multiplicativa: el segundo operando no es de tipo entero."); 
                                }
                                else {
                                    $$.tipo = T_ENTERO;
                                }
                            }
                        ;
expresionUnaria         : expresionSufija
                            {
                                $$.tipo = $1.tipo;
                            }
                        | operadorUnario expresionUnaria
                            {
                                $$.tipo = T_ERROR;
                                if ($1.tipo != $2.tipo) {
                                    yyerror("Error en la expresion unaria: error de incompatibilidad de tipos.");
                                }
                                else {
                                    $$.tipo = $2.tipo;
                                    $$.pos = creaVarTemp();
                                    if ($1.tipo == T_ENTERO) {
                                        emite($1.pos, crArgEnt(0), crArgPos($2.pos), crArgPos($$.pos));
                                    }
                                    else {  // T_LOGICO
                                        // resultado = 1 - valor
                                        emite($1.pos, crArgEnt(1), crArgPos($2.pos), crArgPos($$.pos));
                                    }
                                }
                            }
                        | operadorIncremento ID_
                            {
                                $$.tipo = T_ERROR;
                                SIMB sim = obtTdS($2);
                                if (sim.tipo == T_ERROR) {
                                    yyerror("Error en la expresion unaria: variable no declarada.");
                                }
                                else if (sim.tipo != T_ENTERO) {
                                    yyerror("Error en la expresion unaria: operacion invalida para este tipo.");
                                }
                                else {
                                    $$.tipo = T_ENTERO;
                                    $$.pos = creaVarTemp();
                                    emite($1, crArgPos(sim.desp), crArgEnt(1), crArgPos(sim.desp));
                                    // También asignar al padre el valor del hijo
                                    emite(EASIG, crArgPos(sim.desp), crArgNul(), crArgPos($$.pos));
                                }
                            }EIGUAL
                        ;
expresionSufija         : APAR_ expresion CPAR_
                            {
                                $$.tipo = $2.tipo;
                                $$.pos = $2.pos;
                            }
                        | ID_ operadorIncremento
                            {
                                $$.tipo = T_ERROR;
                                SIMB sim = obtTdS($1);
                                if (sim.tipo == T_ERROR) {
                                    yyerror("Error en la expresion sufija: variable no declarada.");
                                }
                                else if (sim.tipo != T_ENTERO) {
                                    yyerror("Error en la expresion sufija: operacion invalida para este tipo.");
                                }
                                else {
                                    $$.tipo = T_ENTERO;
                                    $$.pos = creaVarTemp();
                                    // También asignar al padre el valor del hijo
                                    emite(EASIG, crArgPos(sim.desp), crArgNul(), crArgPos($$.pos));
                                    emite($1, crArgPos(sim.desp), crArgEnt(1), crArgPos(sim.desp));
                                }
                            }
                        | ID_ ACOR_ expresion CCOR_
                            {
                                $$.tipo = T_ERROR;
                                SIMB sim = obtTdS($1);
                                if (sim.tipo == T_ERROR) {
                                    yyerror("Error en la expresion sufija: vector no declarado.");
                                }
                                else if (sim.tipo != T_ARRAY) {
                                    yyerror("Error en la expresion sufija: la variable no es un vector.");
                                }
                                else {
                                    DIM arr = obtTdA(sim.ref);
                                    if (arr.telem == T_ERROR) {
                                        yyerror("Error en la expresion sufija: el vector referenciado no es un vector valido.");
                                    }
                                    else if ($3.tipo != T_ENTERO) {
                                        yyerror("Error en la expresion sufija: el indice del vector no es de tipo entero.");
                                    }
                                    else {
                                        $$.tipo = arr.telem;
                                        // Se comprueba en tiempo de ejecución, por lo que LO COMPROBAMOS LUEGO XD
                                    }
                                }
                            }
                        | ID_
                            {
                                $$.tipo = T_ERROR;
                                SIMB sim = obtTdS($1);
                                if (sim.tipo == T_ERROR) {
                                    yyerror("Error en la expresion sufija: variable no declarada.");
                                }
                                else {
                                    $$.tipo = sim.tipo;
                                    $$.pos = sim.desp;
                                }
                            }
                        | ID_ SEP_ ID_
                            {
                                $$.tipo = T_ERROR;
                                SIMB sim = obtTdS($1);
                                if (sim.tipo == T_ERROR) {
                                    yyerror("Error en la expresion sufija: estructura no declarada.");
                                }
                                else if (sim.tipo != T_RECORD) {
                                    yyerror("Error en la expresion sufija: la variable no es de tipo 'struct'.");
                                }
                                else {
                                    CAMP camp = obtTdR(sim.ref, $3);
                                    if (camp.tipo == T_ERROR) {
                                        yyerror("Error en la expresion sufija: el campo referenciado no es un campo de la estructura.");
                                    }
                                    else {
                                        $$.tipo = camp.tipo;
                                        int absDesp = sim.desp + camp.desp;
                                        $$.pos = creaVarTemp();
                                        emite(EASIG, absDesp, crArgNul(), crArgPos($$.pos));
                                    }
                                }
                            }
                        | constante
                            {
                                $$.tipo = $1.tipo;
                                $$.pos = $1.pos;
                            }
                        ;
constante               : CTE_
                            {
                                $$.tipo = T_ENTERO; $$.pos = $1;
                                $$.pos = creaVarTemp();
                                emite(EASIG, crArgEnt($1), crArgNul(), crArgPos($$.pos));
                            }
                        | TRUE_
                            {
                                $$.tipo = T_LOGICO;
                                $$.pos = creaVarTemp();
                                emite(EASIG, crArgEnt(TRUE), crArgNul(), crArgPos($$.pos));
                            }
                        | FALSE_
                            {
                                $$.tipo = T_LOGICO;
                                $$.pos = creaVarTemp();
                                emite(EASIG, crArgEnt(FALSE), crArgNul(), crArgPos($$.pos));
                            }
                        ;
operadorAsignacion      : ASIG_
                            {
                                // Comprobaremos que no sea EASIG
                                // si no lo es, hacemos la operacion correspondiente
                                // fuera de ese if, para todos los casos, hacemos asignacion
                                // De esta forma, conseguimos que asig solo se haga una vez para asig
                                // y que para los demas se haga la operacion y luego se asigne 
                                $$ = EASIG;
                            }
                        | MASASIG_
                            {
                                $$ = ESUM;
                            }
                        | MENOSASIG_
                        {
                                $$ = EDIF;
                            }
                        | PORASIG_
                            {
                                $$ = EMULT;
                            }
                        | DIVASIG_
                            {
                                $$ = EDIVI;
                            }
                        ;
operadorLogico          : AND_
                            {
                                // Multiplicamos, si da 1 true, si da 0 false
                                $$ = EMULT;
                            }
                        | OR_
                            {
                                // Sumamos, si da >=1 true, si da <1 false
                                $$ = ESUM;
                            }
                        ;
operadorIgualdad        : ASIGASIG_
                            {
                                $$ = EIGUAL;
                            }
                        | NOTASIG_
                            {
                                $$ = EDIST;
                            }
                        ;
operadorRelacional      : MAYOR_
                            {
                                $$ = EMAY;
                            }
                        | MENOR_
                            {
                                $$ = EMEN;
                            }
                        | MAYORASIG_
                            {
                                $$ = EMAYEQ;
                            }
                        | MENORASIG_
                            {
                                $$ = EMENEQ;
                            }
                        ;
operadorAditivo         : MAS_
                            {
                                $$ = ESUM;
                            }
                        | MENOS_
                            {
                                $$ = EDIF;
                            }
                        ;
operadorMultiplicativo  : POR_
                            {
                                $$ = EMULT;
                            }
                        | DIV_
                            {
                                $$ = EDIVI;
                            }
                        | MOD_
                            {
                                $$ = RESTO;
                            }
                        ;
operadorUnario          : MAS_
                            {
                                $$.tipo = T_ENTERO;
                                $$.pos = ESUM;
                            }
                        | MENOS_
                            {
                                $$.tipo = T_ENTERO;
                                $$.pos = EDIF;
                            }
                        | NOT_
                            {
                                // Restamos (1 - valor) ver arriba
                                $$.tipo = T_LOGICO;
                                $$.pos = EDIF;
                            }
                        ;
operadorIncremento      : MASMAS_
                            {
                                $$ = ESUM;
                            }
                        | MENOSMENOS_
                            {
                                $$ = EDIF;
                            }
                        ;
%%
/*****************************************************************************/
