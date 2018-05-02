%{

/* Inclusao de arquivos da biblioteca de C */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definicao dos atributos dos atomos operadores */

#define 	LT 		    1
#define 	LE 	    	2
#define		GT			3
#define		GE			4
#define		EQ			5
#define		NE			6
#define		MAIS        7
#define		MENOS       8
#define		MULT    	9
#define		DIV   	    10
#define		RESTO   	11

/*   Definicao dos tipos de identificadores   */

#define 	IDPROG		1
#define 	IDVAR		2

/*  Definicao dos tipos de variaveis   */

#define 	NAOVAR		0
#define 	INTEIRO		1
#define 	LOGICO		2
#define 	REAL		3
#define 	CARACTERE	4

/*   Definicao de outras constantes   */

#define	NCLASSHASH	23
#define	VERDADE		1
#define	FALSO		0

/*  Strings para nomes dos tipos de identificadores  */

char *nometipid[3] = {" ", "IDPROG", "IDVAR"};

/*  Strings para nomes dos tipos de variaveis  */

char *nometipvar[5] = {"NAOVAR",
	"INTEIRO", "LOGICO", "REAL", "CARACTERE"
};

/*    Declaracoes para a tabela de simbolos     */

typedef struct celsimb celsimb;
typedef celsimb *simbolo;
struct celsimb {
	char *cadeia;
	int tid, tvar;
	char inic, ref;
	simbolo prox;
};

/*  Variaveis globais para a tabela de simbolos e analise semantica */

simbolo tabsimb[NCLASSHASH];
simbolo simb;

/*
	Prototipos das funcoes para a tabela de simbolos
    	e analise semantica
 */

void InicTabSimb (void);
void ImprimeTabSimb (void);
simbolo InsereSimb (char *, int, int);
int hash (char *);
simbolo ProcuraSimb (char *);
void DeclaracaoRepetida (char *);
void TipoInadequado (char *);
void NaoDeclarado (char *);

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
%token		<string>	    CHARCT
%token		<valor>			INTCT
%token		<valfloat>	    FLOATCT
%token		<string>		STRING
%token		OR
%token		AND
%token		NOT
%token		<string>		RELOP
%token		<string>		ADOP
%token		<string>		MULTOP
%token		NEG
%token		OPPAR
%token		CLPAR
%token		OPBRACE
%token		CLBRACE
%token 		OPBRAK
%token		CLBRAK
%token		OPTRIP
%token		CLTRIP
%token		COMMA
%token		SCOLON
%token		COLON
%token		ASSIGN
%token		CHAR
%token		FALSE
%token		FLOAT
%token		INT
%token		LOGIC
%token		STATEMENTS
%token		TRUE
%token		VAR
%token		CALL
%token		DO
%token		IF
%token		ELSE
%token		MAIN
%token		READ
%token		REPEAT
%token		RETURN
%token		THEN
%token		VOID
%token		WHILE
%token		WRITE
%token		FOR
%token		<carac>         INVAL
%%
/* Producoes da gramatica:

	Os terminais sao escritos e, depois de alguns,
	para alguma estetica, ha mudanca de linha       */

Prog			:	ID  OPTRIP  {printf ("%s {{{\n", $1);}
                    Decls  ModList MainMod CLTRIP  {printf ("}}}\n");}
                ;
Decls 		    :
                |   VAR  OPBRACE  {printf ("var {\n");}  DeclList
                    CLBRACE  {printf ("}\n");}
                ;
DeclList		:	Declaration  |  DeclList  Declaration
                ;
Declaration 	:	Type  ElemList  SCOLON  {printf (";\n");}
                ;
Type			: 	INT  {printf ("int ");}
                |   FLOAT  {printf ("float ");}
                |   CHAR  {printf ("char ");}
                |   LOGIC  {printf ("logic ");}
				| 	VOID {printf("void ");}
                ;
ElemList    	:	Elem  |  ElemList  COMMA  {printf (", ");}  Elem
                ;
Elem        	:	ID  {printf ("%s ", $1);} Dims
                ;
Dims			:
				|	OPBRAK {printf("[");} DimList CLBRAK {printf("]");}
				;
DimList			:	INTCT  {printf ("%d", $1);} 
				|	INTCT COMMA INTCT {printf("%d, %d", $1, $3);} 
				|	INTCT COMMA INTCT COMMA INTCT {printf("%d, %d, %d", $1, $3, $5);}
				;
ModList			:
				|	ModList Module
				;
Module			:	ModHeader ModBody
				;
ModHeader		:	Type ID OPPAR {printf("(");} CLPAR {printf(")");}
				|	Type ID OPPAR {printf("(");} ParamList CLPAR {printf(")");}
				;
ParamList		:	Parameter
				|	ParamList COMMA {printf(", ");} Parameter
				;
Parameter		:	Type ID
				;
ModBody			:	Decls Stats
				;
MainMod			:	MAIN ModBody
				;
Stats       	:   STATEMENTS  {printf ("statements ");}  CompStat
                ;
CompStat		:   OPBRACE  {printf ("{\n");}  StatList  CLBRACE
                    {printf ("}\n");}
                ;
StatList		:
                |   StatList  Statement
                ;
Statement   	:   CompStat  |  IfStat | WhileStat | RepeatStat | ForStat | ReadStat | WriteStat | AssignStat | CallStat | ReturnStat | SCOLON {printf(";");}
                ;
IfStat			:	IF {printf("if ");} Expression THEN {printf("then ");} Statement ElseStat
				;
ElseStat		:
				|	ELSE {printf("else ");} Statement
				;
WhileStat		:	WHILE {printf("while ");} Expression DO {printf("do ");} Statement
				;
RepeatStat		: 	REPEAT {printf("repeat ");} Statement WHILE {printf("while ");} Expression SCOLON {printf(";\n");} 
				;
ForStat			:	FOR {printf("for ");} Variable OPPAR {printf("(");} AuxExpr4 COLON {printf(":");} Expression COLON {printf(":");} AuxExpr4 CLPAR {printf(")");} Statement
				;
ReadStat		:	READ OPPAR {printf("read(");} ReadList CLPAR SCOLON {printf(");\n");}
				;
ReadList		:	Variable
				|	ReadList COMMA {printf(", ");} Variable
				;
WriteStat		:	WRITE OPPAR {printf("write(");} WriteList CLPAR SCOLON {printf(");\n");}
				;
WriteList		:	WriteElem
				|	WriteList COMMA {printf(", ");} WriteElem
				;
WriteElem		: 	STRING {printf("%s", $1);}
				|	Expression
				;
CallStat		:	CALL ID OPPAR {printf("call %s(", $2);} Arguments CLPAR SCOLON {printf(");\n");}
				;
Arguments		:
				|	ExprList
				;
ReturnStat		:	RETURN SCOLON {printf("return;\n");}
				|	RETURN {printf("return ");} Expression SCOLON {printf(";\n");}
				;
AssignStat  	:   Variable  ASSIGN  {printf (":= ");}  Expression  SCOLON
                    {printf (";\n");}
                ;
ExprList		:	Expression
				|	ExprList COMMA {printf(", ");} Expression
				;
Expression  	:   AuxExpr1  |  Expression  OR  {printf ("|| ");}  AuxExpr1
                ;
AuxExpr1    	:   AuxExpr2  |  AuxExpr1  AND  {printf ("&& ");}  AuxExpr2
                ;
AuxExpr2    	:   AuxExpr3  |  NOT  {printf ("! ");}  AuxExpr3
                ;
AuxExpr3    	:   AuxExpr4
                |   AuxExpr4  RELOP  {
                        /*switch ($2) {
                            case LT: printf ("< "); break;
                            case LE: printf ("<= "); break;
                            case EQ: printf ("= "); break;
                            case NE: printf ("!= "); break;
                            case GT: printf ("> "); break;
                            case GE: printf (">= "); break;
                        }*/
						printf("%s ", $2);
                    }  AuxExpr4
                ;
AuxExpr4    	:   Term
                |   AuxExpr4  ADOP  {
                        /*switch ($2) {
                            case MAIS: printf ("+ "); break;
                            case MENOS: printf ("- "); break;
                        }*/
						printf("%s ", $2);
                    }  Term
                ;
Term  	    	:   Factor
                |   Term  MULTOP  {
                        /*switch ($2) {
                            case MULT: printf ("* "); break;
                            case DIV: printf ("/ "); break;
                            case RESTO: printf ("%% "); break;
                        }*/
						printf("%s ", $2);
                    }  Factor
                ;
Factor		    :   Variable
                |   INTCT  {printf ("%d ", $1);}
                |   FLOATCT  {printf ("%g ", $1);}
                |   CHARCT  {printf ("%s ", $1);}
            	|   TRUE  {printf ("true ");}
            	|   FALSE  {printf ("false ");}
            	|   NEG  {printf ("~ ");}  Factor
            	|   OPPAR  {printf ("( ");}  Expression  CLPAR  {printf (") ");}
				| 	FuncCall
                ;
Variable		:   ID  {printf ("%s ", $1);} Subscripts
                ;
Subscripts		:
				|	OPBRAK {printf("[");} SubscrList CLBRAK	{printf("]");}
				;
SubscrList		:	AuxExpr4
				|	TwoSubscr
				|	ThreeSubscr
				;
TwoSubscr		:	AuxExpr4 COMMA {printf(", ");} AuxExpr4
				;
ThreeSubscr		:	TwoSubscr COMMA {printf(", ");} AuxExpr4
				;
FuncCall		:	ID OPPAR {printf("%s(",$1);} Arguments CLPAR {printf(")");}
				;
%%

/* Inclusao do analisador lexico  */

#include "lex.yy.c"

/*  InicTabSimb: Inicializa a tabela de simbolos   */

void InicTabSimb () {
	int i;
	for (i = 0; i < NCLASSHASH; i++)
		tabsimb[i] = NULL;
}

/*
	ProcuraSimb (cadeia): Procura cadeia na tabela de simbolos;
	Caso ela ali esteja, retorna um ponteiro para sua celula;
	Caso contrario, retorna NULL.
 */

simbolo ProcuraSimb (char *cadeia) {
	simbolo s; int i;
	i = hash (cadeia);
	for (s = tabsimb[i]; (s!=NULL) && strcmp(cadeia, s->cadeia);
		s = s->prox);
	return s;
}

/*
	InsereSimb (cadeia, tid, tvar): Insere cadeia na tabela de
	simbolos, com tid como tipo de identificador e com tvar como
	tipo de variavel; Retorna um ponteiro para a celula inserida
 */

simbolo InsereSimb (char *cadeia, int tid, int tvar) {
	int i; simbolo aux, s;
	i = hash (cadeia); aux = tabsimb[i];
	s = tabsimb[i] = (simbolo) malloc (sizeof (celsimb));
	s->cadeia = (char*) malloc ((strlen(cadeia)+1) * sizeof(char));
	strcpy (s->cadeia, cadeia);
	s->tid = tid;		s->tvar = tvar;
	s->inic = FALSO;	s->ref = FALSO;
	s->prox = aux;	return s;
}

/*
	hash (cadeia): funcao que determina e retorna a classe
	de cadeia na tabela de simbolos implementada por hashing
 */

int hash (char *cadeia) {
	int i, h;
	for (h = i = 0; cadeia[i]; i++) {h += cadeia[i];}
	h = h % NCLASSHASH;
	return h;
}

/* ImprimeTabSimb: Imprime todo o conteudo da tabela de simbolos  */

void ImprimeTabSimb () {
	int i; simbolo s;
	printf ("\n\n   TABELA  DE  SIMBOLOS:\n\n");
	for (i = 0; i < NCLASSHASH; i++)
		if (tabsimb[i]) {
			printf ("Classe %d:\n", i);
			for (s = tabsimb[i]; s!=NULL; s = s->prox){
				printf ("  (%s, %s", s->cadeia,  nometipid[s->tid]);
				if (s->tid == IDVAR)
					printf (", %s, %d, %d",
						nometipvar[s->tvar], s->inic, s->ref);
				printf(")\n");
			}
		}
}

/*  Mensagens de erros semanticos  */

void DeclaracaoRepetida (char *s) {
	printf ("\n\n***** Declaracao Repetida: %s *****\n\n", s);
}

void NaoDeclarado (char *s) {
    printf ("\n\n***** Identificador Nao Declarado: %s *****\n\n", s);
}

void TipoInadequado (char *s) {
    printf ("\n\n***** Identificador de Tipo Inadequado: %s *****\n\n", s);
}

