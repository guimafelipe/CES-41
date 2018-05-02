%{
void comentario (void);
char tratachar (char *);
%}
delim		[ \t\n\r]
ws			{delim}+
digito		[0-9]
l_maiuscula	[A-Z]
l_minuscula	[a-z]
letra		{l_maiuscula}|{l_minuscula}
intct		{digito}+
carac1		\\.|[\\^']
charct	 	'{carac1}'
floatct		{digito}+\.{digito}*(([Ee][+-]?{digito}+))?
carac2		\\.|[^\\\"]
string		\"{carac2}*\"
id			{letra}({letra}|{digito})*

%%
{ws}		{ ;}

call		{return CALL;}
char		{return CHAR;}
do			{return DO;}
else		{return ELSE;}
false		{return FALSE;}
float		{return FLOAT;}
for			{return FOR;}
if			{return IF;}
int			{return INT;}
logic		{return LOGIC;}
main		{return MAIN;}
read		{return READ;}
repeat		{return REPEAT;}
return 		{return RETURN;}
statements	{return STATEMENTS;}
then		{return THEN;}
true		{return TRUE;}
var			{return VAR;}
void		{return VOID;}
while		{return WHILE;}
write		{return WRITE;}

"/*"		{comentario();}

"||"		{strcpy(yylval.string, yytext); return OR;}
"&&"		{strcpy(yylval.string, yytext); return AND;}
"!"			{strcpy(yylval.string, yytext); return NOT;}
"<"			{strcpy(yylval.string, yytext); return RELOP;}
"<="		{strcpy(yylval.string, yytext); return RELOP;}
">"			{strcpy(yylval.string, yytext); return RELOP;}
">="		{strcpy(yylval.string, yytext); return RELOP;}
"="			{strcpy(yylval.string, yytext); return RELOP;}
"!="		{strcpy(yylval.string, yytext); return RELOP;}
"+"			{strcpy(yylval.string, yytext); return ADOP;}	
"-"			{strcpy(yylval.string, yytext); return ADOP;}
"*"			{strcpy(yylval.string, yytext); return MULTOP;}
"/"			{strcpy(yylval.string, yytext); return MULTOP;}
"%"			{strcpy(yylval.string, yytext); return MULTOP;}
"~"			{strcpy(yylval.string, yytext); return NEG;}
"{{{"		{strcpy(yylval.string, yytext); return OPTRIP;}
"}}}"		{strcpy(yylval.string, yytext); return CLTRIP;}
"("			{strcpy(yylval.string, yytext); return OPPAR;}
")"			{strcpy(yylval.string, yytext); return CLPAR;}
"["			{strcpy(yylval.string, yytext); return OPBRAK;}
"]"			{strcpy(yylval.string, yytext); return CLBRAK;}
"{"			{strcpy(yylval.string, yytext); return OPBRACE;}
"}"			{strcpy(yylval.string, yytext); return CLBRACE;}
";"			{strcpy(yylval.string, yytext); return SCOLON;}
","			{strcpy(yylval.string, yytext); return COMMA;}
":"			{strcpy(yylval.string, yytext); return COLON;}
":="		{strcpy(yylval.string, yytext); return ASSIGN;}

{charct}	{strcpy (yylval.string, yytext); return CHARCT;}
{id}		{strcpy (yylval.string, yytext); return ID;}
{string}	{strcpy (yylval.string, yytext); return STRING;}
{intct}		{yylval.valor = atoi(yytext); return INTCT;}
{floatct}	{yylval.valfloat = strtof(yytext, NULL); return FLOATCT;}

.			{yylval.carac = yytext[0]; return INVAL;}	
%%

/*
	comentario: le e descarta os comentarios do programa
 */

void comentario () {
	char c;  int estado;
	estado = 1;
	while (estado != 3) {
		switch (estado) {
			case 1:
				c = input ();
				if (c == EOF) estado = 3;
				else if (c == '*') estado = 2;
				break;
			case 2:
				c = input ();
				if (c == EOF || c == '/') estado = 3;
				else if (c != '*') estado = 1;
		}
	}
}

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

