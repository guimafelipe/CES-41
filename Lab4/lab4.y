%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #define		MENOR				1
  #define		MENIG				2
  #define		MAIOR				3
  #define		MAIG				4
  #define		IGUAL				5
  #define		DIFER				6
  #define		MAIS 				1
  #define		MENOS 			2
  #define		VEZES 			1
  #define 	DIV 				2
  #define 	RESTO 			3

  #define   IDGLOB      1
  #define   IDVAR       2
  #define   IDFUNC      3
  #define   IDPROC      4
  #define   IDPROG      5

  #define   NAOVAR      0
  #define   INTEIRO     1
  #define   LOGICO      2
  #define   REAL        3
  #define   CARACTERE   4

  #define   NCLASSHASH  23
  #define   VERDADE     1
  #define   FALSO       0
  #define   MAXDIMS     3

  char *nometipid[6] = {" ", "IDGLOB", "IDVAR", "IDFUNC", "IDPROC", "IDPROG"};

  char *nometipvar[5] = {"NAOVAR", "INTEIRO", "LOGICO", "REAL", "CARACTERE"};

  typedef struct celsimb celsimb;
  typedef celsimb *simbolo;
  typedef struct elemlistsimb elemlistsimb;
  typedef elemlistsimb *pontelemlistsimb;
  typedef elemlistsimb *listsimb;
  struct celsimb {
    char *cadeia;
    int tid, tvar, nparam, tparam, ndims, dims[MAXDIMS+1];
    char inic, ref, array, param;
    listsimb listvar, listparam, listfunc, listvardecl;
    simbolo escopo, prox; 
  };
  
  struct elemlistsimb {
    simbolo simb;
    pontelemlistsimb prox;
  };
  
  typedef struct infolistexpr infolistexpr;
  typedef struct exprtipo exprtipo;
  typedef exprtipo *pontexprtipo;
  struct infolistexpr {
    pontexprtipo listtipo;
    int nargs;
  };
  
  struct exprtipo {
    simbolo simb;
    int tipo;
    pontexprtipo prox;
  };

  simbolo tabsimb[NCLASSHASH];
  simbolo simb;
  int tipocorrente;
  simbolo escopo;
  pontelemlistsimb pontvardecl;
  listsimb pontparam;
  listsimb pontfunc;
  int declparam;
  simbolo escaux;

  void InicTabSimb (void);
  void ImprimeTabSimb (void);
  simbolo InsereSimb (char *, int, int, simbolo);
  int hash (char *);
  simbolo ProcuraSimb (char *, simbolo escopo);
  void DeclaracaoRepetida (char *);
  void TipoInadequado (char *);
  void NaoDeclarado (char *);
  void VerificaInicRef (void);
  void Incompatibilidade (char *);
  void Esperado (char *);
  void NaoEsperado (char *);
  void InsereListSimb (simbolo s, listsimb *l);
  pontexprtipo InicListTipo(int);
  pontexprtipo ConcatListTipo(pontexprtipo, pontexprtipo);
%}

%union {
	char string[50];
	int atr, valor;
	float valreal;
	char carac;
  simbolo simb;
  int tipoexpr;
  int nsubscr;
  infolistexpr infolexpr;
}

%type           <simb> Variable
%type           <tipoexpr> Expression AuxExpr1 AuxExpr2 AuxExpr3 AuxExpr4 Term Factor
%type           <tipoexpr> ReturnStat Type ModHeader Module ModBody Stats CompStat StatList Statement
%type           <nsubscr> Subscripts SubscrList
%type           <infolexpr> ExprList Arguments
%type           <simb> FuncCall
%token          <string> ID
%token          <valor> INTCT
%token          <carac> CHARCT
%token          <valreal> FLOATCT
%token          <string> STRING
%token          OR
%token          AND
%token          NOT
%token          <atr> RELOP
%token          <atr> ADOP
%token          <atr> MULTOP
%token          NEG
%token          OPPAR
%token          CLPAR
%token          OPBRAK
%token          CLBRAK
%token          OPBRACE
%token          CLBRACE
%token          OPTRIP
%token          CLTRIP
%token          SCOLON
%token          COMMA
%token          COLON
%token          ASSIGN
%token          CALL
%token          FOR
%token          REPEAT
%token          VOID
%token          CHAR
%token          IF
%token          RETURN
%token          WHILE
%token          DO
%token          INT
%token          STATEMENTS
%token          WRITE
%token          ELSE
%token          LOGIC
%token          THEN
%token          FALSE
%token          MAIN
%token          TRUE
%token          FLOAT
%token          READ
%token          VAR
%token          <carac> INVAL
%%
Prog          : 
                {
                  InicTabSimb (); 
                  declparam = FALSO; 
                  escopo = simb = InsereSimb ("##global", IDGLOB, NAOVAR, NULL); 
                  pontvardecl = simb->listvardecl; 
                  pontfunc = simb->listfunc;
                }
                ID {printf("%s ", $2);}
                OPTRIP
                {
                  printf("\{\{\{\n");
                  InsereSimb ($2, IDPROG, NAOVAR,NULL);
                  pontvardecl = simb->listvardecl;
                  pontfunc = simb->listfunc;
                }
                Decls
                ModList
                MainMod
                CLTRIP
                {
                  printf("}}}\n");
                  VerificaInicRef ();
                  ImprimeTabSimb ();
                }
              ;
Decls         :
              |  VAR {printf("var ");}
                OPBRACE {printf("\{\n");}
                DeclList
                CLBRACE {printf("}\n");}
              ;
DeclList      :
                Declaration
              |
                DeclList Declaration
              ;
Declaration   :
                Type ElemList SCOLON {printf(";\n");}
              ;
Type          :
                INT
                {
                  printf("int ");
                  $$ = INTEIRO;
                  tipocorrente = INTEIRO;
                }
              |
                FLOAT
                {
                  printf("float ");
                  $$ = REAL;
                  tipocorrente = REAL;
                }
              |
                CHAR
                {
                  printf("char ");
                  $$ = CARACTERE;
                  tipocorrente = CARACTERE;
                }
              |
                LOGIC
                {
                  printf("logic ");
                  $$ = LOGICO;
                  tipocorrente = LOGICO;
                }
              |
                VOID
                {
                  printf("void ");
                  $$ = NAOVAR;
                  tipocorrente = NAOVAR;
                }
              ;
ElemList      :
                Elem
              |
                ElemList COMMA {printf(", ");} Elem
              ;
Elem          :
                ID {
                  printf ("%s ", $1);
                  escaux = escopo;
                  if  (ProcuraSimb ($1,escaux)  !=  NULL)
                    DeclaracaoRepetida ($1);
                  else {
                    simb = InsereSimb ($1,  IDVAR,  tipocorrente, escopo);
                    simb->array = FALSO;
                    simb->ndims = 0;
                  }
                } Dims
              ;
Dims          :
              |
                OPBRAK
                {
                  printf("\[");
                  simb->array = VERDADE;
                }
                DimList
                CLBRAK {printf("]");}
              ;
DimList       :
                INTCT
                {
                  printf("%d", $1);
                  if ($1 <= 0)
                    Esperado ("Valor inteiro positivo");
                  simb->ndims = 1;
                  simb->dims[1] = $1;
                }
              |
                INTCT
                COMMA
                INTCT
                {
                  printf("%d , %d", $1, $3);
                  if ($1 <= 0 || $3 <= 0)
                    Esperado ("Valor inteiro positivo");
                  simb->ndims = 2;  
                  simb->dims[1] = $1; 
                  simb->dims[2] = $3; 
                }
              |
                INTCT
                COMMA
                INTCT
                COMMA
                INTCT
                {
                  printf("%d , %d , %d", $1, $3, $5);
                  if ($1 <= 0 || $3 <= 0 || $5 <= 0)
                    Esperado ("Valor inteiro positivo");
                  simb->ndims = 3;
                  simb->dims[1] = $1; 
                  simb->dims[2] = $3; 
                  simb->dims[3] = $5;
                }
              ;
ModList       :

              |
                ModList Module;
              ;
Module        :
                ModHeader
                ModBody
                {      
                  switch ($1) {
                    case INTEIRO: case CARACTERE:
                      if ($2 != INTEIRO && $2 != CARACTERE) {
                        Incompatibilidade("Retorno deveria ser inteiro ou caractere!");
                        printf("Esperava-se: %s. Em vez disso, retornou-se: %s\n\n", nometipvar[$1], nometipvar[$2]);
                      }
                      break;
                    case REAL:
                      if ($2 != INTEIRO &&  $2 != CARACTERE && $2 != REAL) {
                        Incompatibilidade("Retorno deveria ser inteiro ou caractere ou real!");
                        printf("Esperava-se: %s. Em vez disso, retornou-se: %s\n\n", nometipvar[$1], nometipvar[$2]);
                      }
                      break;
                    case LOGICO:
                      if ($2 != LOGICO) {
                        Incompatibilidade("Retorno deveria ser do tipo logico!");
                        printf("Esperava-se: %s. Em vez disso, retornou-se: %s\n\n", nometipvar[$1], nometipvar[$2]);
                      }
                      break;
                    case NAOVAR:
                      if ($2 != NAOVAR) {
                        Incompatibilidade("Funcao tipo Void!");
                        printf("Esperava-se: void. Em vez disso, retornou-se: %s\n\n", nometipvar[$2]);
                      }
                      break;
                }
              } 
              ;
ModHeader     :
                Type
                ID
                OPPAR
                CLPAR
                {
                  printf("%s ()", $2);
                  while(escaux->escopo != NULL)
                    escaux = escaux->escopo;
                  if (ProcuraSimb ($2,escaux) != NULL)
                    DeclaracaoRepetida ($2);
                  else {
                    escopo = simb = InsereSimb ($2, IDFUNC, tipocorrente, escaux);
                      pontvardecl = simb->listvardecl;
                    pontparam = simb->listparam;
                  }
                  $$ = $1;
                }
              |
                Type
                ID
                OPPAR
                {
                  printf("%s (", $2);
                  declparam = VERDADE;
                  escaux = escopo;
                  while(escaux->escopo != NULL)
                    escaux = escaux->escopo;

                  if  (ProcuraSimb ($2,escaux) != NULL)
                    DeclaracaoRepetida ($2);
                  else {
                    escopo = simb = InsereSimb ($2, IDFUNC, tipocorrente, escaux);
                    pontvardecl = simb->listvardecl;
                    pontparam = simb->listparam;
                  }
                  $$ = $1;
                }
                ParamList
                CLPAR {printf(")\n");}
                {
                  declparam = FALSO;
                  $$ = $1;
                }
              ;
ParamList     :
                Parameter
              |
                ParamList
                COMMA {printf(", ");}
                Parameter
              ;
Parameter     :
                Type
                ID {printf("%s ", $2);}
                {
                  printf ("%s", $2); 
                  if  (ProcuraSimb ($2,escopo)  !=  NULL)
                    DeclaracaoRepetida ($2);
                  else {
                    simb = InsereSimb ($2,  IDVAR,  tipocorrente, escopo);
                    simb->array = FALSO; 
                    simb->ndims = 0;
                  }
                }
              ;
ModBody       :
                Decls
                Stats
                {$$ = $2;}
              ;
MainMod       :
                MAIN
                {
                  printf("main ");
                  escaux = escopo;
                  while(escaux->escopo != NULL) escaux = escaux->escopo;
                  escopo = simb = InsereSimb ("main", IDFUNC, tipocorrente, escaux);
                  pontvardecl = simb->listvardecl;
                  pontparam = simb->listparam;
                }
                ModBody
              ;
Stats         :
                STATEMENTS
                {
                  printf("statements ");
                }
                CompStat
                {$$ = $3;}
              ;
CompStat      :
                OPBRACE {printf("\{\n");}
                StatList
                CLBRACE
                {
                  printf("}\n");
                  $$ = $3;
                }
              ;
StatList      : StatList
                Statement
                {$$ = $2;}
              |
                
              ;
Statement     :
                CompStat {$$ = $1;}
              |
                IfStat {$$ = NAOVAR;} 
              |
                WhileStat {$$ = NAOVAR;}
              |
                RepeatStat {$$ = NAOVAR;} 
              |
                ForStat {$$ = NAOVAR;} 
              |
                ReadStat {$$ = NAOVAR;} 
              |
                WriteStat {$$ = NAOVAR;} 
              |
                AssignStat {$$ = NAOVAR;} 
              |
                CallStat {$$ = NAOVAR;} 
              |
                ReturnStat {$$ = $1;}
              |
                SCOLON {printf(";\n"); $$ = NAOVAR;}
              ;

IfStat        :
                IF {printf("if ");}
                Expression
                {
                  if($3 != LOGICO)
                    Incompatibilidade("As expressões devem ser relacionais ou logicas"); 
                }
                THEN {printf("then\n");}
                Statement
                ElseStat
              ;

ElseStat      :

              |
                ELSE {printf("else\n");}
                Statement
              ;

WhileStat     :
                WHILE {printf("while ");}
                Expression
                {
                  if($3 != LOGICO)
                    Incompatibilidade("As expressões devem ser relacionais ou logicas");  
                }
                DO {printf("do\n");}
                Statement
              ;

RepeatStat    :
                REPEAT {printf("repeat ");}
                Statement
                WHILE {printf("while ");}
                Expression
                {
                  if($6 != LOGICO)
                    Incompatibilidade("A expressao deve ser logica");   
                }
                SCOLON {printf(";\n");}
              ;

ForStat       :
                FOR {printf("for ");}
                Variable
                {
                  if($3 != NULL) {
                    $3->ref = $3->inic = VERDADE;
                    if ($3->tvar != INTEIRO && $3->tvar != CARACTERE)
                      Incompatibilidade("Deve ser inteiro ou caractere");
                  }                    
                }
                OPPAR {printf(" \(");}
                AuxExpr4 
                {
                  if ($7 != INTEIRO && $7 != CARACTERE)
                    Incompatibilidade("Deve ser inteiro ou caractere");
                }  
                COLON  {printf(": ");}
                Expression 
                {
                  if( $11 != LOGICO )
                    Incompatibilidade("Deve ser logico"); 
                }  
                COLON {printf(": ");}
                AuxExpr4 
                {
                  if( $15 != INTEIRO && $15 != CARACTERE )
                    Incompatibilidade("Deve ser inteiro ou caractere"); 
                }  
                CLPAR {printf (") ");}
                Statement
              ;

ReadStat      :
                READ {printf("read ");}
                OPPAR {printf("\( ");}
                ReadList
                CLPAR {printf(") ");}
                SCOLON {printf(";\n");}
              ;

ReadList      :
                Variable
                {
                  if($1 != NULL)
                    $1->ref = $1->inic = VERDADE;
                }
              |
                ReadList
                COMMA {printf(", ");}
                Variable
                {
                  if($4 != NULL)
                    $4->ref = $4->inic = VERDADE;
                }
              ;

WriteStat     :
                WRITE {printf("write ");}
                OPPAR {printf("\( ");}
                WriteList
                CLPAR {printf(") ");}
                SCOLON {printf(";\n");}
              ;

WriteList     :
                WriteElem
              |
                WriteList
                COMMA {printf(", ");}
                WriteElem
              ;

WriteElem     :
                STRING {printf("STRING ");}
              |
                Expression
              ;

CallStat      :
                CALL {printf("call ");}
                ID {printf("%s", $3);}
                OPPAR 
                {
                  printf("\( ");
                  simb = ProcuraSimb ($3, escopo->escopo);
                  if (!simb)
                    NaoDeclarado ($3);
                  else if (simb->tid != IDFUNC)
                    TipoInadequado ($3);

                  if(simb->tvar != VOID)
                    Incompatibilidade("Tipo incompativel com comando Call");
                  $<simb>$ = simb;
                }
                Arguments
                CLPAR {printf(") ");}
                SCOLON {printf(";\n");}
              ;

Arguments     :
                {
                  $$.nargs = 0;
                  $$.listtipo = NULL;
                }
              |
                ExprList
              ;

ReturnStat    :
                RETURN {printf("return ");}
                SCOLON
                {
                  printf(";\n");
                  $$ = NAOVAR;
                }
              |
                RETURN {printf("return ");}
                Expression
                SCOLON
                {
                  printf(";\n");
                  $$ = $3;
                }
              ;

AssignStat    :
                Variable
                {
                  if($1 != NULL)
                    $1->inic = $1->ref = VERDADE;
                }
                ASSIGN {printf(":= ");}
                Expression
                SCOLON
                {
                  printf(";\n");
                  if ($1 != NULL)
                    if ((($1->tvar == INTEIRO || $1->tvar == CARACTERE) && ($5 == REAL || $5 == LOGICO)) 
                    || ($1->tvar == REAL && $5 == LOGICO) 
                    || ($1->tvar == LOGICO && $5 != LOGICO))
                      Incompatibilidade ("Lado direito de comando de atribuicao improprio");
                }
              ;

ExprList      :
                Expression
                {
                  $$.nargs = 1;
                  $$.listtipo = InicListTipo ($1);
                }
              |
                ExprList
                COMMA {printf(", ");}
                Expression
                {
                  $$.nargs = $1.nargs + 1;
                  $$.listtipo = ConcatListTipo ($1.listtipo, InicListTipo ($4));
                }
              ;

Expression    :
                AuxExpr1
              |
                Expression
                OR {printf(" || ");}
                AuxExpr1
                {
                  if ($1 != LOGICO || $4 != LOGICO)
                    Incompatibilidade("Operando improprio para operador or");
                  $$ = LOGICO;
                }
              ;

AuxExpr1      :
                AuxExpr2
              |
                AuxExpr1
                AND {printf(" && ");}
                AuxExpr2
                {
                  if ($1 != LOGICO || $4 != LOGICO)
                    Incompatibilidade("Operando improprio para operador and");
                  $$ = LOGICO;
                }
              ;

AuxExpr2      :
                AuxExpr3
              |
                NOT {printf("!");}
                AuxExpr3
                {
                  if ($3 != LOGICO)
                    Incompatibilidade("Operando improprio para operador not");
                  $$ = LOGICO;
                }
              ;

AuxExpr3      :
                AuxExpr4
              |
                AuxExpr4
                RELOP
                {
                  switch($2) {
                    case MENOR:
                      printf(" < ");
                      break;
                    case MENIG:
                      printf(" <= ");
                      break;
                    case MAIOR:
                      printf(" > ");
                      break;
                    case MAIG:
                      printf(" >= ");
                      break;
                    case IGUAL:
                      printf(" = ");
                      break;
                    case DIFER:
                      printf(" != ");
                      break;
                  }
                }
                AuxExpr4
                {
                  switch($2) {
                    case MENOR: case MENIG: case MAIOR: case MAIG:
                      if ($1 != INTEIRO && $1 != REAL && $1 != CARACTERE || $4 != INTEIRO && $4 != REAL && $4 != CARACTERE)
                        Incompatibilidade("Operando improprio para operador relacional");
                      break;
                    case IGUAL: case DIFER:
                      if($1 == LOGICO && $4 != LOGICO || $1 != LOGICO && $4 == LOGICO)
                        Incompatibilidade("Operando improprio para operador relacional");
                      break;
                  }
                  $$ = LOGICO;
                }
              ;

AuxExpr4      :
                Term
              |
                AuxExpr4
                ADOP
                {
                  if ($2 == MAIS) printf("+");
                  else printf("-");
                }
                Term
                {
                  if ($1 != INTEIRO && $1 != REAL && $1 != CARACTERE || $4 != INTEIRO && $4 != REAL && $4 != CARACTERE)
                    Incompatibilidade("Operando improprio para operador aritmetico");
                  if ($1 == REAL || $4 == REAL)
                    $$ = REAL;
                  else
                    $$ = INTEIRO;
                }
              ;

Term          :
                Factor
              |
                Term
                MULTOP
                {
                  if ($2 == VEZES)
                    printf("*");
                  else if ($2 == DIV)
                    printf("/");
                  else
                    printf("%");
                }
                Factor
                {
                  switch($2) {
                    case VEZES: case DIV:
                      if ($1 != INTEIRO && $1 != REAL && $1 != CARACTERE || $4 != INTEIRO && $4 != REAL && $4 != CARACTERE)
                        Incompatibilidade("Operando improprio para operador aritmetico");
                      if ($1 == REAL || $4 == REAL)
                        $$ = REAL;
                      else
                        $$ = INTEIRO;
                      break;
                    case RESTO:
                      if ($1 != INTEIRO && $1 != CARACTERE || $4 != INTEIRO && $4 != CARACTERE) 
                        Incompatibilidade("Operando improprio para operador resto");
                      $$ = INTEIRO;
                      break;
                  }
                }

              ;

Factor        :
                Variable
                {
                    if  ($1 != NULL) {
                        $1->ref = VERDADE;
                        $$ = $1->tvar;
                    }
                }
              |
                INTCT
                {
                  printf("%d", $1);
                  $$ = INTEIRO;
                }
              |
                FLOATCT
                {
                  printf("%f", "$1");
                  $$ = REAL;
                }
              |
                CHARCT
                {
                  printf("%c", $1);
                  $$ = CARACTERE;
                }
              |
                TRUE
                {
                  printf("true");
                  $$ = LOGICO;
                }
              |
                FALSE
                {
                  printf("false");
                  $$ = LOGICO;
                }
              |
                NEG {printf("~");}
                Factor
                {
                  if ($3 != INTEIRO && $3 != REAL && $3 != CARACTERE)
                    Incompatibilidade ("Operando improprio para menos unario");
                  if ($3 == REAL)
                    $$ = REAL;
                  else
                    $$ = INTEIRO;
                }
              |
                OPPAR
                {
                  printf("\( ");
                }
                Expression
                CLPAR
                {
                  printf(") ");
                  $$ = $3;
                }
              |
                FuncCall
                {
                  $$ = $1->tvar;
                }
              ;

Variable      :
                ID
                {
                  printf("%s", $1);
                  escaux = escopo;
                  simb = ProcuraSimb ($1, escaux);
                  while (escaux && !simb) {
                    escaux = escaux->escopo;
                    if (escaux)
                      simb = ProcuraSimb ($1, escaux);
                  }
                  if (! simb)
                    NaoDeclarado ($1);
                  else if (simb->tid != IDVAR)
                    TipoInadequado ($1);
                  $<simb>$ = simb;
                }
                Subscripts
                {
                  $$ = $<simb>2;
                  if ($$ != NULL) {
                    if ($$->array == FALSO && $3 > 0)
                      NaoEsperado ("Subscrito\(s)");
                    else if ($$->array == VERDADE && $3 == 0)
                      Esperado ("Subscrito\(s)");
                    else if ($$->ndims != $3)
                      Incompatibilidade ("Numero de subscritos incompativel com declaracao");
                  }
                }
              ;

SubscrList    :
                AuxExpr4
                {
                  $$ = 1;
                  if ($1 != INTEIRO && $1 != CARACTERE) Incompatibilidade ("Tipo inadequado para subscrito"); 
                }
              |
                TwoSubscr {$$ = 2;}
              |
                ThreeSubscr {$$ = 3;}
              ;

Subscripts    :
                {
                  $$ = 0;
                }
              |
                OPBRAK {printf("\[");}
                SubscrList
                CLBRAK
                {
                  printf("] ");
                  $$ = $3;
                }
              ;

TwoSubscr     :
                AuxExpr4
                COMMA {printf(",");}
                AuxExpr4
                {
                  if ($1 != INTEIRO && $1 != CARACTERE || $4 != INTEIRO && $4 != CARACTERE)
                    Incompatibilidade ("Tipo inadequado para subscrito"); 
                }
              ;

ThreeSubscr   :
                TwoSubscr
                COMMA {printf(",");}
                AuxExpr4
                {
                  if ($4 != INTEIRO && $4 != CARACTERE)
                    Incompatibilidade ("Tipo inadequado para subscrito");
                }
              ;

FuncCall      :
                ID
                {printf ("%s", $1);}
                OPPAR
                {printf (" \(");}
                Arguments
                CLPAR
                {
                  printf (")");
                  simb = ProcuraSimb ($1, escopo->escopo);
                  if (! simb)
                    NaoDeclarado ($1);
                  else if (simb->tid != IDFUNC)
                    TipoInadequado ($1);
                  $$ = simb;
                                        
                  if ($$ && $$->tid == IDFUNC) {
                    if ($$->nparam != $5.nargs)
                      Incompatibilidade("Numero de argumentos diferente do  numero de parametros");
                              
                    if(($5.listtipo != NULL) && ($$->listparam != NULL))     
                      ChecArgumentos  ($5.listtipo, $$->listparam);

                    if(simb->tvar == VOID)
                        Incompatibilidade("O tipo da funcao do identificador de uma chamada de funcao nao pode ser void");
                  }
                }
              ;
%%
#include "lex.yy.c"

void InicTabSimb () {
  int i;
  for (i = 0; i < NCLASSHASH; i++)
    tabsimb[i] = NULL;
}

simbolo ProcuraSimb (char *cadeia, simbolo escopo) {
  simbolo s; int i;
  i = hash (cadeia);
  for (s = tabsimb[i]; (s!=NULL) && strcmp(cadeia, s->cadeia); s = s->prox)
    if(s->escopo == escopo)
      break;
  return s;
}

simbolo InsereSimb (char *cadeia, int tid, int tvar, simbolo escopo) {
  int i; simbolo aux, s;

  /*  Codigo comum a todos os identificadores  */

  i = hash (cadeia);  aux = tabsimb[i];
  s = tabsimb[i] = malloc (sizeof (celsimb));
  s->cadeia = malloc ((strlen(cadeia)+1)* sizeof(char));
  strcpy (s->cadeia, cadeia);
  s->prox = aux; s->tid = tid;  s->tvar = tvar;
  s->escopo = escopo;

  /*  Codigo para parametros e variáveis globais e locais  */

  if (declparam) {
    s->inic = s->ref = s->param = VERDADE;
    if (s->tid == IDVAR)
      InsereListSimb (s, &pontparam);
    s->escopo->nparam++;
  }

  else {
    s->inic = s->ref = s->param = FALSO;
    if (s->tid == IDVAR)
      InsereListSimb (s, &pontvardecl);
  }

  /*  Codigo para identificador global ou nome de função  */

  if (tid == IDGLOB || tid == IDFUNC) {
    s->listvardecl = (elemlistsimb *) malloc  (sizeof (elemlistsimb));
    s->listvardecl->prox = NULL;
  }

  if (tid == IDGLOB) {
    s->listfunc = (elemlistsimb *) malloc  (sizeof (elemlistsimb));
    s->listfunc->prox = NULL;
  }

  /*  Codigo para nome de função e retorno de Inserir */

  if (tid == IDFUNC) {
    s->listparam = (elemlistsimb *) malloc  (sizeof (elemlistsimb));
    s->listparam->prox = NULL;
    s->nparam = 0;
    InsereListSimb (s, &pontfunc);
  }

  return s;
}

void InsereListSimb (simbolo s, listsimb *lsimb) {
    if (lsimb == NULL) {
        lsimb = (listsimb *) malloc (sizeof(listsimb));
        (*lsimb)->simb = s;
        (*lsimb)->prox = NULL;
    } else {
        while((*lsimb)->prox != NULL) {*lsimb = (*lsimb)->prox;}
        (*lsimb)->prox = (listsimb) malloc (sizeof(elemlistsimb));
        (*lsimb)->prox->simb = s;
        (*lsimb)->prox->prox = NULL;
    }      
}

int hash (char *cadeia) {
  int i, h;
  for (h = i = 0; cadeia[i]; i++) {h += cadeia[i];}
  h = h % NCLASSHASH;
  return h;
}

void ImprimeTabSimb () {
  int i; simbolo s;
  printf ("\n\n   TABELA  DE  SIMBOLOS:\n\n");
  for (i = 0; i < NCLASSHASH; i++)
    if (tabsimb[i]) {
      printf ("Classe %d:\n", i);
      for (s = tabsimb[i]; s!=NULL; s = s->prox){
        printf ("  (%s, %s", s->cadeia,  nometipid[s->tid]);
        if (s->tid == IDVAR) {
          printf (", %s, %d, %d", nometipvar[s->tvar], s->inic, s->ref);
                    if (s->array == VERDADE) { 
                        int j;
                    printf (", EH ARRAY\n\tndims = %d, dimensoes:", s->ndims);
            for (j = 1; j <= s->ndims; j++)
                            printf ("  %d", s->dims[j]);
          }
        }
        printf(")\n");
      }
    }
}

void DeclaracaoRepetida (char *s) {
  printf ("\n\n***** Declaracao Repetida: %s *****\n\n", s);
}

void NaoDeclarado (char *s) {
    printf ("\n\n***** Identificador Nao Declarado: %s *****\n\n", s);
}

void TipoInadequado (char *s) {
    printf ("\n\n***** Identificador de Tipo Inadequado: %s *****\n\n", s);
}

pontexprtipo InicListTipo(int tipo) {
    pontexprtipo listtipo = (exprtipo*) malloc (sizeof (exprtipo));
    listtipo->prox = (exprtipo*) malloc (sizeof (exprtipo));
    listtipo->prox->tipo = tipo;
    listtipo->prox->prox = NULL;
    return listtipo;
}

void VerificaInicRef () {
  int i; simbolo s;

  printf ("\n");
  for (i = 0; i < NCLASSHASH; i++)
    if (tabsimb[i])
      for (s = tabsimb[i]; s!=NULL; s = s->prox)
        if (s->tid == IDVAR) {
          if (s->inic == FALSO)
            printf ("%s: Nao Inicializada\n", s->cadeia);
          if (s->ref == FALSO)
            printf ("%s: Nao Referenciada\n", s->cadeia);
        }
}

void Incompatibilidade (char *s) {
    printf ("\n\n***** Incompatibilidade: %s *****\n\n", s);
}

void Esperado (char *s) {
    printf ("\n\n***** Esperado: %s *****\n\n", s);
}

void NaoEsperado (char *s) {
  printf ("\n\n***** Nao Esperado: %s *****\n\n", s);
}

void ChecArgumentos (pontexprtipo Ltiparg,   listsimb Lparam) {
  pontexprtipo p;  pontelemlistsimb q;
  p = Ltiparg->prox; q = Lparam->prox;
  while (p != NULL && q != NULL) {
    switch (q->simb->tvar) {
      case INTEIRO: case CARACTERE:
        if (p->tipo != INTEIRO && p->tipo != CARACTERE)
          Incompatibilidade("Tipo inadequado para argumento");
        break;
      case REAL:
        if (p->tipo != INTEIRO &&  p->tipo != CARACTERE && p->tipo != REAL)
          Incompatibilidade("Tipo inadequado para argumento");
        break;
      case LOGICO:
        if (p->tipo != LOGICO)
          Incompatibilidade("Tipo inadequado para argumento");
        break;
      default:
        if (q->simb->tvar != p->tipo)
          Incompatibilidade("Tipo inadequado para argumento");
        break;
    }
    p = p->prox; q = q->prox;
  }
}

pontexprtipo ConcatListTipo(pontexprtipo listtipo1, pontexprtipo listtipo2) {
  if(listtipo1 == NULL) return listtipo2;
  else if(listtipo2 == NULL) return listtipo1;
  else {
    while(listtipo1->prox != NULL) {listtipo1 = listtipo1->prox;}
    listtipo1->prox = listtipo2;
    return listtipo1;
  }
}