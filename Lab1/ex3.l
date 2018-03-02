%{
#define	ACEITA	1
#define REJEITA 2
#define OUTRA 	3
%}
delim		[ \t\n\r]
ws			{delim}+
aceita (0*1*)*
string	[^ \t\n\r]+
%%
{ws}		{ ;}
{aceita} 	{return ACEITA;}
{string}	{return OUTRA;}
%%
int check(char* str){
	int uns = 0;
	int ind = 0;
	while(ind < 4){
		if(str[ind] == '1'){
			uns++;
		} else if(str[ind] == '\0'){ //Tamanho menor que 4
			return 0;
		}
		ind++;
	}
	if(uns < 3) return 0;
	while(str[ind] != '\0'){
		if(str[ind-4] == '1') uns--;
		if(str[ind] == '1') uns++;
		if(uns < 3) return 0;
		ind++;
	}
	return 1;
}

main () {
	int i;
	while (i = yylex ())
		switch (i) {
			case ACEITA:
				if(check(yytext))
					printf ("%-20s: Aceita\n", yytext); 
				else
					printf ("%-20s: Rejeitada\n", yytext); 
				break;
			case OUTRA:
				printf ("%-20s: Rejeitada\n", yytext); 
				break;
		}
} 
