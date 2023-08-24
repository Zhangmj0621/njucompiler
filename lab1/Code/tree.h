#pragma once
#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"common.h"

extern int yylineno;
extern char* yytext;

yyerror(char *msg);

typedef struct Node{
    int lineno;
    char* name;
    union{
        char* val;  //for TYPE and ID
        int type_int;//for INT
        float type_float;//for FLOAT
    };
    Type type;     //数据类型，用来判断是否不同数据类型运算
    char* content;  //语义值
    int iflexcial;  //是否为词法单元，仅输出法分析树时有用
    struct Node* child;
    struct Node* nextsibling;
}tNode;

int iftrue;    //see if need to print the tree

tNode* firstNode;   //the first Node,to be the program
//tNode* nodelist[1000];
//int* ifchildnode[1000];
//int nodenum;

//int getnodelistId(tNode* node);


tNode* addNode(char* name,int num,...);
void dfs(tNode* head,int level);

typedef struct Type_* Type;
typedef struct FieldList_* FieldList;

struct Type_
{
    enum {BASIC,ARRAY,STRUCTURE} kind;
    union {
        //基本类型,0为int,1为float
        int basic;
        //数据类型信息包括元素类型与数组大小构成
        struct{
            Type elem;
            int size;
        }array;
        //结构体类型信息是一个链表
        FieldList structure;
    }u;
    
};

//结构体链表
struct FieldList_
{
    char* name;
    Type type;
    FieldList next;
};

//变量符号表
typedef struct Basic_* Basic;
struct Basic_
{
    char* name; //名称
    Type type;  //变量类型
    Basic next;
};

//插入新变量定义至变量符号表
void newBasic(int num,...);

//判断变量名字是否重复,找到返回1，没找到返回0
int findBasic(tNode*);

//函数符号表
typedef struct Func_* Func;
struct Func_
{
    char* name;
    Type returnType;    //返回值类型
    int varNum; //参数个数
    Type* varType;  //参数类型
    Func next;
};

//插入新函数至函数符号表中
void newFunc(int num,...);

//判断是否能找到函数名
int findFunc(tNode*);

//数组符号表
typedef struct Array_* Array;
struct Array_
{
    char* name;
    Type type;
    Array next;
};

//插入新数组至数组符号表中
void newArray(int num,...);

//判断是否能找到数组名
int findArray(tNode*);

//结构体符号表
typedef struct Struct_* Struct;
struct Struct_
{
    char* name;
    Type type;
    Struct next;
};

//插入新结构体至结构体符号表中
void newStruct(int num,...);

//判断是否能找到结构体名
int findStruct(tNode*);