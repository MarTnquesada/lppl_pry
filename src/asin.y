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
    JMPSTRUCT jmpstr;
}

%token STRUCT_ INT_ BOOL_ READ_ PRINT_ WHILE_ FOR_ IF_ ELSE_
%token SEP_ SEMICOL_ MAS_ MENOS_ NOT_ POR_ DIV_ MOD_ MASMAS_ MENOSMENOS_ 
%token APAR_ CPAR_ ACOR_ CCOR_ ALLAV_ CLLAV_ AND_ OR_
%token ASIG_ MASASIG_ MENOSASIG_ PORASIG_ DIVASIG_
%token ASIGASIG_ NOTASIG_ MAYOR_ MENOR_ MAYORASIG_ MENORASIG_
%token <id> ID_
%token <cte> CTE_ TRUE_ FALSE_

%type <ctestr> constante
%type <ctestr> expresion expresionAditiva expresionIgualdad expresionLogica
%type <ctestr> expresionMultiplicativa expresionRelacional expresionSufija expresionUnaria
%type <ctestr> operadorUnario 
%type <tipo> operadorLogico operadorRelacional operadorIgualdad operadorAditivo operadorAsignacion operadorMultiplicativo operadorIncremento
%type <tipo> tipoSimple
%type <lcstr> listaCampos
%type <jmpstr> instruccionSeleccion instruccionIteracion

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
                                if (!insTdS($2, $1, dvar, -1)) {
                                    yyerror("Error en la declaracion de la variable: variable ya declarada.");
                                }
                                else {
                                    dvar += TALLA_TIPO_SIMPLE;
                                }
                            }
                        | tipoSimple ID_ ASIG_ constante SEMICOL_
                            {
                                if ($1 != $4.tipo) {
                                    yyerror("Error en la declaracion de la variable: error de incompatibilidad de tipos.");
                                }
                                else if (!insTdS($2, $1, dvar, -1)) {
                                    yyerror("Error en la declaracion de la variable: variable ya declarada.");
                                }
                                else {
                                    emite(EASIG, crArgEnt($4.pos), crArgNul(), crArgPos(dvar));
                                    dvar += TALLA_TIPO_SIMPLE;
                                }
                            }
                        | tipoSimple ID_ ACOR_ CTE_ CCOR_ SEMICOL_
                            {
                                if ($4 <= 0) {
                                    yyerror("Error en la declaracion del vector: talla inapropiada.");
                                }
                                int arrayRef = insTdA($1, $4);
                                if (!insTdS($2, T_ARRAY, dvar, arrayRef)) {
                                    yyerror("Error en la declaracion del vector: vector ya declarado.");
                                }
                                else {
                                    dvar += TALLA_TIPO_SIMPLE * $4;
                                }
                            }
                        | STRUCT_ ALLAV_ listaCampos CLLAV_ ID_ SEMICOL_
                            {
                                
                                if (!insTdS($5, T_RECORD, dvar, $3.regRef)) {
                                    yyerror("Error en la declaracion de la estructura: estructura ya declarada.");
                                }
                                else {
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
                                if (insTdR($1.regRef, $3, $2, $1.talla) == -1) {
                                    yyerror("Error en la declaracion de la estructura: campo duplicado");
                                }
                                else {
                                    $$.talla += TALLA_TIPO_SIMPLE;
                                    $$.regRef = $1.regRef;
                                }
                            }
                        ;
instruccion             : ALLAV_ CLLAV_
                        | ALLAV_ listaInstrucciones CLLAV_
                        | instruccionEntradaSalida
                        | instruccionSeleccion
                        | instruccionIteracion
                        | instruccionExpresion
                        ;
listaInstrucciones      : instruccion
                        | listaInstrucciones instruccion
                        ;
instruccionEntradaSalida : READ_ APAR_ ID_ CPAR_ SEMICOL_
                            {
                                SIMB sim = obtTdS($3);
                                if (sim.tipo == T_ERROR) {
                                    yyerror("Error en la instruccion de lectura: variable no declarada.");
                                }
                                else if (sim.tipo != T_ENTERO) {
                                    yyerror("Error en la instruccion de lectura: la variable no es de tipo entero.");
                                }
                                else {
                                    emite(EREAD, crArgNul(), crArgNul(), crArgPos(sim.desp));
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
                                    emite(EWRITE, crArgNul(), crArgNul(), crArgPos($3.pos));
                                }
                            }
                        ;
instruccionSeleccion    : IF_ APAR_ expresion CPAR_
                            {
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
                                else{
                                    $<jmpstr>$.jmpf = creaLans(si);
                                    emite(EIGUAL, crArgPos($3.pos), crArgEnt(FALSE), crArgEnt(-1));
                                }
                            }
                        instruccion
                            {
                               $<jmpstr>5.fin = creaLans(si);
                               emite(GOTOS, crArgNul(), crArgNul(), crArgEnt(-1)); 
                               completaLans($<jmpstr>5.jmpf, crArgEtq(si));
                            }
                        ELSE_ instruccion 
                            {
                                completaLans($<jmpstr>5.fin, crArgEtq(si));
                            }
                        ;
instruccionIteracion    : WHILE_ 
                            {
                                $<jmpstr>$.ini = si;
                            }
                        APAR_ expresion CPAR_
                            {
                                if ($4.tipo == T_ERROR) {
                                    // Ninguna salida por pantalla, ya la hemos hecho donde toca
                                }
                                else if ($4.tipo != T_LOGICO) {
                                    yyerror("Error en la expresion de bucle: expresion no valida en la guarda.");
                                }
                                else{
                                    $<jmpstr>2.jmpf = creaLans(si);
                                    emite(EIGUAL, crArgPos($4.pos), crArgEnt(FALSE), crArgEnt(-1));
                                }
                            }
                        instruccion
                            {
                                emite(GOTOS, crArgNul(), crArgNul(), crArgEtq($<jmpstr>2.ini));
                                completaLans($<jmpstr>2.jmpf, crArgEtq(si));
                            }
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
                                    $$.tipo = $3.tipo;
                                    $$.pos = creaVarTemp();
                                    if($2 != EASIG){
                                        emite($2, crArgPos(sim.desp), crArgPos($3.pos),  crArgPos(sim.desp));
                                    }
                                    else {
                                        emite(EASIG, crArgPos($3.pos), crArgNul(), crArgPos(sim.desp));
                                    }
                                    emite(EASIG, crArgPos(sim.desp), crArgNul(), crArgPos($$.pos));
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
                                        $$.tipo = $6.tipo;
                                        // Nota: no multiplicamos la expresión por TALLA_TIPO_SIMPLE porque es 1
                                        // Si expresion < 0 entonces peto
                                        emite(EMEN, crArgPos($3.pos), crArgEnt(0), crArgEtq(si + 2));

                                        // No he petado aún; si expresion < arr.nelem entonces sigo
                                        emite(EMEN, crArgPos($3.pos), crArgEnt(arr.nelem), crArgEtq(si + 2));
                                        
                                        // He petado. Acabo el programa.
                                        emite(FIN, crArgNul(), crArgNul(), crArgNul());
                                        
                                        // No he petado en esta instrucción. Prosigo normalmente.
                                        $$.pos = creaVarTemp();
                                        if ($5 != EASIG) {
                                            int aux = creaVarTemp();
                                            // Cojo el valor anterior que había en esa posición del vector
                                            emite(EAV, crArgPos(sim.desp), crArgPos($3.pos), crArgPos(aux));
                                            // Hago la operación correspondiente y propago
                                            emite($5, crArgPos(aux), crArgPos($6.pos), crArgPos($$.pos));
                                            // Guardo el resultado en el índice del array
                                            emite(EVA, crArgPos(sim.desp), crArgPos($3.pos), crArgPos($$.pos));
                                        }
                                        else {
                                            // Asigno al vector el valor
                                            emite(EVA, crArgPos(sim.desp), crArgPos($3.pos), crArgPos($6.pos));
                                            // Propago
                                            emite(EASIG, crArgPos($6.pos), crArgNul(), crArgPos($$.pos));
                                        }    
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
                                        $$.tipo = $5.tipo;
                                        $$.pos = creaVarTemp();
                                        int absDesp = sim.desp + camp.desp;

                                        if($4 != EASIG){
                                            emite($4, crArgPos(absDesp), crArgPos($5.pos),  crArgPos(absDesp));
                                        }
                                        else {
                                            emite(EASIG, crArgPos($5.pos), crArgNul(), crArgPos(absDesp));
                                        }
                                        emite(EASIG, crArgPos(absDesp), crArgNul(), crArgPos($$.pos));
                                    }
                                }
                            }
                        ;
expresionLogica         : expresionIgualdad
                            {
                                $$.tipo = $1.tipo;
                                $$.pos = $1.pos;
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
                                    $$.pos = creaVarTemp();
                                    emite($2, crArgPos($1.pos), crArgPos($3.pos), crArgPos($$.pos));
                                    if ($2 == ESUM) {
                                        // OR
                                        // Si eran los dos TRUE, la suma es 2
                                        // Hay que comprobar si esto pasa para asignar TRUE
                                        emite(EMEN, crArgPos($$.pos), crArgEnt(2), crArgEtq(si + 2));
                                        emite(EASIG, crArgEnt(TRUE), crArgNul(), crArgPos($$.pos));
                                    }
                                }
                            }
                        ;
expresionIgualdad       : expresionRelacional
                            {
                                $$.tipo = $1.tipo;
                                $$.pos = $1.pos;
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
                                    $$.pos = creaVarTemp();

                                    // Ver expresionRelacional
                                    emite($2, crArgPos($1.pos), crArgPos($3.pos), crArgEtq(si + 3));
                                    emite(EASIG, crArgEnt(FALSE), crArgNul(), crArgPos($$.pos));
                                    emite(GOTOS, crArgNul(), crArgNul(), crArgEtq(si + 2));
                                    emite(EASIG, crArgEnt(TRUE), crArgNul(), crArgPos($$.pos));

                                }
                            }
                        ;
expresionRelacional     : expresionAditiva
                            {
                                $$.tipo = $1.tipo;
                                $$.pos = $1.pos;
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
                                $$.pos = $1.pos;
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
                                $$.pos = $1.pos;
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
                                    $$.pos = creaVarTemp();
                                    emite($2, crArgPos($1.pos), crArgPos($3.pos), crArgPos($$.pos));
                                }
                            }
                        ;
expresionUnaria         : expresionSufija
                            {
                                $$.tipo = $1.tipo;
                                $$.pos = $1.pos;
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
                                    else {
                                        // T_LOGICO
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
                            }
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
                                    emite($2, crArgPos(sim.desp), crArgEnt(1), crArgPos(sim.desp));
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
                                        // Nota: no multiplicamos la expresión por TALLA_TIPO_SIMPLE porque es 1
                                        // Si expresion < 0 entonces peto
                                        emite(EMEN, crArgPos($3.pos), crArgEnt(0), crArgEtq(si + 2));
                                        // No he petado aún; si expresion < arr.nelem entonces sigo
                                        emite(EMEN, crArgPos($3.pos), crArgEnt(arr.nelem), crArgEtq(si + 2));
                                        // He petado. Acabo el programa.
                                        emite(FIN, crArgNul(), crArgNul(), crArgNul());

                                        // No he petado en esta instrucción. Prosigo normalmente.
                                        $$.pos = creaVarTemp();
                                        emite(EAV, crArgPos(sim.desp), crArgPos($3.pos), crArgPos($$.pos));
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
                                        emite(EASIG, crArgPos(absDesp), crArgNul(), crArgPos($$.pos));
                                    }
                                }
                            }
                        | constante
                            {
                                $$.tipo = $1.tipo;
                                $$.pos = creaVarTemp();
                                emite(EASIG, crArgEnt($1.pos), crArgNul(), crArgPos($$.pos));
                            }
                        ;
constante               : CTE_
                            {
                                $$.tipo = T_ENTERO;
                                $$.pos = $1;
                            }
                        | TRUE_
                            {
                                $$.tipo = T_LOGICO;
                                $$.pos = TRUE;
                            }
                        | FALSE_
                            {
                                $$.tipo = T_LOGICO;
                                $$.pos = FALSE;
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
