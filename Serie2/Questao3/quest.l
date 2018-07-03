%{
char tratachar (char *);
%}
delim		[ \t\n\r]
ws			{delim}+
digito		[0-9]
l_maiuscula	[A-Z]
l_minuscula	[a-z]
letra		{l_maiuscula}|{l_minuscula}
intct		{digito}+
carac1		\\.|[^\\']
charct	 	'{carac1}'
floatct		{digito}+\.{digito}*(([Ee][+-]?{digito}+))?
carac2		\\.|[^\\\"]
string		\"{carac2}*\"
id			{letra}({letra}|{digito})*

%%
{ws}		{ ;}

do			{return DO;}
while		{return WHILE;}

"="			{strcpy(yylval.string, yytext); return EQ;}
"+"			{strcpy(yylval.string, yytext); return MAIS;}	

{id}		{strcpy (yylval.string, yytext); return ID;}

.			{yylval.carac = yytext[0]; return INVAL;}	
%%

/*
	tratachar: retorna o codigo ASCII de uma constante do tipo char,
   eliminando os apostrofos e as barras invertidas
 */

char tratachar (char *s) {
	if (s[1] != '\\') return s[1];
	else switch (s[2]) {
		case 'a': 	return 7;		case '\\': 	return 92;
		case 'b': 	return 8;		case 'r': 	return 13;
		case '\"': 	return 34;		case 'f': 	return 12;
		case 't': 	return 9;		case 'n': 	return 10;
		case '0': 	return 0;		case '\'': 	return 39;
		case 'v': 	return 11;
		default:		return s[2];
	}
}

