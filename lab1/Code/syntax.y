%locations

%{
    
    #include "tree.h"
    #include "lex.yy.c"
    #include<stdio.h>
%}

%union {
    tNode* type_node;
}

%token <type_node>INT
%token <type_node>FLOAT
%token <type_node>SEMI COMMA TYPE STRUCT ID LC RC LB RB LP RP RETURN IF ELSE WHILE ASSIGNOP AND OR RELOP PLUS MINUS STAR DIV NOT DOT

%type <type_node> Program ExtDefList ExtDef ExtDecList Specifier StructSpecifier OptTag Tag VarDec FunDec VarList ParamDec CompSt StmtList Stmt DefList Def DecList Dec Exp Args

%right ASSIGNOP
%left AND OR
%left RELOP
%left PLUS MINUS
%left STAR DIV
%right NOT
%left LB RB LP RP DOT
%nonassoc IF ELSE WHILE

%nonassoc LOWER_THAN_ELSE

%%
Program : ExtDefList{$$=addNode("Program",1,$1);}
  ;
ExtDefList :{$$=addNode("ExtDefList",0,-1);}
  | ExtDef ExtDefList{$$=addNode("ExtDefList",2,$1,$2);}
  ;
ExtDef : Specifier ExtDecList SEMI{$$=addNode("ExtDef",3,$1,$2,$3);}
  | Specifier SEMI{$$=addNode("ExtDef",2,$1,$2);}
  | Specifier FunDec CompSt{$$=addNode("ExtDef",3,$1,$2,$3);}
  | Specifier error SEMI{yyerror("initialized or invalid global variable");}
  | error SEMI{yyerror("error 0");}
  | error Specifier SEMI{yyerror("error 2");}
  ;
ExtDecList : VarDec{$$=addNode("ExtDecList",1,$1);}
  | VarDec COMMA ExtDecList{$$=addNode("ExtDecList",3,$1,$2,$3);}
  ;

Specifier : TYPE{$$=addNode("Specifier",1,$1);}
  | StructSpecifier{$$=addNode("Specifier",1,$1);}
  ;
StructSpecifier : STRUCT OptTag LC DefList RC{$$=addNode("StructSpecifier",5,$1,$2,$3,$4,$5);}
  | STRUCT Tag{$$=addNode("StructSpecifier",2,$1,$2);}
  ;
OptTag : {$$=addNode("OptTag",0,-1);}
  | ID {$$=addNode("OptTag",1,$1);}
  ;

Tag: ID{$$=addNode("Tag",1,$1);};

VarDec : ID {$$=addNode("VarDec",1,$1);}
  | VarDec LB INT RB{$$=addNode("VarDec",4,$1,$2,$3,$4);}
  | VarDec LB error RB{yyerror("invalid expression between \'[]\'");}
  ;
FunDec : ID LP VarList RP{$$=addNode("FunDec",4,$1,$2,$3,$4);}
  | ID LP RP{$$=addNode("FunDec",3,$1,$2,$3);}
  | ID LP error RP{yyerror("invalid varlist");}
  | error LP VarList RP{yyerror("invalid function name");}
  | error LP RP{yyerror("invalid function name");}
  ;
VarList : ParamDec COMMA VarList{$$=addNode("VarList",3,$1,$2,$3);}
  | ParamDec{$$=addNode("VarList",1,$1);}
  ;
ParamDec : Specifier VarDec {$$=addNode("ParamDec",2,$1,$2);};

CompSt : LC DefList StmtList RC {$$=addNode("CompSt",4,$1,$2,$3,$4);}
  ;
StmtList : {$$=addNode("StmList",0,-1);}
  | Stmt StmtList{$$=addNode("StmtList",2,$1,$2);}
  ;
Stmt : Exp SEMI{$$=addNode("Stmt",2,$1,$2);}
  | CompSt{$$=addNode("Stmt",1,$1);}
  | RETURN Exp SEMI{$$=addNode("Stmt",3,$1,$2,$3);}
  | IF LP Exp RP Stmt{$$=addNode("Stmt",5,$1,$2,$3,$4,$5);}
  | IF LP Exp RP Stmt ELSE Stmt{$$=addNode("Stmt",7,$1,$2,$3,$4,$5,$6,$7);}
  | WHILE LP Exp RP Stmt{$$=addNode("Stmt",5,$1,$2,$3,$4,$5);}
  | error SEMI{yyerror("invalid statement or cannot define variable before \';\'");}
  | Exp error SEMI{yyerror("invalid expression near \';\'");}
  | RETURN Exp error{yyerror("invalid expression near \'return\'");}
  | RETURN error SEMI{yyerror("invalid expression between \'return\' and \';\'");}
  | IF LP error RP Stmt %prec LOWER_THAN_ELSE{yyerror("invalid statement of if");}
  | IF LP Exp RP error ELSE Stmt{yyerror("invalid statement of if");}
  | IF LP error RP ELSE Stmt{yyerror("invalid statement of if");}
  | error LP Exp RP Stmt{yyerror("invalid statement of if");}
  ;

DefList : {$$=addNode("DefList",0,-1);}
  | Def DefList{$$=addNode("DefList",2,$1,$2);}
  ;
Def : Specifier DecList SEMI{$$=addNode("Def",3,$1,$2,$3);}
  | Specifier error SEMI{yyerror("invalid variable or expected expression before \';\'");}
  | Specifier DecList error{yyerror("missing \';\' or invalid token");}
  ;
DecList : Dec{$$=addNode("DecList",1,$1);}
  | Dec COMMA DecList{$$=addNode("DecList",3,$1,$2,$3);}
  ;
Dec : VarDec{$$=addNode("Dec",1,$1);}
  | VarDec ASSIGNOP Exp{$$=addNode("Dec",3,$1,$2,$3);}
  ;

Exp : Exp ASSIGNOP Exp{$$=addNode("Exp",3,$1,$2,$3);}
  | Exp AND Exp{$$=addNode("Exp",3,$1,$2,$3);}
  | Exp OR Exp{$$=addNode("Exp",3,$1,$2,$3);}
  | Exp RELOP Exp{$$=addNode("Exp",3,$1,$2,$3);}
  | Exp PLUS Exp{$$=addNode("Exp",3,$1,$2,$3);}
  | Exp MINUS Exp{$$=addNode("Exp",3,$1,$2,$3);}
  | Exp STAR Exp{$$=addNode("Exp",3,$1,$2,$3);}
  | Exp DIV Exp{$$=addNode("Exp",3,$1,$2,$3);}
  | LP Exp RP{$$=addNode("Exp",3,$1,$2,$3);}
  | MINUS Exp{$$=addNode("Exp",2,$1,$2);}
  | NOT Exp{$$=addNode("Exp",2,$1,$2);}
  | ID LP Args RP{$$=addNode("Exp",4,$1,$2,$3,$4);}
  | ID LP RP{$$=addNode("Exp",3,$1,$2,$3);}
  | Exp LB Exp RB{$$=addNode("Exp",4,$1,$2,$3,$4);}
  | Exp DOT ID{$$=addNode("Exp",3,$1,$2,$3);}
  | ID{$$=addNode("Exp",1,$1);}
  | INT{$$=addNode("Exp",1,$1);}
  | FLOAT{$$=addNode("Exp",1,$1);}
  | Exp ASSIGNOP error{yyerror("invalid token near \'=\'");}
  | Exp AND error{yyerror("invalid token near \'&&\'");}
  | Exp OR error{yyerror("invalid token near \'||\'");}
  | Exp RELOP error{yyerror("invalid token near \'RELOP\'");}
  | Exp PLUS error{yyerror("invalid token near \'+\'");}
  | Exp MINUS error{yyerror("invalid token near \'-\'");}
  | Exp STAR error{yyerror("invalid token near \'*\'");}
  | Exp DIV error{yyerror("invalid token near \'/\'");}
  | ID LP error RP{yyerror("invalid expression between \'[]\'");}
  | Exp LB error RB{yyerror("invalid expression between \'[]\'");}
  | MINUS error{yyerror("invalid token after \'-\'");}
  | NOT error{yyerror("invalid token after \'!\'");}
  | LP error RP{yyerror("invalid expression between \'[]\'");}
  ;
Args : Exp COMMA Args{$$=addNode("Args",3,$1,$2,$3);}
  | Exp{$$=addNode("Args",1,$1);}
  ;
%%
//#include "lex.yy.c"
#include"tree.h"
