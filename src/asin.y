/*****************************************************************************/
/**  Martín Quesada Zaragoza                                                **/
/**  Nahuel Unai Roselló Beneitez                                           **/
/**  Manuel Roselló Oviedo                                                  **/
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
%token APAR_ CPAR_ ACOR_ CCOR_ ALLAV_ CLLAV_ ASIG_ MASASIG_ MENOSASIG_ PORASIG_ DIVASIG_ ASIGASIG_ NOTASIG_ AND_ OR_ MAYOR_ MENOR_ MAYORASIG_ MENORASIG_
%token <id> ID_
%token <cte> CTE_

%type <ctestr> constante
%type <ctestr> expresion expresionAditiva expresionIgualdad expresionLogica expresionMultipicativa expresionRelacional expresionSufija expresionUnaria
%type <tipo> tipoSimple
%type <lcstr> listaCampos

%%

programa                : ALLAV_ { dvar = 0; } secuenciaSentencias CLLAV_ { verTdS(); }
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
                                    yyerror("Objeto ya declarado");
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
                                    yyerror("Objeto ya declarado.");
                                }
                                else if ($1 != $4.tipo) {
                                    yyerror("Error de incompatibilidad de tipos.");
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
                                    yyerror("Objeto ya declarado.");
                                }
                                else if ($4 <= 0) {
                                    yyerror("Definición incorrecta del límite del vector (índice no válido).");
                                }
                                else {
                                    int arrayRef = insTdA($1, $4);
                                    insTdS($2, T_ARRAY, dvar, arrayRef);
                                    dvar += TALLA_TIPO_SIMPLE * $4; // + TALLA_TIPO_SIMPLE(???)
                                }
                            }
                        | STRUCT_ ALLAV_ listaCampos CLLAV_ ID_ SEMICOL_
                            {
                                SIMB sim = obtTdS($5);
                                if (sim.tipo != T_ERROR) {
                                    yyerror("Objeto ya declarado.");
                                }
                                else {
                                    insTdS($5, T_RECORD, dvar, $3.regRef);
                                    dvar += $3.talla; /* +TALLA_TIPO_SIMPLE??? */
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
                                    /* cambiar a que mole más */
                                    /* char bla[] = "lkasjfkladsjfkl" */
                                    yyerror("Campo $3 duplicado");
                                }
                                /* No se tiene que comprobar si ya existe en la tabla
                                de símbolos porque es un campo del registro y no una
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
                        | PRINT_ APAR_ expresion CPAR_ SEMICOL_
                        ;
instruccionSeleccion    : IF_ APAR_ expresion CPAR_ instruccion ELSE_ instruccion
                            {
                                if ($3.tipo != T_LOGICO) {
                                    yyerror("Expresión no válida en la guarda de la condición.");
                                }
                            }
                        ;
instruccionIteracion    : WHILE_ APAR_ expresion CPAR_ instruccion
                            {
                                if ($3.tipo != T_LOGICO) {
                                    yyerror("Expresión no válida en la guarda de la condición.");
                                }
                            }
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
                                    /* Cambiar string o algo */
                                    yyerror("$1 no existente.");
                                }
                                else if ($3.tipo == T_ERROR) {
                                    // Ninguna salida por pantalla, ya la hemos hecho
                                }
                                else if (sim.tipo != $3.tipo) {
                                    yyerror("Error de incompatibilidad de tipos.");
                                }
                                else {
                                    $$.tipo = T_VACIO;
                                }
                            }
                        | ID_ ACOR_ expresion CCOR_ operadorAsignacion expresion
                            {
                                // No se puede poner array[-0], peta
                                $$.tipo = T_ERROR;
                                SIMB sim = obtTdS($1);
                                if (sim.tipo == T_ERROR) {
                                    /* Cambiar string o algo */
                                    yyerror("$1 no existente.");
                                }
                                else if (sim.tipo != T_ARRAY) {
                                    yyerror("$1 no es un array.");
                                }
                                else {
                                    DIM arr = obtTdA(sim.ref);
                                    if (arr.telem == T_ERROR) {
                                        yyerror("$1 no es un array válido.");
                                    }
                                    else if ($3.tipo != T_ENTERO) {
                                        yyerror("El índice del vector no es de tipo entero.");
                                    }
                                    else if ($3.cte < 0 || $3.cte >= arr.nelem) {
                                        yyerror("Índice fuera de rango.");
                                    }
                                    else if ($6.tipo == T_ERROR) {
                                        // Ninguna salida por pantalla, ya la hemos hecho donde toca
                                    }
                                    else if (arr.telem != $6.tipo) {
                                        yyerror("Error de incompatibilidad de tipos.");
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
                                    yyerror("$1 no existente.");
                                }
                                else if (sim.tipo != T_RECORD) {
                                    yyerror("$1 no es un registro.");
                                }
                                else {
                                    CAMP camp = obtTdR(sim.ref, $3);
                                    if (camp.tipo == T_ERROR) {
                                        yyerror("$3 no es un campo de $1.");
                                    }
                                    else if ($5.tipo == T_ERROR) {
                                        // Ninguna salida por pantalla, ya la hemos hecho donde toca
                                    }
                                    else if (camp.tipo != $5.tipo) {
                                        yyerror("Error de incompatibilidad de tipos.");
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
                                if ($1.tipo != T_ERROR || $3.tipo != T_ERROR) {
                                    // Ninguna salida por pantalla, ya la hemos hecho donde toca
                                }
                                else if ($1.tipo != T_LOGICO || $3.tipo != T_LOGICO) {
                                    yyerror("Error en el tipo del operador.");
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
                                if ($1.tipo != T_ERROR || $3.tipo != T_ERROR) {
                                    // Ninguna salida por pantalla, ya la hemos hecho donde toca
                                }
                                else if ($1.tipo != $3.tipo) {
                                    yyerror("Error en el tipo del operador.");
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
                                if ($1.tipo != T_ERROR || $3.tipo != T_ERROR) {
                                    // Ninguna salida por pantalla, ya la hemos hecho donde toca
                                }
                                else if ($1.tipo != T_ENTERO || $3.tipo != T_ENTERO) {
                                    yyerror("Error en el tipo del operador.");
                                }
                                else {
                                    $$.tipo = T_LOGICO;
                                }
                            }
                        ;
expresionAditiva        : expresionMultipicativa
                            {
                                $$.tipo = $1.tipo;
                            }
                        | expresionAditiva operadorAditivo expresionMultipicativa
                            {
                                if ($1.tipo != T_ERROR || $3.tipo != T_ERROR) {
                                    // Ninguna salida por pantalla, ya la hemos hecho donde toca
                                }
                                else if ($1.tipo != T_ENTERO || $3.tipo != T_ENTERO) {
                                    yyerror("Error en el tipo del operador.");
                                }
                                else {
                                    $$.tipo = T_ENTERO;
                                }
                            }
                        ;
expresionMultipicativa  : expresionUnaria 
                            {
                                $$.tipo = $1.tipo;
                            }
                        | expresionMultipicativa operadorMultiplicativo expresionUnaria
                            {
                                if ($1.tipo != T_ERROR || $3.tipo != T_ERROR) {
                                    // Ninguna salida por pantalla, ya la hemos hecho donde toca
                                }
                                else if ($1.tipo != T_ENTERO || $3.tipo != T_ENTERO) {
                                    yyerror("Error en el tipo del operador.");
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
                                $$.tipo = $2.tipo;
                            }
                        | operadorIncremento ID_
                            {
                                $$.tipo = T_ERROR;
                                SIMB sim = obtTdS($2);
                                if (sim.tipo == T_ERROR) {
                                    yyerror("$2 no existente.");
                                }
                                else if (sim.tipo != T_ENTERO) {
                                    yyerror("Operación inválida para este tipo.");
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
                                    yyerror("$1 no existente.");
                                }
                                else if (sim.tipo != T_ENTERO) {
                                    yyerror("Operación inválida para este tipo.");
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
                                    yyerror("$1 no existente.");
                                }
                                else if (sim.tipo != T_ARRAY) {
                                    yyerror("$1 no es un array.");
                                }
                                else {
                                    DIM arr = obtTdA(sim.ref);
                                    if (arr.telem == T_ERROR) {
                                        yyerror("$1 no es un array válido.");
                                    }
                                    else if ($3.tipo != T_ENTERO) {
                                        yyerror("El índice del vector no es de tipo entero.");
                                    }
                                    else if ($3.cte < 0 || $3.cte >= arr.nelem) {
                                        yyerror("Índice fuera de rango.");
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
                                    yyerror("$1 no existente.");
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
                                    yyerror("$1 no existente.");
                                }
                                else if (sim.tipo != T_RECORD) {
                                    yyerror("$1 no es un registro.");
                                }
                                else {
                                    CAMP camp = obtTdR(sim.ref, $3);
                                    if (camp.tipo == T_ERROR) {
                                        yyerror("$3 no es un campo de $1.");
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
                        | MENOS_
                        | NOT_
                        ;
operadorIncremento      : MASMAS_
                        | MENOSMENOS_
                        ;
%%
/*****************************************************************************/
