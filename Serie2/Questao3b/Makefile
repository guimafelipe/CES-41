build:
	@flex quest.l
	@yacc quest.y -v
	@gcc y.tab.c yyerror.c main.c -o ex -ll

