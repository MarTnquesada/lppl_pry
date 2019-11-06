/*****************************************************************************/
/**  Martín Quesada Zaragoza                                                **/
/**  Nahuel Unai Roselló Beneitez                                           **/
/**  Manuel Roselló Oviedo                                                  **/
/*****************************************************************************/
%{
#include <stdio.h>
#include <string.h>
#include "header.h"
#include "asin.h"

#define  retornar(x) { if (verbosidad) ECHO; return(x);}
%}
/*-----------------------------------------------------------------------------
  Estas opciones evitan "warnings" innecesarios y permiten obtener el
  numero de linea actual en la variable global "yylineno".
-----------------------------------------------------------------------------*/
%option noinput       
%option nounput       
%option yylineno  

delimitador    [ \t]+
digito         [0-9]
sep            [.] 
minuscula      [a-z]
mayuscula      [A-Z]
letra          {minuscula}|{mayuscula}
comentario     "//".*"\n"
id             {letra}({letra}|{digito}|_)* 
entero         {digito}+
real           ({digito}+{sep}{digito}*)|({digito}*{sep}{digito}+)
cte            {entero}|{real}

%%
{delimitador}  { if(verbosidad) ECHO;  }
{comentario}   { if(verbosidad) {ECHO; printf("  %d.-", yylineno);}  }
"\n"           { if(verbosidad) {ECHO; printf("  %d.-", yylineno);}  }
"struct"       { retornar(STRUCT_);    }
"int"          { retornar(INT_);       }
"bool"         { retornar(BOOL_);      }
"read"         { retornar(READ_);      }
"print"        { retornar(PRINT_);     }
"while"        { retornar(WHILE_);     }
"for"          { retornar(FOR_);       }
"if"           { retornar(IF_);        }
"else"         { retornar(ELSE_);      }
"true"         { retornar(TRUE_);      }
"false"        { retornar(FALSE_);     }
{sep}          { retornar(SEP_);       }
";"            { retornar(SEMICOL_);   }
"+"	           { retornar(MAS_);       } 
"-"            { retornar(MENOS_);     }
"!"            { retornar(NOT_);       }
"*"            { retornar(POR_);       }  
"/"            { retornar(DIV_);       }
"%"            { retornar(MOD_);       }
"++"           { retornar(MASMAS_);    }
"--"           { retornar(MENOSMENOS_);}
"("            { retornar(APAR_);      }
")"            { retornar(CPAR_);      }
"["            { retornar(ACOR_);      }
"]"            { retornar(CCOR_);      }
"{"            { retornar(ALLAV_);     } 
"}"            { retornar(CLLAV_);     }
"="            { retornar(ASIG_);      }
"+="           { retornar(MASASIG_);   }
"-="           { retornar(MENOSASIG_); } 
"*="           { retornar(PORASIG_);   }
"/="           { retornar(DIVASIG_);   }
"=="           { retornar(ASIGASIG_);  }
"!="           { retornar(NOTASIG_);   }
"&&"           { retornar(AND_);       }
"||"           { retornar(OR_);        }
">"            { retornar(MAYOR_);     }
"<"            { retornar(MENOR_);     }
">="           { retornar(MAYORASIG_); }
"<="           { retornar(MENORASIG_); }
{cte}          { yylval.cte = atoi(yytext); retornar(CTE_);       }
{id}           { yylval.id = yytext; retornar(ID_);        }
.	             { yyerror("Caracter desconocido"); }
%%
/*****************************************************************************/
