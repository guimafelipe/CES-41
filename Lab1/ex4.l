%{
#include <string.h>
#define	ID			1
#define	CTINT		2
#define CTHEX		3
#define CTREAL		4
#define	OPREL		5
#define MENOR 		1
#define MENIG		2
#define	MAIOR		3
#define	MAIG		4
#define	IGUAL		5
#define	DIFER		6
#define OPAD		6
#define MAIS		1
#define MENOS		2
#define OPMULT		7
#define VEZES		1
#define DIV			2
#define ABPAR		8
#define FPAR		9
#define INVAL		10

union {
	char string[50];
	int atr, valor;
	float valfloat;
	char carac;
} yylval;

%}

delim		[ \t\n\r]
ws			{delim}+
digito		[0-9]
ctint		{digito}+
cthex		0x{digito}+
ctreal		{digito}+\.{digito}*
l_maiuscula	[A-Z]
l_minuscula	[a-z]
id			{l_maiuscula}(({l_minuscula}|{digito}|(_{l_maiuscula}))*({l_minuscula}|{digito})+)?

%%
{ws}		{ ;}
{id}		{strcpy (yylval.string, yytext); return ID;}
{ctint}		{yylval.valor = atoi(yytext); return CTINT;}
{cthex}		{yylval.valor = strtol(yytext, NULL, 16); return CTHEX;}
{ctreal}	{yylval.valfloat = strtof(yytext, NULL); return CTREAL;}
"<"			{strcpy(yylval.string, "MENOR"); return OPREL;}
"<="		{strcpy(yylval.string, "MENIG"); return OPREL;}
">"			{strcpy(yylval.string, "MAIOR"); return OPREL;}
">="		{strcpy(yylval.string, "MAIG"); return OPREL;}
"=="		{strcpy(yylval.string, "IGUAL"); return OPREL;}
"!="		{strcpy(yylval.string, "DIF"); return OPREL;}
"+"			{strcpy(yylval.string, "MAIS"); return OPAD;}
"-"			{strcpy(yylval.string, "MENOS"); return OPAD;}
"*"			{strcpy(yylval.string, "VEZES"); return OPMULT;}
"/"			{strcpy(yylval.string, "DIV"); return OPMULT;}
"("			{return ABPAR;}
")"			{return FPAR;}
.			{yylval.carac = yytext[0]; return INVAL;}
%%

main () {
	int i;
	printf ("\n   texto  |   tipo   | atributo \n");
	printf ("--------------------------------\n");
	while (i = yylex ()) {
		printf ("%10s|", yytext);
		switch (i) {
			case ID:
				printf ("%10s|%10s|", "ID", yylval.string); break;
			case CTINT:
				printf ("%10s|%10d|", "CTINT", yylval.valor); break;
			case CTHEX:
				printf ("%10s|%10d|", "CTHEX", yylval.valor); break;
			case CTREAL:
				printf ("%10s|%10f|", "CTREAL", yylval.valfloat); break;
			case OPREL:
				printf ("%10s|%10s|", "OPREL", yylval.string); break;
			case OPAD:
				printf ("%10s|%10s|", "OPAD", yylval.string); break;
			case OPMULT:
				printf ("%10s|%10s|", "OPMULT", yylval.string); break;
			case ABPAR:
				printf ("%10s|", "ABPAR"); break;
			case FPAR:
				printf ("%10s|", "FPAR"); break;
			case INVAL:
				printf ("%10s|%10c|", "INVAL", yylval.carac); break;
		}
		printf ("\n");
	}
}
