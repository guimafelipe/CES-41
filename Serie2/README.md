# Série 2 - Compiladores

## Questão 1

### Entrada

`id*((id + id)*(id+id+id))`

----

### Tabela

|Pilha|Entrada|Ação|Goto|
|---|---|---|---|
|$ 0|id\*((id+id)\*(id+id+id))$|d5| |	
|$ 0 (5,id) | \*((id+id)\*(id+id+id))$ | r6 (F -> id) | Goto(0, F) = 3 |
|$ 0 (3,F) | \*((id+id)\*(id+id+id))$ | r4 (T -> F) | Goto(0, T) = 2|
|$ 0 (2,T) | \*((id+id)\*(id+id+id))$ | d7 | |
|$ 0 (2,T) (7,\*) | ((id+id)\*(id+id+id))$ | d4 | |
|$ 0 (2,T) (7,\*) (4,*(*) | (id+id)\*(id+id+id))$| d4 | |
|$ 0 (2,T) (7,\*) (4,*(*) (4,*(*) | id+id)\*(id+id+id))$ | d5 | |
|$ 0 (2,T) (7,\*) (4,*(*) (4,*(*) (5,id) | +id)\*(id+id+id))$| r6 (F -> id) |Goto(4,F) = 3|
|$ 0 (2,T) (7,\*) (4,*(*) (4,*(*) (3,F) | +id)\*(id+id+id))$|r4 (T -> F) |Goto(4,T) = 2|
|$ 0 (2,T) (7,\*) (4,*(*) (4,*(*) (2,T) | +id)\*(id+id+id))$|r2 (E -> T)|Goto(4,E) = 8|
|$ 0 (2,T) (7,\*) (4,*(*) (4,*(*) (8,E) | +id)\*(id+id+id))$|d6||
|$ 0 (2,T) (7,\*) (4,*(*) (4,*(*) (8,E) (6,+) | id)\*(id+id+id))$|d5||
|$ 0 (2,T) (7,\*) (4,*(*) (4,*(*) (8,E) (6,+) (5,id)| )\*(id+id+id))$|r6 (F -> id)|Goto(6,F) = 3|
|$ 0 (2,T) (7,\*) (4,*(*) (4,*(*) (8,E) (6,+) (3,F)| )\*(id+id+id))$|r4 (T -> F)|Goto(6,T) = 9|
|$ 0 (2,T) (7,\*) (4,*(*) (4,*(*) (8,E) (6,+) (9,T)| )\*(id+id+id))$|r1 (E -> E+T)|Goto(4,E) = 8|
|$ 0 (2,T) (7,\*) (4,*(*) (4,*(*) (8,E)| )\*(id+id+id))$|d11| |
|$ 0 (2,T) (7,\*) (4,*(*) (4,*(*) (8,E) (11,*)*)| \*(id+id+id))$|r5 (F -> (E))|Goto(4,F) = 3|
|$ 0 (2,T) (7,\*) (4,*(*) (3,F)| \*(id+id+id))$|r4 (T -> F)|Goto(4,T) = 2|
|$ 0 (2,T) (7,\*) (4,*(*) (2,T)| \*(id+id+id))$|d7| |
|$ 0 (2,T) (7,\*) (4,*(*) (2,T) (7,\*)| (id+id+id))$|d4| |
|$ 0 (2,T) (7,\*) (4,*(*) (2,T) (7,\*) (4,*(*)| id+id+id))$|d5| |
|$ 0 (2,T) (7,\*) (4,*(*) (2,T) (7,\*) (4,*(*) (5,id)| +id+id))$|r6 (F -> id)|Goto(4,F) = 3|
|$ 0 (2,T) (7,\*) (4,*(*) (2,T) (7,\*) (4,*(*) (3,F)| +id+id))$|r4 (T -> F)|Goto(4,T) = 2|
|$ 0 (2,T) (7,\*) (4,*(*) (2,T) (7,\*) (4,*(*) (2,T)| +id+id))$|r2 (E -> T)|Goto(4,E) = 8|
|$ 0 (2,T) (7,\*) (4,*(*) (2,T) (7,\*) (4,*(*) (8,E)| +id+id))$|d6| |
|$ 0 (2,T) (7,\*) (4,*(*) (2,T) (7,\*) (4,*(*) (8,E) (6,+)| id+id))$|d5| |
|$ 0 (2,T) (7,\*) (4,*(*) (2,T) (7,\*) (4,*(*) (8,E) (6,+) (5,id)| +id))$|r6 (F -> id)|Goto(6,F) = 3|
|$ 0 (2,T) (7,\*) (4,*(*) (2,T) (7,\*) (4,*(*) (8,E) (6,+) (3,F)| +id))$|r4 (T -> F)|Goto(6,T) = 9|
|$ 0 (2,T) (7,\*) (4,*(*) (2,T) (7,\*) (4,*(*) (8,E) (6,+) (9,T)| +id))$|r1 (E -> E+T)|Goto(4,E) = 8|
|$ 0 (2,T) (7,\*) (4,*(*) (2,T) (7,\*) (4,*(*) (8,E)| +id))$|d6| |
|$ 0 (2,T) (7,\*) (4,*(*) (2,T) (7,\*) (4,*(*) (8,E) (6,+)| id))$|d5| |
|$ 0 (2,T) (7,\*) (4,*(*) (2,T) (7,\*) (4,*(*) (8,E) (6,+) (5,id)| ))$|r6 (F -> id)|Goto(6,F) = 3 |
|$ 0 (2,T) (7,\*) (4,*(*) (2,T) (7,\*) (4,*(*) (8,E) (6,+) (3,F)| ))$|r4 (T -> F)|Goto(6,T) = 9 |
|$ 0 (2,T) (7,\*) (4,*(*) (2,T) (7,\*) (4,*(*) (8,E) (6,+) (9,T)| ))$|r1 (E -> E+T)|Goto(4,E) = 8 |
|$ 0 (2,T) (7,\*) (4,*(*) (2,T) (7,\*) (4,*(*) (8,E)| ))$|d11| |
|$ 0 (2,T) (7,\*) (4,*(*) (2,T) (7,\*) (4,*(*) (8,E) (11,*)*)| )$|r5 (F -> (E))|Goto(7,F) = 10|
|$ 0 (2,T) (7,\*) (4,*(*) (2,T) (7,\*) (10,F)| )$|r3 (T -> T\*F)|Goto(4,T) = 2|
|$ 0 (2,T) (7,\*) (4,*(*) (2,T) | )$|r2 (E -> T)|Goto(4,E) = 8|
|$ 0 (2,T) (7,\*) (4,*(*) (8,E) | )$|d11| |
|$ 0 (2,T) (7,\*) (4,*(*) (8,E) (11,*)*)| $|r5 (F -> (E))|Goto(7,E) = 10|
|$ 0 (2,T) (7,\*) (10,F)| $|r5 (F -> (E))|Goto(7,F) = 10|
|$ 0 (2,T) (7,\*) (10,F)| $|r3 (T -> T\*F)|Goto(0,T) = 2|
|$ 0 (2,T)| $|r2 (E -> T)|Goto(0,E) = 1|
|$ 0 (1,E)| $|aceito| |

## Questão 2

### Gramática:
```
1) Prog -> ID { ListDecls }
2) ListDecls -> Decl | ListDecls Decl
3) Decl -> Tipo ListId
4) Tipo ->int | real
5) ListId -> ID | ListId , ID
```

### Passo 1 - AFND

#### Itens de Produção

|Produção | Itens|
|---|---|
|Prog'->Prog |Prog'->.Prog Prog'->Prog. |
|Prog->ID{ListDecls} | Prog->.ID{ListDecls} Prog->ID.{ListDecls} Prog->ID{.ListDecls} Prog->ID{ListDecls.} Prog->ID{ListDecls}.|
|ListDecls->Decl|ListDecls->.Decl ListDecls->Decl.|
|ListDecls->ListDecls Decl|ListDecls->.ListDecls Decl ListDecls->ListDecls.Decl ListDecls->ListDecls Decl.|
|Decl->Tipo ListId|Decl->.Tipo ListId Decl->Tipo.ListId Decl->Tipo ListId.|
|Tipo->int|Tipo->.int Tipo->int.|
|Tipo->real|Tipo->.real Tipo->real.|
|ListId->ID|ListId->.ID ListId->ID.|
|ListId->ListId,ID|ListId->.ListId,ID ListId->ListId.,ID ListId->ListId,.ID ListId->ListId,ID.|

#### Autômatos construídos

Usou-se o site `draw.io` para a construção das imagens dos grafos abaixo.
Dentro da pasta `diagrams`, pode-se encontrar os arquivos `.png` e os arquivos `.xml` dos mesmos. 
Pode-se usar os arquivos `.xml` para abrir os diagramas no site supracitado.

##### Autômato não determinístico
![alt text](https://raw.githubusercontent.com/guimafelipe/CES-41/master/Serie2/Diagrams/AFND.png "AFND")


##### Autômato determinístico

![alt text](https://raw.githubusercontent.com/guimafelipe/CES-41/master/Serie2/Diagrams/AFD.png "AFND")

> Note que na imagem estão representados os números referentes ao estado de cada nó do autômato

#### Tabela de Seguintes

|Produção | Seguintes|
|---|:-:|
|Prog| $|
|ListDecls |} int real| 
|Decl| } int real|
|Tipo| ID|
|ListId |, } int real|

#### Tabela SLR

##### Produções numeradas

```
1) Prog -> ID { ListDecls }
2) ListDecls -> Decl
3) ListDecls -> ListDecls Decl
4) Decl -> Tipo ListId
5) Tipo -> int
6) Tipo -> real
7) ListId -> ID
8) ListId -> ListId , ID
```
##### Tabela das Transições

|Estado|ID|{|}|,|int|real|$|
|--:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|1|d2| | | | | | |
|2| |d3| | | | | |
|3| | | | |d12|d13| |
|4| | |d5| |d12|d13| |
|5| | | | | | |r1|
|6| | |r3| |r3|r3| |
|7|d8| | | | | | |
|8| | |r7|r7|r7|r7| |
|9| | |r4|d10|r4|r4| |
|10|d11| | | | | | |
|11| | |r8|r8|r8|r8| |
|12|r5| | | | | | |
|13|r6| | | | | | |
|14| | | | | | |aceitar|

##### Tabela de Goto's

|Estado|Prog|ListDecls|Decl|Tipo|ListId|
|--:|:-:|:-:|:-:|:-:|:-:|
|1|14| | | | | |
|2| | | | | |
|3| |4|6|7| |
|4| | |6|7| |
|5| | | | | |
|6| | | | | |
|7| | | | |9|
|8| | | | | |
|9| | | | | |
|10| | | | | |
|11| | | | | |
|12| | | | | |
|13| | | | | |
|14| | | | | |

## Questão 3

### Letra a

Ocorreram três conflitos de shift/reduce relacionados à estados que antecedem um simbolo **MAIS**.
Por exemplo, se temos `ID = E` e o átomo seguinte é um `MAIS`, não sabemos se devemos reduzir o `ID = E` para um `E` e shiftar ou consideramos o `E` no final para shiftar com o átomo.
A implementação dessa questão encontra-se aqui.
O arquivo gerado encontra-se aqui.

### Letra b

Para tirar o conflito, usaremos a informação da precedência mostrada no enunciado da questão.
Com isso, nossa linguagem passa a ser:

```
E	:	WHILE E DO E
	|	Exp
	;

Exp	:	ID EQ Term
	|	Term
	;

Term:	Term + ID
	|	ID
	;
```

Agora, nossa linguagem não tem nenhum conflito e respeita as regras de associatividade  e precedência estipuladas.

A implementação dessa questão pode ser encontrada aqui.

A linguagem foi testada para três casos testes, que estão a seguir:

Caso 1
Caso 2
Caso 3

Onde não ocorreram erros e ela foi capaz de reescrever o código do caso teste.
