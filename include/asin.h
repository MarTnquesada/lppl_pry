/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_ASIN_H_INCLUDED
# define YY_YY_ASIN_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    STRUCT_ = 258,
    INT_ = 259,
    BOOL_ = 260,
    READ_ = 261,
    PRINT_ = 262,
    WHILE_ = 263,
    FOR_ = 264,
    IF_ = 265,
    ELSE_ = 266,
    SEP_ = 267,
    SEMICOL_ = 268,
    MAS_ = 269,
    MENOS_ = 270,
    NOT_ = 271,
    POR_ = 272,
    DIV_ = 273,
    MOD_ = 274,
    MASMAS_ = 275,
    MENOSMENOS_ = 276,
    APAR_ = 277,
    CPAR_ = 278,
    ACOR_ = 279,
    CCOR_ = 280,
    ALLAV_ = 281,
    CLLAV_ = 282,
    AND_ = 283,
    OR_ = 284,
    ASIG_ = 285,
    MASASIG_ = 286,
    MENOSASIG_ = 287,
    PORASIG_ = 288,
    DIVASIG_ = 289,
    ASIGASIG_ = 290,
    NOTASIG_ = 291,
    MAYOR_ = 292,
    MENOR_ = 293,
    MAYORASIG_ = 294,
    MENORASIG_ = 295,
    ID_ = 296,
    CTE_ = 297,
    TRUE_ = 298,
    FALSE_ = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 15 "src/asin.y" /* yacc.c:1909  */

    char *id;
    int cte;
    int tipo;
    LCSTRUCT lcstr;
    CTESTRUCT ctestr;
    JMPSTRUCT jmpstr;

#line 108 "asin.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ASIN_H_INCLUDED  */
