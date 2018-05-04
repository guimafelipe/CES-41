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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    ID = 258,
    CHARCT = 259,
    INTCT = 260,
    FLOATCT = 261,
    OR = 262,
    AND = 263,
    NOT = 264,
    RELOP = 265,
    ADOP = 266,
    MULTOP = 267,
    NEG = 268,
    OPPAR = 269,
    CLPAR = 270,
    OPBRACE = 271,
    CLBRACE = 272,
    OPTRIP = 273,
    CLTRIP = 274,
    COMMA = 275,
    SCOLON = 276,
    ASSIGN = 277,
    CHAR = 278,
    FALSE = 279,
    FLOAT = 280,
    INT = 281,
    LOGIC = 282,
    STATEMENTS = 283,
    TRUE = 284,
    VAR = 285,
    INVAL = 286
  };
#endif
/* Tokens.  */
#define ID 258
#define CHARCT 259
#define INTCT 260
#define FLOATCT 261
#define OR 262
#define AND 263
#define NOT 264
#define RELOP 265
#define ADOP 266
#define MULTOP 267
#define NEG 268
#define OPPAR 269
#define CLPAR 270
#define OPBRACE 271
#define CLBRACE 272
#define OPTRIP 273
#define CLTRIP 274
#define COMMA 275
#define SCOLON 276
#define ASSIGN 277
#define CHAR 278
#define FALSE 279
#define FLOAT 280
#define INT 281
#define LOGIC 282
#define STATEMENTS 283
#define TRUE 284
#define VAR 285
#define INVAL 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 86 "tsimb.y" /* yacc.c:1909  */

	char cadeia[50];
	int atr, valint;
	float valreal;
	char carac;

#line 123 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
