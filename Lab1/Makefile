nbr=1

run:
	@flex ex$(nbr).l
	@gcc lex.yy.c -lfl
	@./a.out < lab1_ex$(nbr).dat > saida.txt
	@diff saida.txt lab1_ex$(nbr)_saida.txt

