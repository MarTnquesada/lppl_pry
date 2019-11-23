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

%%

programa                : ALLAV_ { dvar = 0; } secuenciaSentencias CLLAV_ { if (verTDS) { verTdS(); } }
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
                                else {
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
                            }
                        | PRINT_ APAR_ expresion CPAR_ SEMICOL_
                            {
                                if ($3.tipo == T_ERROR) {
                                    // Ninguna salida por pantalla, ya la hemos hecho donde toca
                                }
                                else if ($3.tipo != T_ENTERO) {
                                    yyerror("Error en la instruccion de escritura: la variable no es de tipo entero.");
                                }
                            }
                        ;
instruccionSeleccion    : IF_ APAR_ expresion CPAR_
                            {
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
                                /* $$.cte = $1.cte; */
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
                                }
                            }
                        ;
expresionSufija         : APAR_ expresion CPAR_
                            {
                                $$.tipo = $2.tipo;
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
                                    }
                                }
                            }
                        | constante
                            {
                                $$.tipo = $1.tipo;
                            }
                        ;
constante               : CTE_ {$$.tipo = T_ENTERO; $$.cte = $1;}
                        | TRUE_ {$$.tipo = T_LOGICO; $$.cte = TRUE;}
                        | FALSE_ {$$.tipo = T_LOGICO; $$.cte = FALSE;}
                        ;
operadorAsignacion      : ASIG_
                        | MASASIG_
                        | MENOSASIG_
                        | PORASIG_
                        | DIVASIG_
                        ;
operadorLogico          : AND_
                        | OR_
                        ;
operadorIgualdad        : ASIGASIG_
                        | NOTASIG_
                        ;
operadorRelacional      : MAYOR_
                        | MENOR_
                        | MAYORASIG_
                        | MENORASIG_
                        ;
operadorAditivo         : MAS_
                        | MENOS_
                        ;
operadorMultiplicativo  : POR_
                        | DIV_
                        | MOD_
                        ;
operadorUnario          : MAS_
                            {
                                $$.tipo = T_ENTERO;
                            }
                        | MENOS_
                            {
                                $$.tipo = T_ENTERO;
                            }
                        | NOT_
                            {
                                $$.tipo = T_LOGICO;
                            }
                        ;
operadorIncremento      : MASMAS_
                        | MENOSMENOS_
                        ;
%%
/*****************************************************************************/
