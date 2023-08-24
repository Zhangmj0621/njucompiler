#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#pragma region 类型定义
// 描述程序的数据结构
typedef struct _operand *pOperand;
typedef struct _interCode *pInterCode;
typedef struct _basicBlock *pBasicBlock;
typedef struct _dAGNode *pDAGNode;
typedef struct _blockState *pBlockState;

// 操作数（变量，临时变量，标记，函数）
typedef struct _operand
{
    enum
    {
        O_VARIABLE,
        O_TEMP_VAR,
        O_CONSTANT,
        O_LABEL,
        O_FUNCTION,
        O_GET_ADDR,
        O_GET_VAL
    } kind;
    union
    {
        int no;        // 临时变量的编号，变量的编号，标记的编号
        int value;     // 常量的值
        char name[32]; // 函数的名字
        pOperand op;   // 取地址和解引用指向的操作数
    };
    int version; // 版本号，用于基本块内部优化
} Operand_;

// 单条指令
typedef struct _interCode
{
    enum
    {
        I_LABEL,
        I_FUNC,
        I_ASSIGN,
        I_PLUS,
        I_SUB,
        I_MUL,
        I_DIV,
        I_TO_MEM,
        I_GOTO,
        I_IF_GOTO,
        I_RETURN,
        I_DEC,
        I_ARG,
        I_CALL,
        I_PARAM,
        I_READ,
        I_WRITE,
        I_NULL
    } kind;
    pOperand ops[3]; // 操作数指针数组
    union
    {
        char relop[32];
        int size;
    };               // 额外信息：IF_GOTO_IR中的比较符号，DEC_IR中的数值大小
    pInterCode prev; // 前一条指令
    pInterCode next; // 后一条指令
} InterCode_;

// 基本块
typedef struct _basicBlock
{
    int no;                // 基本块编号
    int dead;              // 不可达为1，可达为0
    pInterCode interCodes; // 基本块内部指令
    pBasicBlock next[2];   // 后驱基本块，基本块后驱应该至多只有两个
    int preNum;            // 前驱数量
    pBasicBlock *prev;     // 前驱基本块，数量不确定
    char func[32];         // 所属函数的名字
} BasicBlock_;

// 描述基本块内部语句结构的数据结构

// DAG图的节点
typedef struct _dAGNode
{
    enum
    {
        N_ASSIGN,
        N_PLUS,
        N_SUB,
        N_MUL,
        N_DIV,
        N_LEAF
    } kind;               // 节点的类型
    pOperand op;          // 该节点代表的语句修改的操作数
    pDAGNode children[2]; // LEAF没有子节点，ASSIGN有一个子节点，剩余四种有两个子节点
} DAGNode_;

// 描述基本块状态的数据结构

typedef struct _blockState
{
    int size;
    int *in;
    int *out;
    int *inValue; // 常量传播中对应的常量
    int *outValue;
} BlockState_;

#pragma endregion
#pragma region 变量声明
extern pBasicBlock *blocks; // 基本块数组，初始容量设为64
extern int blocksCapacity;  // 基本块数组容量
extern int blocksSize;      // 基本块数组实际大小
extern pBlockState *states;
#pragma endregion

#pragma region 函数声明

// void readInput(char *filename);
// void optimize();
// void printOperand(pOperand op, FILE *fp);
// void writeOutput(char *filename);

void initblocks();
pInterCode getNullInterCode();                                // 获取一条空指令
pBasicBlock createBlock(char *func);                          // 新建基本块
void addBlock(pBasicBlock block);                             // 将基本块加入基本块数组
void insertInterCode(pInterCode code, pInterCode interCodes); // 向指令链表尾部插入多条指令组成的双向链表
void deleteInterCode(pInterCode code);                        // 从指令链表中删除指令
void fillOperand(char *name, pOperand op);                    // 根据字符串填充操作数信息（限五种操作数）
void readInput(char *filename);                               // 读取输入

int opEqual(pOperand op1, pOperand op2, int flag);                                         // flag为0，里外层都不比较版本号；flag为1，里外层都比较版本号；flag为2，外层不比较版本号，里层比较版本号
pDAGNode searchDAGNode(pOperand op, pDAGNode *nodes, int nodesSize, int flag);             // 在DAG图数组中搜寻有没有已经代表该操作数（且ver最大）的节点
void addDAGNode(pDAGNode node, pDAGNode **nodes, int *nodesCapacity, int *nodesSize);      // 将DAG图节点加入DAG图节点数组
pDAGNode createDAGLeafNode(pOperand op);                                                   // 新建DAG图叶子节点
void createDAGNode(pInterCode code, pDAGNode **nodes, int *nodesCapacity, int *nodesSize); // 新建DAG图节点
pOperand getValue(int num);                                                                // 创建常量

void optimizePLUSIR(pInterCode code);   // 优化加法
void optimizeSUBIR(pInterCode code);    // 优化减法
void optimizeMULIR(pInterCode code);    // 优化乘法
void optimizeDIVIR(pInterCode code);    // 优化除法
void optimizeIFGOTOIR(pInterCode code); // 优化有条件跳转

void replaceOp(pOperand src, pOperand dest, pInterCode codes);                                  // 对中间代码进行操作数代换
void deleteOp(pOperand src, pInterCode codes);                                                  // 删除对特定操作数赋值的中间代码
void eliminateSubExp(pInterCode codes, pDAGNode **nodes, int *nodesCapacity, int *nodesSize);   // 公共子表达式消除
void eliminateDeadCode(pInterCode codes, pDAGNode **nodes, int *nodesCapacity, int *nodesSize); // 无用代码消除
void foldConstant(pInterCode codes, pDAGNode **nodes, int *nodesCapacity, int *nodesSize);      // 常量折叠
void optimizeBlock(pBasicBlock block);                                                          // 基本块内局部优化

void getBeignEnd(char *func, int *begin, int *end); // 获取函数对应基本块的起止范围
void genDataFlow(char *func);                       // 确定特定函数内部基本块之间的前驱后继关系
void propagateConstantg(int num);                   // 常量传播的控制流约束函数
int propagateConstantf(int num);                    // 常量传播的传递函数
void propagateConsantr(int num);                    // 根据基本块的in信息进行常量代换
void propagateConsant(char *func);                  // 常量传播
void deleteDeadCodeg(int num);                      // 无用代码消除的控制流约束函数
int deleteDeadCodef(int num);                       // 无用代码消除的传递函数
int deleteDeadCoder(int num);                       // 根据基本块的out信息进行死代码消除
void deleteDeadCode(char *func);                    // 无用代码消除
void strengthReduction(char *func);                 // 归纳变量强度削减

void optimizeFunc(char *func); // 函数内全局优化
void optimize();               // 优化管道

void printOperand(pOperand op, FILE *fp);              // 向指定文件中打印操作数
void printInterCodes(pInterCode interCodes, FILE *fp); // 向指定文件中打印中间代码
void writeOutput(char *filename);                      // 打印输出
#pragma endregion