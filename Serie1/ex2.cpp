#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

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

using namespace std;

struct atomo{
	int tipo;
};

atomo atom;

void Expressao();
void ListCmd();

void Error(string msg){
	cout << "ERROR: " << msg << endl;
}

void NovoAtomo(){
	char linha[25];
	scanf(" %d ", &atom.tipo);
	gets(linha);
	printf("%s\n", linha);
}

void Termo(){
	if(atom.tipo == OPPAR){
		NovoAtomo();
		Expressao();
		if(atom.tipo != CLPAR){
			Error("Expected CLPAR");
		} else NovoAtomo();
	} else if(atom.tipo == ID || atom.tipo == CTE){
		NovoAtomo();
	} else {
		Error("Expected ID, CTE or OPPAR");
	}
}

void Eaux(){
	if(atom.tipo == ADD){
		NovoAtomo();
		Expressao();
	}
}

void Expressao(){
	Termo();
	Eaux();
}

void Comando(){
	if(atom.tipo != ID){
		Error("Expected ID");
		return;
	} else NovoAtomo();
	if(atom.tipo != EQ){
		Error("Expected EQ");
		return;
	} else NovoAtomo();
	Expressao();
	if(atom.tipo != SCOLON){
		Error("Expected SCOLON");
		return;
	} else NovoAtomo();
}

void LCaux(){
	if(atom.tipo == ID){
		ListCmd();
	}
}

void ListCmd(){
	Comando();
	LCaux();
}

void CmdComp(){
	if(atom.tipo != OPBRAK){
		Error("Expected OPBRAK");
		return;
	} else
		NovoAtomo();
	ListCmd();
	if(atom.tipo != CLBRAK){
		Error("Expected CLBRAK");
		return;
	} else NovoAtomo();
}

void Prog(){
	if(atom.tipo == ID){
		NovoAtomo();
		CmdComp();
	} else {
		cout << "Error" << endl;
	}
}

int main(){
	NovoAtomo();
	Prog();
	if(atom.tipo != FINAL)
		Error("Expected Final");
	return 0;
}
