/*****************************************************************************/
/**  GRUPO 12:                                                              **/                                                                            
/**  Martin Quesada Zaragoza                                                **/
/**  Nahuel Unai Rosello Beneitez                                           **/
/**  Manuel Rosello Oviedo                                                  **/                                     
/*****************************************************************************/
#ifndef _HEADER_H
#define _HEADER_H

/****************************************************** Constantes generales */
#define TRUE  1
#define FALSE 0
#define TALLA_TIPO_SIMPLE 1
/************************************* Variables externas definidas en el AL */
extern int yylex();
extern int yyparse();

extern FILE *yyin;                           /* Fichero de entrada           */
extern int   yylineno;                       /* Contador del numero de linea */
extern char *yytext;                         /* Patron detectado             */
/********* Funciones y variables externas definidas en el Programa Principal */
extern void yyerror(const char * msg) ;   /* Tratamiento de errores          */

extern int verbosidad;                   /* Flag si se desea una traza       */
extern int verTDS;                        /* Flag para saber si se ve la TdS */
extern int numErrores;              /* Contador del numero de errores        */

extern int dvar;                    /* Desplazamiento en el segmento de variables */

/*****************************************************************************/

typedef struct cteStruct {
    int tipo;
    int cte;
} CTESTRUCT;
typedef struct lcStruct{
    int talla;
    int regRef;
} LCSTRUCT;
/*****************************************************************************/
#endif  /* _HEADER_H */
/*****************************************************************************/


