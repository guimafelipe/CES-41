%{
#define	ACEITA	1
#define REJEITA 2
#define OUTRA 	3
%}
delim		[ \t\n\r]
ws			{delim}+
rejeita	1*(1*01*0)*1*|0*1(0*10*1)*0*
aceita (0*1*)*
string	[^ \t\n\r]+
%%
{ws}		{ ;}
{rejeita}  	{return REJEITA;}
{aceita} 	{return ACEITA;}
{string}	{return OUTRA;}
%%
main () {
	int i;
	while (i = yylex ())
		switch (i) {
			case REJEITA:
				printf ("%-20s: Rejeitada\n", yytext); 
				break;
			case ACEITA:
				printf ("%-20s: Aceita\n", yytext); 
				break;
			case OUTRA:
				printf ("%-20s: Rejeitada\n", yytext); 
				break;
		}
} 
