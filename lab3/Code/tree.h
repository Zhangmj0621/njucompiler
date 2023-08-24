#pragma once
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

extern int yylineno;
extern char *yytext;

yyerror(char *msg);

#pragma region 自定义类型
typedef struct tType_ *Type;
typedef struct tBasic_ *Basic;
typedef struct tFunc_ *Func;
typedef struct tArray_ *Array;
// typedef struct tArrayBody_ *ArrayBody;
typedef struct tStruct_ *Struct;
typedef struct tFieldList_ *FieldList;

typedef struct Node
{
    int lineno;
    char *name;
    union
    {
        char *val;        // for TYPE and ID
        int type_int;     // for INT
        float type_float; // for FLOAT
    };
    Type type; // 数据类型，用来判断是否不同数据类型运算
    char *type_name;
    char *content; // 语义值
    int iflexcial; // 是否为词法单元，仅输出法分析树时有用
    int tag;       // 1变量 2函数 3常数 4数组 5结构体
    struct Node *child;
    struct Node *nextsibling;
} tNode;

typedef struct tType_
{
    enum
    {
        BASIC,
        ARRAY,
        STRUCTURE
    } kind;
    union
    {
        // 基本类型,0为int,1为float
        int basic;
        // 数据类型信息包括元素类型与数组大小构成
        struct
        {
            Type elem;
            int size;
        } array;
        // 结构体类型信息是一个链表
        struct
        {
            FieldList structbody;
            char *structName; // 链表名称
        } structure;

    } u;
} Type_;

// 变量符号表
typedef struct tBasic_
{
    char *name;      // 名称
    Type type;       // 变量类型
    char *type_name; // 类型名称
    int isStruct;    // 是否为结构体域
    int structNum;   // 如果是结构体域属于第几号结构体
    int structIndex; // 如果在结构体域名内,他是第几个
    struct tBasic_ *next;
} Basic_;

// 函数符号表
typedef struct tFunc_
{
    char *name;
    Type returnType;   // 返回值类型
    char *type_name;   // 返回值名称
    int varNum;        // 形参个数
    Type varType[10];  // 参数类型，参数个数不超过10个
    char *varName[10]; // 形参名称
    struct tFunc_ *next;
} Func_;

// 数组符号表
// typedef struct tArrayBody_
// {
//     int size;
//     struct tArrayBody_ *next;
// } ArrayBody_;

typedef struct tArray_
{
    char *name;
    Type type;       // 类型
    char *type_name; // 返回值名称
    int isStruct;    // 是否为结构体域
    int structNum;   // 如果是结构体域属于第几号结构体
    int structIndex; // 如果是结构体域中的是第几个结构体
    struct tArray_ *next;
} Array_;

// 结构体符号表
typedef struct tStruct_
{
    Type type;
    char *name;
    int structNum; // 这是第几个结构体
    struct tStruct_ *next;
} Struct_;

// 结构体链表
typedef struct tFieldList_
{
    char *name;
    Type type;
    struct tFieldList_ *next;
} FieldList_;

#pragma endregion
#pragma region 全局变量
int iftrue; // see if need to print the tree

tNode *firstNode; // the first Node,to be the program
Basic_ *basicHead;
Basic_ *basicTail;
Func_ *funcHead;
Func_ *funcTail;
Array_ *arrayHead;
Array_ *arrayTail;
// 用来获取数组类型变量的body部分
Type_ *arrayBodyHead;
Type_ *arrayBodyTail;
Struct_ *structHead;
Struct_ *structTail;

Type type_int;
Type type_float;

// 目前的函数返回值类型，用于在构建函数时判断是否一致
Type funcReturnType[10];
int returnTypeNum;
// 用于记录返回值的行数，若返回值类型不一致输出八号错误时有用
int returnlineno[10];
Type funcReturnTypePlus;
// 目前调用函数实际参数数量
int funcVarNum;
// 目前调用函数的实际参数类型
Type varType[10];

// 存放结构体域，目前假设结构体嵌套不超过10层
int structNumStack[10];
// 栈顶
int stackTop;
// 目前结构体总数量
int maxStructNum;
// 目前变量数量
int structIndexStack[10];
int stackIndexTop;
// 结构体名称所在的行
int structopttagline[10];

#pragma endregion
#pragma region 函数
tNode *addNode(char *name, int num, ...);
void dfs(tNode *head, int level);

// 插入新变量定义至变量符号表
void newBasic(int num, ...);
// 判断变量名字是否重复,找到返回1，找到了同结构体域名返回2
int findBasic(tNode *);
// 获取变量
Basic getBasic(tNode *);
// 获取变量类型
Type getBasicType(tNode *);
// 是否在第num个结构体域内又叫做name的变量
int iffindBasicBySName(int num, char *name);
// 获取在第num个结构体域内叫做name的变量
Basic getBasicBySName(int num, char *name);
// 根据名称获取变量
Basic getBasicByName(char *name);

// 插入新函数至函数符号表中
void newFunc(int num, ...);
// 判断是否能找到函数名
int findFunc(tNode *);
// 获取函数
Func getFunc(tNode *);
// 获取形参列表
void getDeType(tNode *);
// 获取实参
void getReType(tNode *);
// 检查形参实参是否类型一致,一致返回1
int checkType(tNode *funcId, tNode *args);
// 获取函数返回值
void getFuncReturnType(tNode *);

// 插入新数组至数组符号表中
void newArray(int num, ...);
// 判断是否能找到数组名
int findArray(tNode *);
// 创建新的数组类型变量体
void createNewArrayBody(tNode *tnode);
// 获取数组
Array_ *getArray(tNode *);
// 是否在第num个结构体域内又叫做name的变量
int iffindArrayBySName(int num, char *name);
// 获取在第num个结构体域内叫做name的变量
Array_ *getArrayBySName(int num, char *name);

// 插入新结构体至结构体符号表中
void newStruct(int num, ...);
// 不存在名字的结构体
void newStructNoname(int num, ...);
// 判断是否能找到结构体名
int findIfStruct(tNode *);
// 获取结构体
Struct_ *getStruct(tNode *);
// 通过名称获取结构体
Struct getStructByName(char *name);
// 获取结构体参数
FieldList_ *getfield(Type_ *structtype, char *name);
// 判断是否为左值表达式
int checkIfLeft(tNode *);

// 初始化符号表
void initSymbolList();
// 根据Type判断结点的类型是否相同,相同返回0,不同返回1
int isSameTypeByNode(tNode *n1, tNode *n2);
int isSameType(Type t1, Type t2);

/*
------------------------------------------------------------
之前我就觉得代码结构很奇怪，实验三要求预先往符号表添加函数时我才发现，
现在符号表添加符号的代码直接内嵌在语法树里，高度依赖node，根本没有写一个专门的接口，
代码耦合程度太高了。。。
------------------------------------------------------------
*/

// 符号表预先添加内置函数
void addFunc(Func_ func);
// read和write使源程序可以与控制台进行交互
// 符号表预先添加read函数，无参数，返回值为int
void addFuncRead();
// 符号表预先添加write函数，参数为int（读入的整数值)，返回值为int（固定为0）
void addFuncWrite();
#pragma endregion