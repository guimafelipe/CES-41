%{

/* Inclusao de arquivos da biblioteca de C */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definicao dos atributos dos atomos operadores */


%}

/* Definicao do tipo de yylval e dos atributos dos nao terminais */

%union {
	char string[50];
	int atr, valor;
	float valfloat;
	char carac;
}

/* Declaracao dos atributos dos tokens e dos nao-terminais */

%token		<string>		ID
%token		DO
%token		WHILE
%token		EQ
%token		MAIS
%token		<carac>         INVAL
%%
/* Producoes da gramatica:

	Os terminais sao escritos e, depois de alguns,
	para alguma estetica, ha mudanca de linha       */

E		:	WHILE {printf("while ");}  E DO {printf("do ");} E 
		|	Exp
		;

Exp		:	ID EQ {printf("%s = ", $1);} Term
		|	Term
		;

Term	:	Term MAIS ID {printf("+ %s ", $3);}
		|	ID {printf("%s ", $1);}
		;
%%

/* Inclusao do analisador lexico  */

#include "lex.yy.c"

