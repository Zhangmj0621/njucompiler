#include "tree.h"

// int getnodelistId(tNode* node)
// {
//     for(int i=0;i<nodenum;i++)
//     {
//         if(nodelist[i]==node)
//             return i;
//     }
//     return -1;  //find error
// }

tNode *addNode(char *name, int num, ...)
{
    tNode *newNode = (tNode *)malloc(sizeof(tNode));
    tNode *temp;
    if (!newNode)
    {
        // create error
        yyerror("create treeNode error");
        exit(0);
    }
    newNode->name = name;
    newNode->iflexcial = 0;
    if (strcmp(name, "Program") == 0)
        firstNode = newNode;
    // create valist
    va_list list;

    // start the valist
    va_start(list, num);

    if (num > 0)
    {
        temp = va_arg(list, tNode *); // the first childNode
        newNode->child = temp;
        newNode->lineno = temp->lineno;

        // 如果只有一个孩子节点，传递语义值
        if (num == 1)
        {
            // printf("name: %s you have only one child\n",name);
            newNode->content = temp->content;
            newNode->tag = temp->tag;
            // printf("addnode you have success left the one child addnode\n");
        }
        for (int i = 0; i < num - 1; i++)
        {
            temp->nextsibling = va_arg(list, tNode *);
            temp = temp->nextsibling;
        }
    }
    else
    {
        newNode->child = NULL;
        newNode->lineno = va_arg(list, int);
        newNode->iflexcial = 1;
        if (strcmp(newNode->name, "TYPE") == 0)
        {
            // 设置类型
            newNode->type = strcmp(yytext, "int") == 0 ? type_int : type_float;

            newNode->val = (char *)malloc(strlen(yytext));
            strcpy(newNode->val, yytext);
            // 同时存入语义content中
            newNode->content = (char *)malloc(strlen(yytext));
            strcpy(newNode->content, yytext);
        }
        if (strcmp(newNode->name, "ID") == 0) // save into val
        {
            // printf("you have come to the type");
            newNode->val = (char *)malloc(strlen(yytext));
            strcpy(newNode->val, yytext);
            // 同时存入语义content中
            newNode->content = (char *)malloc(strlen(yytext));
            strcpy(newNode->content, yytext);
            // printf("id is %s",yytext);
        }
        // func atoi can not transfer OCT and HEX to DEC
        else if (strcmp(newNode->name, "INT") == 0)
        {
            // printf("you have come to the int");
            newNode->type_int = stoi(yytext);
            newNode->content = (char *)malloc(strlen(yytext));
            strcpy(newNode->content, yytext);
            // 将数据类型定义为int
            newNode->type = type_int;
            newNode->type_name = "int";
        }
        else if (strcmp(newNode->name, "FLOAT") == 0)
        {
            newNode->type_float = stof(yytext);
            newNode->content = (char *)malloc(strlen(yytext));
            strcpy(newNode->content, yytext);
            // 将数据类型定义为float
            newNode->type = type_float;
            newNode->type_name = "float";
        }
        else
        {
            char *str = (char *)malloc(sizeof(char) * 40);
            strcpy(str, yytext);
            newNode->content = str;
        }
    }
    return newNode;
}

void dfs(tNode *head, int level)
{
    if (head == NULL)
    {
        return;
    }
    if (head->lineno > 0)
    {
        for (int i = 0; i < level; i++)
        {
            printf("  ");
        }
        printf("%s", head->name);
        if (strcmp(head->name, "TYPE") == 0 || strcmp(head->name, "ID") == 0) // save into val
        {
            printf(": %s", head->val);
        }
        else if (strcmp(head->name, "INT") == 0)
        {
            printf(": %d", head->type_int);
        }
        else if (strcmp(head->name, "FLOAT") == 0)
        {
            printf(": %f", head->type_float);
        }
        else if (head->iflexcial == 0)
        {
            printf(" (%d)", head->lineno);
        }
        printf("\n");
    }
    dfs(head->child, level + 1);
    dfs(head->nextsibling, level);
    return;
}

yyerror(char *msg)
{
    iftrue = 0;
    printf("Error type B at Line %d: %s\n", yylineno, msg);
}

void newBasic(int num, ...)
{
    // 应该为两个变量，第一个type，第二个名称
    // type保存在Type对象中，name保存在content（val)中
    // printf("you have come to the newBasic\n");
    va_list valist;
    va_start(valist, num);
    tNode *temp;
    temp = va_arg(valist, tNode *);
    if (temp->type == NULL)
    {
        return;
    }

    Basic_ *basic = (Basic_ *)malloc(sizeof(Basic_));
    if (stackTop != -1)
    {
        basic->isStruct = 1;
        basic->structNum = structNumStack[stackTop];
        structIndexStack[stackIndexTop]++;
        basic->structIndex = structIndexStack[stackIndexTop];
    }
    else
    {
        basic->isStruct = 0;
        basic->structNum = 0;
        basic->structIndex = 0;
    }

    basic->type = temp->type;

    basic->type_name = temp->content;
    temp = va_arg(valist, tNode *);
    basic->name = temp->content;
    basic->next = NULL;

    // 加入链表中
    basicTail->next = basic;
    basicTail = basic;
}

int findBasic(tNode *tnode)
{
    // 遍历链表是否存在找到与tnode content名称一样的项
    Basic_ *it = basicHead->next;
    // if (it == NULL)
    // printf("the basichead is null\n");
    while (it != NULL)
    {
        // printf("FindBasic: tnode->content: %s, it->name: %s\n", tnode->content, it->name);
        if (strcmp(tnode->content, it->name) == 0) // 找到名称一致
        {
            // 当前变量为结构体域，观察是否同结构体域
            if (stackTop != -1)
            {
                // 同结构体域报错15，此时返回2
                if (it->isStruct == 1 && it->structNum == structNumStack[stackTop])
                {
                    // printf("Error type 15 at Line %d: Redefined field \'%s\'.",yylineno,it->name);
                    // printf("you have find the %s in basictable\n", tnode->content);
                    return 2;
                }
            }
            else
            {
                // 同为变量时报错误三，此时返回1
                if (it->isStruct == 0)
                {
                    // printf("Error type 3 at Line %d: Redefined variable \'i\'.",yylineno,it->name);
                    // printf("you have find the %s in basictable\n", tnode->content);
                    return 1;
                }
            }
        }
        it = it->next;
    }
    // printf("you have not find the %s in basictable\n", tnode->content);
    return 0;
}

Type getBasicType(tNode *tnode)
{
    Basic_ *it = basicHead->next;
    while (it != NULL)
    {
        if (strcmp(tnode->content, it->name) == 0)
        {
            return it->type;
        }
        it = it->next;
    }
    return NULL;
}

Basic getBasic(tNode *tnode)
{ // 遍历链表是否存在找到与tnode content名称一样的项
    Basic_ *it = basicHead->next;
    // if (it == NULL)
    // printf("the basichead is null\n");
    while (it != NULL)
    {
        // printf("FindBasic: tnode->content: %s, it->name: %s\n", tnode->content, it->name);
        if (strcmp(tnode->content, it->name) == 0) // 找到名称一致
        {
            // 当前变量为结构体域，观察是否同结构体域
            if (stackTop != -1)
            {
                // 同结构体域报错15，此时返回2
                if (it->isStruct == 1 && it->structNum == structNumStack[stackTop])
                {
                    // printf("Error type 15 at Line %d: Redefined field \'%s\'.",yylineno,it->name);
                    // printf("you have find the %s in basictable\n", tnode->content);
                    return it;
                }
            }
            else
            {
                // 同为变量时报错误三，此时返回1
                if (it->isStruct == 0)
                {
                    // printf("Error type 3 at Line %d: Redefined variable \'i\'.",yylineno,it->name);
                    // printf("you have find the %s in basictable\n", tnode->content);
                    return it;
                }
            }
        }
        it = it->next;
    }
    // printf("you have not find the %s in basictable\n", tnode->content);
    return NULL;
}

int iffindBasicBySName(int num, char *name)
{
    Basic_ *it = basicHead->next;
    while (it != NULL)
    {
        if (it->structNum == num && strcmp(name, it->name) == 0)
            return 1;
        it = it->next;
    }
    return 0;
}

Basic getBasicBySName(int num, char *name)
{
    Basic_ *it = basicHead->next;
    while (it != NULL)
    {
        if (it->structNum == num && strcmp(name, it->name) == 0)
            return it;
        it = it->next;
    }
    return NULL;
}

Basic getBasicByName(char *name)
{
    Basic_ *it = basicHead->next;
    while (it != NULL)
    {
        if (strcmp(name, it->name) == 0)
            return it;
        it = it->next;
    }
    return NULL;
}

// 要改判断返回值是否类型等价，参数为num，ID，VarList
void newFunc(int num, ...)
{
    // printf("you have come to the newfunc");
    va_list valist;
    va_start(valist, num);
    // 当只有一个参数的时候，保存函数返回值并与应该的函数返回值进行比较判断是否相等
    if (num == 1)
    {
        if (funcTail->name == NULL)
            return;
        tNode *temp;
        temp = va_arg(valist, tNode *);
        funcTail->type_name = temp->content;
        // 可以为int,float,定义的结构体
        funcTail->returnType = temp->type;
        // printf("funcreturntype=NULL,exit\n");
        // printf("funcTail->content: %s \n", funcTail->name);
        // printf("returntypenum is %d\n", returnTypeNum);
        for (int i = 0; i < returnTypeNum; i++)
        {
            // printf("funcTail->type.kind: %d   funcTail->type.basic: %d\n", funcTail->returnType->kind, funcTail->returnType->u.basic);
            // printf("funcTail->type_name: %s  funcreturntypekind: %d funcreturnTYpe: %d\n", funcTail->type_name, funcReturnType[i]->kind, funcReturnType[i]->u.basic);
            if (isSameType(funcTail->returnType, funcReturnType[i]) != 0) // 返回值类型不相同，报8号错误
            {
                printf("Error type 8 at Line %d: Type mismatched for return.\n", returnlineno[i]);
            }
        }
        // 分配下一个节点
        Func newFunc = (Func)malloc(sizeof(Func_));
        funcTail->next = newFunc;
        funcTail = newFunc;

        returnTypeNum = 0;
    }
    else if (num == 2)
    {
        tNode *temp;
        temp = va_arg(valist, tNode *);
        funcTail->name = temp->content;
        // printf("the functail->name: %s\n",funcTail->name);
        temp = va_arg(valist, tNode *);
        funcTail->varNum = 0;
        getDeType(temp);
    }
}

// 修改获取参数方式从type_name改为type
void getDeType(tNode *tnode)
{
    // printf("you have come to the getdetype");
    if (tnode != NULL)
    {
        if (strcmp(tnode->name, "ParamDec") == 0)
        {
            Basic_ *temp1 = getBasic(tnode->child->nextsibling);
            Array_ *temp2 = getArray(tnode->child->nextsibling);
            if (temp1 != NULL)
            {
                funcTail->varType[funcTail->varNum] = temp1->type;
            }
            else if (temp2 != NULL)
            {
                funcTail->varType[funcTail->varNum] = temp2->type;
            }
            funcTail->varName[funcTail->varNum] = tnode->child->nextsibling->content;
            funcTail->varNum++;
            return;
        }
        tNode *temp = tnode->child;
        while (temp != NULL)
        {
            getDeType(temp);
            temp = temp->nextsibling;
        }
    }
    return;
}

int findFunc(tNode *tnode)
{
    Func_ *it = funcHead->next;
    while (it != NULL && it->name != NULL)
    {
        // printf("the findfunc: it-name: %s tnode->content: %s\n", it->name, tnode->content);
        if (strcmp(it->name, tnode->content) == 0)
        {
            // printf("you have find the func\n");
            return 1;
        }
        it = it->next;
    }
    // printf("you have not find the func\n");
    return 0;
}

Func getFunc(tNode *tnode)
{
    Func_ *it = funcHead->next;
    while (it != NULL && it->name != NULL)
    {
        if (strcmp(it->name, tnode->content) == 0)
        {
            return it;
        }
        it = it->next;
    }
    return NULL;
}

void getReType(tNode *tnode)
{
    if (tnode != NULL)
    {
        if (strcmp(tnode->name, "Exp") == 0)
        {
            varType[funcVarNum] = tnode->type;
            funcVarNum++;
            return;
        }
        tNode *temp = tnode->child;
        while (temp != NULL)
        {
            getReType(temp);
            temp = temp->nextsibling;
        }
    }
    return;
}

//**要改为结构等价！！！
int checkType(tNode *funcId, tNode *args)
{
    funcVarNum = 0;
    getReType(args);
    Func_ *it = funcHead->next;
    while (it != NULL && it->name != NULL)
    {
        if (strcmp(it->name, funcId->content) == 0)
        {
            break;
        }
        it = it->next;
    }
    if (it->varNum != funcVarNum)
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < it->varNum; i++)
        {
            if (it->varType[i] != NULL && varType[i] != NULL && isSameType(varType[i], it->varType[i]) == 0)
                continue;
            else
                return 0;
        }
    }
    return 1;
}

// ！！要改为type判断而非type_name
void getFuncReturnType(tNode *tnode)
{
    if (tnode->type == NULL)
    {
        return;
    }
    funcReturnType[returnTypeNum] = tnode->type;
    returnlineno[returnTypeNum] = yylineno;
    returnTypeNum++;
    return;
}

void createNewArrayBody(tNode *tnode)
{
    Type_ *temp = (Type_ *)malloc(sizeof(Type_));
    if (tnode != NULL)
    {
        if (tnode->type == type_float) // 此时中括号内为浮点数，报错但一样添加
        {
            printf("Error type 12 at Line %d: \'%f\' is not an integer.\n", yylineno, tnode->type_float);
        }
        else if (tnode->type == type_int) // 输入正确，添加数组
        {
            temp->kind = ARRAY;
            temp->u.array.size = tnode->type_int;
            arrayBodyTail->u.array.elem = temp;
            temp->u.array.elem = NULL;
            arrayBodyTail = temp;

            // 使用Type
            // Type t = varDec->type;
            // while (t != NULL)
            // {
            //     t = t->u.array.elem;
            // }
            // t = (Type)malloc(sizeof(Type_));
            // t->kind = ARRAY;
            // t->u.array.size = tnode->type_int;
            // t->u.array.elem = NULL;
        }
    }
}

void newArray(int num, ...)
{
    va_list valist;
    va_start(valist, num);
    // 收取到的参数第一个为类型，第二个参数为数组变量名称
    Array_ *array = (Array_ *)malloc(sizeof(Array_));
    if (stackTop != -1)
    {
        array->isStruct = 1;
        array->structNum = structNumStack[stackTop];
        structIndexStack[stackIndexTop]++;
        array->structIndex = structIndexStack[stackIndexTop];
    }
    else
    {
        array->isStruct = 0;
        array->structNum = 0;
        array->structIndex = 0;
    }
    tNode *temp;
    temp = va_arg(valist, tNode *);
    // 取得specifier a[]...[]中的specifier 的type，将其连到最后一个type上
    Type t1 = temp->type;
    array->type_name = temp->content;
    temp = va_arg(valist, tNode *);
    // 获取数组变量名字
    array->name = temp->content;

    // Type t2 = temp->type;
    // while (t2->u.array.elem != NULL)
    // {
    //     t2 = t2->u.array.elem;
    // }
    // t2->u.array.elem = t1;

    array->next = NULL;
    // 将数组体接上
    array->type = arrayBodyHead->u.array.elem;
    // 将最后一个数组的type置为从specifier中得到的
    arrayBodyTail->u.array.elem = t1;
    // 将数组体部分恢复
    arrayBodyHead->u.array.elem = NULL;
    arrayBodyTail = arrayBodyHead;

    // 加入链表中
    arrayTail->next = array;
    arrayTail = array;
}

int findArray(tNode *tnode)
{
    // 遍历链表是否存在找到与tnode content名称一样的项
    Array_ *it = arrayHead->next;
    // if(it==NULL) printf("the basichead is null\n");
    while (it != NULL)
    {
        // printf("Arraytable: tnode->content: %s, it->name: %s\n",tnode->content,it->name);
        if (strcmp(tnode->content, it->name) == 0) // 找到名称一致
        {
            // 当前变量为结构体域，观察是否同结构体域
            if (stackTop != -1)
            {
                // 同结构体域报错15，此时返回2
                if (it->isStruct == 1 && it->structNum == structNumStack[stackTop])
                {
                    // printf("Error type 15 at Line %d: Redefined field \'%s\'.",yylineno,it->name);
                    // printf("you have find the %s in arraytable\n",tnode->content);
                    return 2;
                }
            }
            else
            {
                // 同为变量时报错误三，此时返回1
                if (it->isStruct == 0)
                {
                    // printf("Error type 3 at Line %d: Redefined variable \'i\'.",yylineno,it->name);
                    // printf("you have find the %s in arraytable\n",tnode->content);
                    return 1;
                }
            }
        }
        it = it->next;
    }
    // printf("you have not find the %s in arraytable\n",tnode->content);
    return 0;
}

int iffindArrayBySName(int num, char *name)
{
    Array_ *it = arrayHead->next;
    while (it != NULL)
    {
        if (it->structNum == num && strcmp(name, it->name) == 0)
            return 1;
        it = it->next;
    }
    return 0;
}

Array getArrayBySName(int num, char *name)
{
    Array_ *it = arrayHead->next;
    while (it != NULL)
    {
        if (it->structNum == num && strcmp(name, it->name) == 0)
            return it;
        it = it->next;
    }
    return NULL;
}

Array_ *getArray(tNode *tnode)
{
    // 目前在哪个结构体域内
    int nowstructNum = 0;
    if (stackTop != -1)
    {
        nowstructNum = structNumStack[stackTop];
    }
    Array_ *it = arrayHead->next;
    while (it != NULL)
    {
        if (strcmp(it->name, tnode->content) == 0)
        {
            if (it->structNum == nowstructNum)
            {
                return it;
            }
        }
        it = it->next;
    }
    return NULL;
}

void newStruct(int num, ...)
{
    va_list valist;
    va_start(valist, num);
    // 两个参数为Specifier结点和结构体名称
    tNode *Spe = va_arg(valist, tNode *);
    tNode *tag = va_arg(valist, tNode *);
    // 新的结构体
    Struct newStruct = (Struct)malloc(sizeof(Struct_));
    Type newType = (Type)malloc(sizeof(Type_));
    // newlist从newlisthead->next开始
    FieldList newListHead = (FieldList)malloc(sizeof(FieldList_));
    newListHead->next = NULL;
    FieldList newListTail = newListHead;

    if (stackTop != -1)
        newStruct->structNum = structNumStack[stackTop];
    newStruct->type = newType;
    newStruct->name = tag->content;
    newStruct->next = NULL;

    newType->kind = STRUCTURE;
    newType->u.structure.structName = tag->content;
    // newType->u.structure = newList;

    Basic var = basicHead->next;
    Array arr = arrayHead->next;
    int structidx = 1;
    while (var != NULL || arr != NULL)
    {
        if (var != NULL)
        {
            if (var->structNum == newStruct->structNum)
            {
                if (var->structIndex == structidx)
                {
                    FieldList_ *tempfieldlist = (FieldList)malloc(sizeof(FieldList_));
                    tempfieldlist->next = NULL;
                    tempfieldlist->name = var->name;
                    tempfieldlist->type = var->type;
                    // 将tempfieldlist加入到tail中
                    newListTail->next = tempfieldlist;
                    newListTail = tempfieldlist;
                    structidx++;
                    var = var->next;
                }
            }
            else
            {
                var = var->next;
            }
        }
        if (arr != NULL)
        {
            if (arr->structNum == newStruct->structNum)
            {
                if (arr->structIndex == structidx)
                {
                    FieldList_ *tempfieldlist = (FieldList)malloc(sizeof(FieldList_));
                    tempfieldlist->next = NULL;
                    tempfieldlist->name = arr->name;
                    tempfieldlist->type = arr->type;
                    // 将tempfieldlist加入到tail中
                    newListTail->next = tempfieldlist;
                    newListTail = tempfieldlist;
                    structidx++;
                    arr = arr->next;
                }
            }
            else
            {
                arr = arr->next;
            }
        }
    }

    // 将fieldlist加入到struct中
    newStruct->type->u.structure.structbody = newListHead->next;

    // 加入链表中
    structTail->next = newStruct;
    structTail = newStruct;

    Spe->type = newType;
    Spe->content = tag->content;
}

void newStructNoname(int num, ...)
{
    // printf("you have come to the nonamenestruct\n");
    va_list valist;
    va_start(valist, num);
    // 两个参数为Specifier结点和结构体名称
    tNode *Spe = va_arg(valist, tNode *);
    // 新的结构体
    Type newType = (Type)malloc(sizeof(Type_));
    // newlist从newlisthead->next开始
    FieldList newListHead = (FieldList)malloc(sizeof(FieldList_));
    newListHead->next = NULL;
    FieldList newListTail = newListHead;

    int structNum = 0;
    if (stackTop != -1)
        structNum = structNumStack[stackTop];

    newType->kind = STRUCTURE;
    newType->u.structure.structName = "";
    // newType->u.structure = newList;

    Basic var = basicHead->next;
    Array arr = arrayHead->next;
    int structidx = 1;
    while (var != NULL || arr != NULL)
    {
        if (var != NULL)
        {
            if (var->structNum == structNum)
            {
                if (var->structIndex == structidx)
                {
                    FieldList_ *tempfieldlist = (FieldList)malloc(sizeof(FieldList_));
                    tempfieldlist->next = NULL;
                    tempfieldlist->name = var->name;
                    tempfieldlist->type = var->type;
                    // 将tempfieldlist加入到tail中
                    newListTail->next = tempfieldlist;
                    newListTail = tempfieldlist;
                    structidx++;
                    var = var->next;
                }
            }
            else
            {
                var = var->next;
            }
        }
        if (arr != NULL)
        {
            if (arr->structNum == structNum)
            {
                if (arr->structIndex == structidx)
                {
                    FieldList_ *tempfieldlist = (FieldList)malloc(sizeof(FieldList_));
                    tempfieldlist->next = NULL;
                    tempfieldlist->name = arr->name;
                    tempfieldlist->type = arr->type;
                    // 将tempfieldlist加入到tail中
                    newListTail->next = tempfieldlist;
                    newListTail = tempfieldlist;
                    structidx++;
                    arr = arr->next;
                }
            }
            else
            {
                arr = arr->next;
            }
        }
    }

    // 将fieldlist加入到struct中
    newType->u.structure.structbody = newListHead->next;

    Spe->type = newType;
    Spe->content = "";
}

int findIfStruct(tNode *tnode)
{
    Struct_ *it = structHead->next;
    while (it != NULL)
    {
        if (strcmp(it->name, tnode->content) == 0)
        {
            return 1;
        }
        it = it->next;
    }
    return 0;
}

Struct_ *getStruct(tNode *tnode)
{
    Struct_ *it = structHead->next;
    while (it != NULL)
    {
        if (strcmp(it->name, tnode->content) == 0)
        {
            return it;
        }
        it = it->next;
    }
    return NULL;
}

Struct getStructByName(char *name)
{
    Struct_ *it = structHead->next;
    while (it != NULL)
    {
        if (strcmp(it->name, name) == 0)
        {
            return it;
        }
        it = it->next;
    }
    return NULL;
}

FieldList_ *getfield(Type_ *structtype, char *name)
{
    FieldList_ *head = structtype->u.structure.structbody;
    while (head != NULL)
    {
        if (strcmp(head->name, name) == 0)
        {
            break;
        }
        head = head->next;
    }
    return head;
}

int checkIfLeft(tNode *val)
{
    if (val == NULL)
        return 0;
    tNode *temp = val->child;
    // printf("check: %s\n", temp->name);
    if (temp == NULL)
        return 0;
    if (strcmp(temp->name, "ID") == 0 && temp->nextsibling == NULL)
        return 1;
    else if (!strcmp(temp->name, "Exp"))
    {
        temp = temp->nextsibling;
        if (temp == NULL)
            return 0;
        else if (strcmp(temp->name, "DOT") == 0)
        {
            temp = temp->nextsibling;
            if (temp == NULL)
                return 0;
            if (strcmp(temp->name, "ID") == 0)
            {
                if (temp->nextsibling == NULL)
                    return 1;
                else
                    return 0;
            }
            return 0;
        }
        else if (strcmp(temp->name, "LB") == 0)
        {
            temp = temp->nextsibling;
            if (temp == NULL)
                return 0;
            if (strcmp(temp->name, "Exp") == 0)
            {
                temp = temp->nextsibling;
                if (temp == NULL)
                    return 0;
                if (strcmp(temp->name, "RB") == 0)
                {
                    if (temp->nextsibling == NULL)
                        return 1;
                    else
                        return 0;
                }
                return 0;
            }
            return 0;
        }

        return 0;
    }
    else
        return 0;
}

void initSymbolList()
{
    // 初始化符号表
    basicHead = (Basic_ *)malloc(sizeof(Basic_));
    basicTail = basicHead;
    funcHead = (Func_ *)malloc(sizeof(Func_));
    funcTail = (Func_ *)malloc(sizeof(Func_));
    funcTail->varNum = 0;
    funcTail->next = NULL;
    funcHead->next = funcTail;
    arrayHead = (Array_ *)malloc(sizeof(Array_));
    arrayTail = arrayHead;
    arrayBodyHead = (Type_ *)malloc(sizeof(Type_));
    arrayBodyTail = arrayBodyHead;
    structHead = (Struct_ *)malloc(sizeof(Struct_));
    structTail = structHead;

    // 返回值类型是否一致
    for (int i = 0; i < 10; i++)
        funcReturnType[i] = (Type_ *)malloc(sizeof(Type_));
    returnTypeNum = 0;

    // 将形参初始化
    funcVarNum = 0;

    // 初始化结构体域判断信息
    stackTop = -1;
    maxStructNum = 0;
    stackIndexTop = -1;

    // 设置INT FLOAT类型的Type
    type_int = (Type)malloc(sizeof(Type_));
    type_int->kind = BASIC;
    type_int->u.basic = 0;
    type_float = (Type)malloc(sizeof(Type_));
    type_float->kind = BASIC;
    type_float->u.basic = 1;

    // 初始化是否存在词法语法错误
    iftrue = 1;

    // 在符号表中预先添加read、write函数
    addFuncRead();
    addFuncWrite();
}

int isSameTypeByNode(tNode *n1, tNode *n2)
{
    Type t1 = n1->type;
    Type t2 = n2->type;
    return isSameType(t1, t2);
}

int isSameType(Type t1, Type t2)
{
    // printf("t1->kind: %d    t2->kind:  %d\n", t1->kind, t2->kind);
    if (t1->kind != t2->kind)
    {
        return 1;
    }
    else
    {
        if (t1->kind == ARRAY)
        {
            // printf("t1->kind: %d    t2->kind:  %d\n", t1->kind, t2->kind);
            // printf("you have come to the array %d,,,,%d\n", t1->u.array.size, t2->u.array.size);
            Type e1 = t1;
            Type e2 = t2;
            // printf("e1->elem: %d    e2->elem: %d\n", e1->kind, e2->kind);
            // printf("e1->array.elem: %d, e2->array.elem: %d\n", e1->u.array.elem->kind, e2->u.array.elem->kind);
            while (e1->kind == ARRAY && e2->kind == ARRAY)
            {
                e1 = e1->u.array.elem;
                e2 = e2->u.array.elem;
                // printf("e1->elem: %d    e2->elem: %d\n", e1->kind, e2->kind);
            }
            // printf("ooooe1->elem: %d    oooooe2->elem: %d\n", e1->kind, e2->kind);
            //   维数不同
            if (e1->kind == ARRAY || e2->kind == ARRAY)
            {
                return 1;
            }
            // 基类型不同
            else if (isSameType(e1, e2) != 0)
            {
                return 1;
            }
        }
        else if (t1->kind == STRUCTURE)
        {
            // printf("you have come to the structure %s\n", t1->u.structure.structName);
            FieldList l1 = t1->u.structure.structbody;
            FieldList l2 = t2->u.structure.structbody;
            while (l1 != NULL && l2 != NULL)
            {
                if (isSameType(l1->type, l2->type) != 0)
                {
                    return 1;
                }
                l1 = l1->next;
                l2 = l2->next;
            }
            if (l1 != NULL || l2 != NULL)
            {
                return 1;
            }
        }
        else if (t1->u.basic != t2->u.basic)
        {
            return 1;
        }
    }
    // printf("you have get the an is same\n");
    return 0;
}

void addFunc(Func_ func)
{
    *funcTail = func;
    funcTail->next = (Func)malloc(sizeof(Func_));
    funcTail = funcTail->next;
}

void addFuncRead()
{
    Func_ read;
    read.name = "read";
    read.returnType = type_int;
    read.varNum = 0;
    addFunc(read);
}

void addFuncWrite()
{
    Func_ write;
    write.name = "write";
    write.returnType = type_int;
    write.varNum = 1;
    write.varType[0] = type_int;
    addFunc(write);
}

void addFuncMain()
{
    Func_ main;
    main.name = "main";
    main.returnType = type_int;
    main.varNum = 0;
    addFunc(main);
}
