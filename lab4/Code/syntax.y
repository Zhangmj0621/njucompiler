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
ExtDef : Specifier ExtDecList SEMI{
    $$=addNode("ExtDef",3,$1,$2,$3);
    //对每个varDec进行添加
    //printf("you have come tothe extdef\n");
    tNode* child=$2->child;
    while(child!=NULL)
    {
      //printf("child->name: %s\n",child->name);
      if(strcmp(child->name,"VarDec")==0)
      {
        int iffindBasic=findBasic(child);
        //printf("you have come to the iffindarray\n");
        int iffindArray=findArray(child);
        //printf("you have end the iffindarray\n");
        if(iffindBasic==1 || iffindArray==1)
          printf("Error type 3 at Line %d: Redefined variable \'%s\'.\n",yylineno,child->content);
        else if(iffindBasic==2 || iffindBasic==2)
          printf("Error type 15 at Line %d: Redefined field \'%s\'.\n",yylineno,child->content);
        else if(child->tag==1) newBasic(2,$1,child);
        else if(child->tag==4) newArray(2,$1,child);
        child=child->nextsibling;
      }
      else if(strcmp(child->name,"ExtDecList")==0)
      {
        child=child->child;
      }
      else child=child->nextsibling;
    }
  }
  | Specifier SEMI{$$=addNode("ExtDef",2,$1,$2);}
  | Specifier FunDec CompSt{
    $$=addNode("ExtDef",3,$1,$2,$3);
    newFunc(1,$1);
  }
  | Specifier error SEMI{yyerror("initialized or invalid global variable");}
  | error SEMI{yyerror("error 0");}
  | error Specifier SEMI{yyerror("error 2");}
  ;
ExtDecList : VarDec{$$=addNode("ExtDecList",1,$1);$$->type=$1->type;}
  | VarDec COMMA ExtDecList{$$=addNode("ExtDecList",3,$1,$2,$3);$$->type=$1->type;}
  ;

Specifier : TYPE{$$=addNode("Specifier",1,$1);$$->type=$1->type;}
  | StructSpecifier{$$=addNode("Specifier",1,$1);$$->type=$1->type;}
  ;
StructSpecifier : STRUCT OptTag LC DefList RC{
    $$=addNode("StructSpecifier",5,$1,$2,$3,$4,$5);
    //是否找到同名结构体或变量
    int iffindStruct=findIfStruct($2);
    int iffindBasic=findBasic($2);
    int iffindArray=findArray($2);
    if(iffindStruct==1 || iffindBasic==1 || iffindArray==1)
      printf("Error type 16 at Line %d: Duplicated name \'%s\'.\n",structopttagline[stackTop],$2->content);
    else if(strcmp($2->content,"{")!=0) newStruct(2,$$,$2);  //在这一部中对structspecifier的type赋值
    else
    {
      //Opttag->
      //此时仅需修改structspecifier的type
      newStructNoname(1,$$);
    }
    stackIndexTop--;
    //printf("the stacktop insturct is %d\n",stackTop);
    stackTop--;
  }
  | STRUCT Tag{
    $$=addNode("StructSpecifier",2,$1,$2);
    //发现此时的struct是使用而非定义
    stackTop--;
    maxStructNum--;
    stackIndexTop--;
    //如果tag未被定义，则输出错误17
    int iffindStruct=findIfStruct($2);
    if(iffindStruct==0)
    {
      printf("Error type 17 at Line %d: Undefined structure \'%s\'.\n",yylineno,$2->content);
    }
    else
    {
      $$->content=$2->content;
      $$->type=getStructByName($2->content)->type;
    }
  }
  ;
OptTag : {$$=addNode("OptTag",0,-1);}
  | ID {$$=addNode("OptTag",1,$1); }
  ;

Tag: ID{$$=addNode("Tag",1,$1);};

VarDec : ID {$$=addNode("VarDec",1,$1);$$->tag=1;}
  | VarDec LB INT RB{
    $$=addNode("VarDec",4,$1,$2,$3,$4);
    $$->content=$1->content;
    $$->tag=4;
    createNewArrayBody($3);
  }
  | VarDec LB error RB{yyerror("invalid expression between \'[]\'");}
  ;
FunDec : ID LP VarList RP{
    $$=addNode("FunDec",4,$1,$2,$3,$4);
    $$->content=$1->content;
    $$->tag=2;
    if(findFunc($1)==1)
      printf("Error type 4 at Line %d: Redefined function \'%s\'.\n",yylineno,$1->content);
    else newFunc(2,$1,$3);
  }
  | ID LP RP{
    $$=addNode("FunDec",3,$1,$2,$3);
    $$->content=$1->content;
    $$->tag=2;
    //printf("the funcid is %s\n",$$->content);
    if(findFunc($1)==1)
      printf("Error type 4 at Line %d: Redefined function \'%s\'.\n",yylineno,$1->content);
    else newFunc(2,$1,NULL);
  }
  | ID LP error RP{yyerror("invalid varlist");}
  | error LP VarList RP{yyerror("invalid function name");}
  | error LP RP{yyerror("invalid function name");}
  ;
VarList : ParamDec COMMA VarList{$$=addNode("VarList",3,$1,$2,$3);}
  | ParamDec{$$=addNode("VarList",1,$1);}
  ;
ParamDec : Specifier VarDec {
    $$=addNode("ParamDec",2,$1,$2);
    int iffindBasic=findBasic($2);
    int iffindArray=findArray($2);
    if(iffindBasic==1 || iffindArray==1)
      printf("Error type 3 at Line %d: Redefined variable \'%s\'.\n",yylineno,$2->content);
    else if($2->tag==1)
      newBasic(2,$1,$2);
    else if($2->tag==4)
      newArray(2,$1,$2);
  };

CompSt : LC DefList StmtList RC {$$=addNode("CompSt",4,$1,$2,$3,$4);}
  ;
StmtList : {$$=addNode("StmList",0,-1);}
  | Stmt StmtList{$$=addNode("StmtList",2,$1,$2);}
  ;
Stmt : Exp SEMI{$$=addNode("Stmt",2,$1,$2);}
  | CompSt{$$=addNode("Stmt",1,$1);}
  | RETURN Exp SEMI{
    $$=addNode("Stmt",3,$1,$2,$3);
    getFuncReturnType($2);
  }
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
Def : Specifier DecList SEMI{
    $$=addNode("Def",3,$1,$2,$3);
    //对每个varDec进行添加
    tNode* child=$2->child;
    //if(child==NULL) printf("the declist has no child\n");
    while(child!=NULL)
    {
      //printf("the declist indef child name is: %s\n",child->name);
      if(strcmp(child->name,"Dec")==0)
      {
        tNode* temp=child->child;
        int iffindBasic=findBasic(temp);
        int iffindArray=findArray(temp);
        //printf("child->tag: %d\n",child->tag);
        //if(temp->type_name!=NULL) printf("temp->type_name: $s\n",temp->type_name);
        if(iffindBasic==1 || iffindArray==1)
          printf("Error type 3 at Line %d: Redefined variable \'%s\'.\n",yylineno,temp->content);
        else if(iffindBasic==2 || iffindBasic==2)
          printf("Error type 15 at Line %d: Redefined field \'%s\'.\n",yylineno,temp->content);
        //如果有等号，徐判断类型是否一致
        else if(temp->type!=NULL && isSameType(temp->type,$1->type)!=0)
        {
          printf("Error type 5 at Line %d: Type mismatched for assignment.\n",yylineno);
        }
        else if(child->tag==1) newBasic(2,$1,temp);
        else if(child->tag==4) newArray(2,$1,temp);
        child=child->nextsibling;
      }
      else if(strcmp(child->name,"DecList")==0)
      {
        child=child->child;
      }
      else child=child->nextsibling;
    }
  }
  | Specifier error SEMI{yyerror("invalid variable or expected expression before \';\'");}
  | Specifier DecList error{yyerror("missing \';\' or invalid token");}
  ;
DecList : Dec{$$=addNode("DecList",1,$1);}
  | Dec COMMA DecList{$$=addNode("DecList",3,$1,$2,$3);$$->tag=$3->tag;}
  ;
Dec : VarDec{$$=addNode("Dec",1,$1);}
  | VarDec ASSIGNOP Exp{
    $$=addNode("Dec",3,$1,$2,$3);
    $$->content=$1->content;
    $$->tag=$1->tag;
    $1->type_name=$3->type_name;
    //printf("$$->type_name: %s\n",$$->type_name);
    $1->type=$3->type;
    if(stackTop!=-1)
    {
      printf("Error type 15 at Line %d: Illegal use of assignment.\n",yylineno);
    }
  }
  ;

Exp : Exp ASSIGNOP Exp{
    $$=addNode("Exp",3,$1,$2,$3);
    //如果出现一边变量未被定义，不做任何输出，错误信息前面以及输出
    if($1->type==NULL || $3->type==NULL)
    {
      //printf("%s type_name is zero\n",$1->content);
    }
    else
    {
      //printf("int Exp ASSIGNOP Exp,use Type_ to compare node's type,may cause fault!\n");
      // if(strcmp($1->type_name,$3->type_name)!=0)
      //如果在结构体中赋值，报15号错误
      if(stackTop!=-1)
      {
        printf("Error type 15 at Line %d: Illegal use of assignment.\n",yylineno);
      }
      if(isSameTypeByNode($1,$3) != 0)
        printf("Error type 5 at Line %d: Type mismatched for assignment.\n",yylineno);
      if(checkIfLeft($1)==0)
        printf("Error type 6 at Line %d: The left-hand side of an assignment must be a variable.\n",yylineno);
      // if(strcmp($1->type_name,$3->type_name)==0 && checkIfLeft($1)==1)
      if(isSameTypeByNode($1,$3) == 0 && checkIfLeft($1)==1)
      {
        $$->type_name=$1->type_name;
        $$->type=$1->type;
      }
    }
  }
  | Exp AND Exp{
    $$=addNode("Exp",3,$1,$2,$3);
    if($1->type==NULL || $3->type==NULL){}
    else if($1->type!=type_int || $3->type!=type_int)
      printf("Error type 7 at Line %d: Type mismatched for operands.\n",yylineno);
    else
    {
      $$->type_name="int";
      $$->type=type_int;
    }
  }
  | Exp OR Exp{
    $$=addNode("Exp",3,$1,$2,$3);
    if($1->type==NULL || $3->type==NULL){}
    else if($1->type!=type_int || $3->type!=type_int)
      printf("Error type 7 at Line %d: Type mismatched for operands.\n",yylineno);
    else
    {
      $$->type_name="int";
      $$->type=type_int;
    }
  }
  | Exp RELOP Exp{
    $$=addNode("Exp",3,$1,$2,$3);
    //printf("int Exp RELOP Exp,use Type_ to compare node's type,may cause fault!\n");
    if($1->type==NULL || $3->type==NULL){}
    // else if(strcmp($1->type_name,$3->type_name))
    else if(isSameTypeByNode($1,$3) != 0)
      printf("Error type 7 at Line %d: Type mismatched for operands.\n",yylineno);
    else
    {
      $$->type_name="int";
      $$->type=type_int;
    }
  }
  | Exp PLUS Exp{
    $$=addNode("Exp",3,$1,$2,$3);
    if($1->type==NULL || $3->type==NULL){}
    else if(isSameTypeByNode($1,$3) != 0)
      printf("Error type 7 at Line %d: Type mismatched for operands.\n",yylineno);
    else if($1->type!=type_int && $1->type!=type_float)
      printf("Error type 7 at Line %d: Type mismatched for operands.\n",yylineno);
    else
    {
      $$->type_name=$1->type_name;
      $$->type=$1->type;
    }
  }
  | Exp MINUS Exp{
    $$=addNode("Exp",3,$1,$2,$3);
    if($1->type==NULL || $3->type==NULL){}
    else if(isSameTypeByNode($1,$3) != 0)
      printf("Error type 7 at Line %d: Type mismatched for operands.\n",yylineno);
    else if($1->type!=type_int && $1->type!=type_float)
      printf("Error type 7 at Line %d: Type mismatched for operands.\n",yylineno);
    else
    {
      $$->type_name=$1->type_name;
      $$->type=$1->type;
    }
  }
  | Exp STAR Exp{
    $$=addNode("Exp",3,$1,$2,$3);
    if($1->type==NULL || $3->type==NULL){}
    else if(isSameTypeByNode($1,$3) != 0)
      printf("Error type 7 at Line %d: Type mismatched for operands.\n",yylineno);
    else if($1->type!=type_int && $1->type!=type_float)
      printf("Error type 7 at Line %d: Type mismatched for operands.\n",yylineno);
    else
    {
      $$->type_name=$1->type_name;
      $$->type=$1->type;
      //printf("the exp*exp type: %d  basic: %d\n",$$->type->kind,$$->type->u.basic);
    }
  }
  | Exp DIV Exp{
    $$=addNode("Exp",3,$1,$2,$3);
    if($1->type==NULL || $3->type==NULL){}
    else if(isSameTypeByNode($1,$3) != 0)
      printf("Error type 7 at Line %d: Type mismatched for operands.\n",yylineno);
    else if($1->type!=type_int && $1->type!=type_float)
      printf("Error type 7 at Line %d: Type mismatched for operands.\n",yylineno);
    else
    {
      $$->type_name=$1->type_name;
      $$->type=$1->type;
    }
  }
  | LP Exp RP{$$=addNode("Exp",3,$1,$2,$3);$$->type_name=$2->type_name;$$->type=$2->type;}
  | MINUS Exp{
    $$=addNode("Exp",2,$1,$2);
    if($2->type==NULL){}
    else if($2->type!=type_int && $2->type!=type_float)
      printf("Error type 7 at Line %d: Type mismatched for operands.\n",yylineno);
    else
    {
      $$->type_name=$2->type_name;
      $$->type=$2->type;
    }
  }
  | NOT Exp{
    $$=addNode("Exp",2,$1,$2);
    if($2->type==NULL){}
    else if($2->type!=type_int && $2->type!=type_float)
      printf("Error type 7 at Line %d: Type mismatched for operands.\n",yylineno);
    else
    {
      $$->type_name=$2->type_name;
      $$->type=$2->type;
    }
  }
  | ID LP Args RP{
    $$=addNode("Exp",4,$1,$2,$3,$4);
    //对普通变量使用（）调用，报错误11
    if(!findFunc($1) && (findBasic($1) || findArray($1)))
    {
      printf("Error type 11 at Line %d: \'%s\' is not a function.\n",yylineno,$1->content);
    }
    //函数调用时未定义，报错误2
    else if(!findFunc($1))
    {
      printf("Error type 2 at Line %d: Undefined function \'%s\'.\n",yylineno,$1->content);
    }
    //检查参数数量和类型,报错误9
    else if(checkType($1,$3)==0)
    {
      printf("Error type 9 at Line %d: Function parameter type error.\n",yylineno);
    }
    else
    {
      Func_* temp=getFunc($1);
      $$->type_name=temp->type_name;
      $$->type=temp->returnType;
    }
  }
  | ID LP RP{
    $$=addNode("Exp",3,$1,$2,$3);
    //对普通变量使用（）调用，报错误11
    if(!findFunc($1) && (findBasic($1) || findArray($1)))
    {
      printf("Error type 11 at Line %d: \'%s\' is not a function.\n",yylineno,$1->content);
    }
    //函数调用时未定义，报错误2
    else if(!findFunc($1))
    {
      printf("Error type 2 at Line %d: Undefined function \'%s\'.\n",yylineno,$1->content);
    }
    else
    {
      Func_* temp=getFunc($1);
      $$->type_name=temp->type_name;
      $$->type=temp->returnType;
    }
  }
  | Exp LB Exp RB{
    //printf("you have come to the exp->exp lb exp rb\n");
    $$=addNode("Exp",4,$1,$2,$3,$4);
    $$->content=$1->content;
    $$->tag=$1->tag;
    //printf("tag: %d\n",$$->tag);
    //对非数组变量采用[]报错误10
    if($$->tag!=4 && $$->tag>0)
    {
      printf("Error type 10 at Line %d: \'%s\' is not an array.\n",yylineno,$1->content);
    }
    //数组变量名未定义，报错误1
    else if($$->tag!=4)
    {
      //printf("$$->tag: %d\n",$$->tag);
      printf("Error type 1 at Line %d: Undefined variable \'%s\'.\n",yylineno,$1->content);
    }
    else
    {
      //中间不是int变量，报12号错误
      if($3->type==type_float)
      {
        printf("Error type 12 at Line %d: \'%s\' is not an integer.\n",yylineno,$3->content);
      }
      else
      {
        $$->type_name=$1->type_name;
        $$->type=$1->type->u.array.elem;
        if($$->type->kind!=ARRAY)
        {
          $$->tag=1;
        }
        //printf("you have exit the exp->exp LB Exp RB");
      }
    }
    
  }
  | Exp DOT ID{
    $$=addNode("Exp",3,$1,$2,$3);
    $$->content=$1->content;
    //获取exp所在的structnum
    if($1->type==NULL){}
    else
    {
      if($1->type->kind!=STRUCTURE)
      {
        printf("Error type 13 at Line %d: Illegal use of \'.\'.\n",yylineno);
      }
      else
      {
        //printf("Line: %d $1->type: %d\n",yylineno,$1->type->kind);
        //通过type里的structure去找$3->content
        FieldList_* it=getfield($1->type,$3->content);
        if(it==NULL){
          //没找到，报错误14
          printf("Error type 14 at Line %d: Non-existent field \'%s\'.\n",yylineno,$3->content);
        }
        else
        {
          $$->content=it->name;
          $$->type=it->type;
          if($$->type->kind==ARRAY){
            $$->tag=4;
          }
          else $$->tag=1;
        }
      }
    }
  }
  | ID{
    $$=addNode("Exp",1,$1);
    $$->content=$1->content;
    //如果变量未定义，输出错误1
    if(!findBasic($1) && !findArray($1))
    {
      printf("Error type 1 at Line %d: Undefined variable \'%s\'.\n",yylineno,$1->content);
      $$->tag=0;
    }
    else
    {
      if(findBasic($1))
      {
        //printf("you have find the basicvariable\n");
        Basic_* temp=getBasic($1);
        //printf("you have get the basic\n");
        $$->type=temp->type;
        $$->type_name=temp->type_name;
        $$->content=temp->name;
        $$->tag=1;
        //printf("you have left the exp->id\n");
      }
      if(findArray($1))
      {
        //printf("you have find the arryvariable\n");
        Array_* temp=getArray($1);
        $$->type_name=temp->type_name;
        $$->type=temp->type;
        $$->content=temp->name;
        $$->tag=4;
        //printf("$$->content: %s  $$->tag: %d\n",$$->content,$$->tag);
      }
    }
  }
  | INT{
    //printf("exp->int\n");
    $$=addNode("Exp",1,$1);
    //printf("exp->int\n");
    $$->tag=3;
    $$->type_name="int";
    $$->type=$1->type;
    $$->content=$1->content;
    //printf("you have success left the exp->int\n");
  }
  | FLOAT{
    $$=addNode("Exp",1,$1);
    $$->tag=3;
    $$->type_name="float";
    $$->type=$1->type;
    $$->content=$1->content;
  }
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
