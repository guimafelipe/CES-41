%{
  void comentario ();
%}
delim               [ \t\n\r]
ws                  {delim}+
digito              [0-9]
letra               [a-zA-Z]
caractere1          \\.|[^\\']
caractere2          \\.|[^\\\"]
id                  {letra}({letra}|{digito})*
intct               {digito}+
charct              '[\\]?{caractere1}*'
floatct             {digito}+\.{digito}*([Ee][+-]?{digito}+)?
string              \"[\\]?{caractere2}*\"
%%
call                {return CALL;}
for                 {return FOR;}
repeat              {return REPEAT;}
void                {return VOID;}
char                {return CHAR;}
if                  {return IF;}
return              {return RETURN;}
while               {return WHILE;}
do                  {return DO;}
int                 {return INT;}
statements          {return STATEMENTS;}
write               {return WRITE;}
else                {return ELSE;}
logic               {return LOGIC;}
then                {return THEN;}
false               {return FALSE;}
main                {return MAIN;}
true                {return TRUE;}
float               {return FLOAT;}
read                {return READ;}
var                 {return VAR;}
{ws}                { ;}
{id}                {strcpy (yylval.string, yytext); return ID;}
{intct}             {yylval.valor = atoi(yytext); return INTCT;}
{floatct}           {yylval.valreal = atof(yytext); return FLOATCT;}
"||"                {return OR;}
"&&"                {return AND;}
"!"                 {return NOT;}
"<"                 {yylval.atr = MENOR; return RELOP;}
"<="                {yylval.atr = MENIG; return RELOP;}
">"                 {yylval.atr = MAIOR; return RELOP;}
">="                {yylval.atr = MAIG; return RELOP;}
"="                 {yylval.atr = IGUAL; return RELOP;}
"!="                {yylval.atr = DIFER; return RELOP;}
"+"                 {yylval.atr = MAIS; return ADOP;}
"-"                 {yylval.atr = MENOS; return ADOP;}
"*"                 {yylval.atr = VEZES; return MULTOP;}
"/"                 {yylval.atr = DIV; return MULTOP;}
"%"                 {yylval.atr = RESTO; return MULTOP;}
"~"                 {return NEG;}
"("                 {return OPPAR;}
")"                 {return CLPAR;}
"["                 {return OPBRAK;}
"]"                 {return CLBRAK;}
"{"                 {return OPBRACE;}
"}"                 {return CLBRACE;}
"{{{"               {return OPTRIP;}
"}}}"               {return CLTRIP;}
";"                 {return SCOLON;}
","                 {return COMMA;}
":"                 {return COLON;}
":="                {return ASSIGN;}
"/*"                {comentario ();}
{charct}            {strcpy (yylval.string, yytext); return CHARCT;}
{string}            {strcpy (yylval.string, yytext); return STRING;}
.                   {yylval.carac = yytext[0]; return INVAL;}
%%
void comentario () {
    char c;  int estado;
    estado = 1;
    printf("\n/*");
    while (estado != 3) {
        switch (estado) {
            case 1:
                c = input ();
                if (c == EOF)
                    estado = 3;
                else if (c == '*')
                    estado = 2;
                printf("%c", c);
                break;
            case 2:
                c = input ();
                if (c == EOF || c == '/')
                    estado = 3;
                else if (c != '*')
                    estado = 1;
                printf("%c", c);
        }
    }
    printf("\n\n");
}
