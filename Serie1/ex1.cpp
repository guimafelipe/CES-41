#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#define FINAL	0
#define INVAL 	1
#define ID 		2
#define CTE		3
#define SCOLON	4
#define OPBRAK	5
#define CLBRAK	6
#define ADD		7
#define EQ		8
#define OPPAR	9
#define CLPAR	10

struct atomo {
	int tipo;
	string atrib;
};

char carac;
string cadeia;

atomo atom;

void FormaCadeia(){
	cadeia.append(1u, carac);
}

char NovoCarac(){
	char aux;
	scanf("%c", &aux);
	return aux;
}

void ImprimeAtomo(){
	printf("%d | ", atom.tipo);
	switch(atom.tipo){
		case EQ:
			printf("EQ");
			break;
		case OPPAR:
			printf("OPPAR");
			break;
		case CLPAR:
			printf("CLPAR");
			break;
		case OPBRAK:
			printf("OPBRAK");
			break;
		case CLBRAK:
			printf("CLBRAK");
			break;
		case ADD:
			printf("ADD");
			break;
		case ID:
			printf("ID");
			break;
		case CTE:
			printf("CTE");
			break;
		case SCOLON:
			printf("SCOLON");
			break;
		case FINAL:
			printf("FINAL");
			break;
	}
	cout << " | " << atom.atrib << endl;	
}

atomo Classifica(){
	atomo result;
	switch(carac){
		case '+':
			result.tipo = ADD;
			result.atrib = "+";
			break;
		case ';':
			result.tipo = SCOLON;
			result.atrib = ";";
			break;
		case '{':
			result.tipo = OPBRAK;
			result.atrib = "{";
			break;
		case '}':
			result.tipo = CLBRAK;
			result.atrib = "}";
			break;
		case '(':
			result.tipo = OPPAR;
			result.atrib = "(";
			break;
		case ')':
			result.tipo = CLPAR;
			result.atrib = ")";
			break;
		case '=':
			result.tipo = EQ;
			result.atrib = "=";
			break;
	}
	return result;
}

atomo FormaID(){
	atomo result;
	result.tipo = ID;
	result.atrib = cadeia;
	return result;
}

atomo FormaCTE(){
	atomo result;
	result.tipo = CTE;
	result.atrib = cadeia;
	return result;
}

void NovoAtomo(){
	int estado = 1;
	
	cadeia.erase(cadeia.begin(), cadeia.end());

	while(estado != 3){ //estado de saida do while
		switch(estado){
			case 1:
				switch(carac){
					case '+':
					case ';':
					case '{':
					case '}':
					case '(':
					case ')':
					case '=':
						atom = Classifica();
						carac = NovoCarac();
						estado = 3;
						break;
					case '\0':
						atom.tipo = FINAL;
						atom.atrib = "FINAL";
						estado = 3;
						break;
					default:
						if(isalpha(carac)){ //Formando ID
							FormaCadeia();
							carac = NovoCarac();
							estado = 2;
						} else if(isdigit(carac)){ //Formando CTE
							FormaCadeia();
							carac = NovoCarac();
							estado = 4;
						} else if((isspace(carac)||iscntrl(carac))&&carac != 0){
							carac = NovoCarac();
							estado = 1; //Leu espaço em branco
						} else {
							atom.atrib = "";
							estado = 3;
						}
				}
				break;
			case 2:
				if(isalnum(carac)){
					FormaCadeia();
					carac = NovoCarac();
					estado = 2;
				} else {
					atom = FormaID();
					estado = 3;
				}
				break;
			case 4:
				if(isdigit(carac)){
					FormaCadeia();
					carac = NovoCarac();
					estado = 4;
				} else {
					atom = FormaCTE();
					estado = 3;
				}
				break;
		}
	}
}

int main(){
	printf("Analise lexica!\n\n");
	atom.tipo = INVAL;
	carac = NovoCarac();
	while(atom.tipo != FINAL){
		NovoAtomo();
		ImprimeAtomo();
	}
	printf("Análise encerrada\n");
	return 0;
}
