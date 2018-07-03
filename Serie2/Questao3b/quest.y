%{

/* Inclusao de arquivos da biblioteca de C */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definicao dos atributos dos atomos operadores */

#define EQ 		1
#define WHILE	2
#define DO		3
#define MAIS	4
#define ID 		5

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

E				:	WHILE  E DO E 
				|	ID EQ E
				|	E MAIS E
				|	ID
                ;
%%

/* Inclusao do analisador lexico  */

#include "lex.yy.c"

