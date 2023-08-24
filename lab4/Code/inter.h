#pragma once
#include "tree.h"

#pragma region 类型定义
typedef struct Node *pNode;
typedef struct _operand *pOperand;
typedef struct _interCode *pInterCode;
typedef struct _interCodes *pInterCodes;
typedef struct _arg *pArg;
typedef struct _argList *pArgList;
typedef struct _interCodeList *pInterCodeList;

// 操作数
typedef struct _operand
{
    enum
    {
        O_VARIABLE,
        O_CONSTANT,
        O_ADDRESS,
        O_LABEL,
        O_FUNCTION,
        O_RELOP
    } kind;
    union
    {
        int var_no;
        int value;
        char *name;
        int temp_no;
        int label_no;
        char *relop;
    } u;
    Type type;
} Operand;

// 中间代码
typedef struct _interCode
{
    enum
    {
        I_ASSIGN,
        I_ADD,
        I_SUB,
        I_MUL,
        I_DIV,
        I_LABEL,
        I_FUNCTION,
        I_GOTO,
        I_IF_GOTO,
        I_RETURN,
        I_DEC,
        I_ARG,
        I_CALL,
        I_PARAM,
        I_READ,
        I_WRITE,
        I_ARG_ADDR,
        I_GET_ADDR,
        I_READ_ADDR,
        I_WRITE_ADDR
    } kind;
    union
    {
        struct
        {
            pOperand left, right;
        } assign;
        struct
        {
            pOperand result, op1, op2;
        } binop;
        struct
        {
            pOperand op;
        } sinop;
        struct
        {
            pOperand op1, op2, relop, label;
        } if_goto;
        struct
        {
            pOperand op;
            int size;
        } dec;
        struct
        {
            pOperand op;
        } arg;
        struct
        {
            pOperand op;
            char *func_name;
        } call;
        struct
        {
            pOperand op;
        } param;
        struct
        {
            pOperand op;
        } read;
        struct
        {
            pOperand op;
        } write;
    } u;
} InterCode;

// 中间代码列表结点
typedef struct _interCodes
{
    pInterCode code;
    pInterCodes prev, next;
} InterCodes;

// 中间代码列表
typedef struct _interCodeList
{
    pInterCodes head, tail;
    Type arrType;
    int norVarCnt;
    int tmpVarCnt;
    int labelCnt;
} InterCodeList;

// 参数列表结点
typedef struct _arg
{
    pOperand op;
    pArg prev, next;
} Arg;

// 参数列表
typedef struct _argList
{
    pArg head, tail;
} ArgList;

#pragma endregion
#pragma region 变量声明
#define MAX_NAME_LEN 32
// 中间代码列表
extern pInterCodeList interCodeList;
#pragma endregion
#pragma region 函数声明
//@param kind 操作数类型
//@param ...  操作数name/操作数value
pOperand newOperand(int kind, ...);
void deleteOperand(pOperand op);
void setOperand(pOperand op, int kind, ...);
void setOperandType(pOperand op, Type tp);
void setWidth(pOperand op, int width);
void printOp(FILE *fp, pOperand op);

// 中间代码
pInterCode newInterCode(int kind, ...);
void deleteInterCode(pInterCode code);
void printInterCode(FILE *fp, pInterCodeList list);

// 中间代码列表
pInterCodes newInterCodes(pInterCode code);
pInterCodeList newInterCodeList();
void deleteInterCodes(pInterCodes codes);
void deleteInterCodeList(pInterCodeList list);
void addInterCode(pInterCodeList list, pInterCodes codes);

// 参数列表
pArg newArg(pOperand op);
pArgList newArgList();
void deleteArg(pArg arg);
void deleteArgList(pArgList list);
void addArg(pArgList list, pArg arg);

// 中间代码生成
pOperand newTmp();
pOperand newLabel();
int getSize(Type type);
Type getElement(Type type);
void genInterCodes(pNode node);
void genInterCode(int kind, ...);
void translateExp(pNode node, pOperand place);
void translateArgs(pNode node, pArgList argList);
void translateCond(pNode node, pOperand labelTrue, pOperand labelFalse);
void translateVarDec(pNode node, pOperand place);
void translateDec(pNode node);
void translateDecList(pNode node);
void translateDef(pNode node);
void translateDefList(pNode node);
void translateCompSt(pNode node);
void translateStmt(pNode node);
void translateStmtList(pNode node);
void translateFunDec(pNode node);
void translateExtDef(pNode node);
void translateExtDefList(pNode node);
#pragma endregion