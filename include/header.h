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

/* Flag si se desea una traza       */
extern int verbosidad;
/* Flag para saber si se ve la TdS */
extern int verTDS;
/* Contador del numero de errores        */
extern int numErrores;

/* Desplazamiento en el segmento de variables */
extern int dvar;
/* Desplazamiento relativo en el segmento de código */
extern int si;

/*****************************************************************************/

typedef struct cteStruct {
    int tipo;
    int pos;
} CTESTRUCT;
typedef struct lcStruct{
    int talla;
    int regRef;
} LCSTRUCT;
/*****************************************************************************/
#endif  /* _HEADER_H */
/*****************************************************************************/


