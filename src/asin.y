/*****************************************************************************/
/**  Martín Quesada Zaragoza                                                **/
/**  Nahuel Unai Roselló Beneitez                                           **/
/**  Manuel Roselló Oviedo                                                  **/
/*****************************************************************************/
%{
#include <stdio.h>
#include <string.h>
#include "header.h"
%}

%union {
    char *id;
    int cte;
}

%token STRUCT_ INT_ BOOL_ READ_ PRINT_ WHILE_ FOR_ IF_ ELSE_ TRUE_ FALSE_
%token SEP_ SEMICOL_ MAS_ MENOS_ NOT_ POR_ DIV_ MOD_ MASMAS_ MENOSMENOS_ 
%token APAR_ CPAR_ ACOR_ CCOR_ ALLAV_ CLLAV_ ASIG_ MASASIG_ MENOSASIG_ PORASIG_ DIVASIG_ ASIGASIG_ NOTASIG_ AND_ OR_ MAYOR_ MENOR_ MAYORASIG_ MENORASIG_
%token <id> ID_
%token <cte> CTE_

%type <cte> expresion

%%

programa                : ALLAV_ secuenciaSentencias CLLAV_
                        ;
secuenciaSentencias     : sentencia
                        | secuenciaSentencias sentencia
                        ;
sentencia               : declaracion
                        | instruccion
                        ;
declaracion             : tipoSimple ID_ SEMICOL_
                            { 
                                $$.tipo = $1.tipo;
                                
                            }
                        | tipoSimple ID_ ASIG_ constante SEMICOL_
                        | tipoSimple ID_ ACOR_ CTE_ CCOR_ SEMICOL_
                        | STRUCT_ ALLAV_ listaCampos CLLAV_ ID_ SEMICOL_
                        ;
tipoSimple              : INT_
                            {
                                $$.tipo = T_ENTERO;
                            }
                        | BOOL_
                            {
                                $$.tipo = T_LOGICO;
                            }
                        ;
listaCampos             : tipoSimple ID_ SEMICOL_
                        | listaCampos tipoSimple ID_ SEMICOL_
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
                        ;
instruccionIteracion    : WHILE_ APAR_ expresion CPAR_ instruccion
                        ;
instruccionExpresion    : expresion SEMICOL_
                        | SEMICOL_
                        ;
expresion               : expresionLogica
                        | ID_ operadorAsignacion expresion
                        | ID_ ACOR_ expresion CCOR_ operadorAsignacion expresion
                        | ID_ SEP_ ID_ operadorAsignacion expresion
                        ;
expresionLogica         : expresionIgualdad
                        | expresionLogica operadorLogico expresionIgualdad
                        ;
expresionIgualdad       : expresionRelacional
                        | expresionIgualdad operadorIgualdad expresionRelacional
                        ;
expresionRelacional     : expresionAditiva
                        | expresionRelacional operadorRelacional expresionAditiva
                        ;
expresionAditiva        : expresionMultipicativa
                        | expresionAditiva operadorAditivo expresionMultipicativa
                        ;
expresionMultipicativa  : expresionUnaria 
                        | expresionMultipicativa operadorMultiplicativo expresionUnaria
                        ;
expresionUnaria         : expresionSufija
                        | operadorUnario expresionUnaria
                        | operadorIncremento ID_
                        ;
expresionSufija         : APAR_ expresion CPAR_
                        | ID_ operadorIncremento
                        | ID_ ACOR_ expresion CCOR_
                        | ID_
                        | ID_ SEP_ ID_
                        | constante
                        ;
constante               : CTE_
                        | TRUE_
                        | FALSE_
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
