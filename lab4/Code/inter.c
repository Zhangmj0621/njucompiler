#include "inter.h"
#include "tree.h"
#include <assert.h>

pInterCodeList interCodeList = NULL;

static inline char *newStr(char *src)
{
    char *dst = (char *)malloc(sizeof(char) * (strlen(src) + 1));
    strcpy(dst, src);
    return dst;
}

pOperand newOperand(int kind, ...)
{
    pOperand op = (pOperand)malloc(sizeof(Operand));
    op->kind = kind;
    va_list args;
    va_start(args, kind);
    if (kind == O_CONSTANT)
    {
        op->u.value = va_arg(args, int);
    }
    else
    {
        op->u.name = va_arg(args, char *);
    }
    op->type = NULL;
    return op;
}

void deleteOperand(pOperand op)
{
    assert(op != NULL);
    if (op->kind != O_CONSTANT)
    {
        assert(op->u.name != NULL);
        free(op->u.name);
    }
    free(op);
}

void setOperand(pOperand op, int kind, ...)
{
    assert(op != NULL);
    op->kind = kind;
    va_list args;
    va_start(args, kind);
    if (kind == O_CONSTANT)
    {
        op->u.value = va_arg(args, int);
    }
    else if (kind == O_ADDRESS)
    {
        op->kind = O_ADDRESS;
        char *tmp = va_arg(args, char *);
        if (tmp != NULL)
        {
            op->u.name = tmp;
        }
    }
    else
    {
        op->u.name = va_arg(args, char *);
    }
}

void setOperandType(pOperand op, Type tp)
{
    assert(op != NULL);
    op->type = tp;
}

void printOp(FILE *fp, pOperand op)
{
    assert(op != NULL);
    if (op->kind == O_CONSTANT)
    {
        fprintf(fp, "#%d", op->u.value);
    }
    else
    {
        fprintf(fp, "%s", op->u.name);
    }
}

pInterCode newInterCode(int kind, ...)
{
    va_list args;
    va_start(args, kind);
    pInterCode code = (pInterCode)malloc(sizeof(InterCode));
    code->kind = kind;
    switch (kind)
    {
    // single op
    case I_LABEL:
    case I_FUNCTION:
    case I_GOTO:
    case I_RETURN:
    case I_ARG:
    case I_ARG_ADDR:
    case I_PARAM:
    case I_READ:
    case I_WRITE:
        code->u.sinop.op = va_arg(args, pOperand);
        break;
    // assign
    case I_ASSIGN:
    case I_CALL:
    case I_GET_ADDR:
    case I_READ_ADDR:
    case I_WRITE_ADDR:
        code->u.assign.left = va_arg(args, pOperand);
        code->u.assign.right = va_arg(args, pOperand);
        break;
    // binary op
    case I_ADD:
    case I_SUB:
    case I_MUL:
    case I_DIV:
        code->u.binop.result = va_arg(args, pOperand);
        code->u.binop.op1 = va_arg(args, pOperand);
        code->u.binop.op2 = va_arg(args, pOperand);
        break;
    // if goto
    case I_IF_GOTO:
        code->u.if_goto.op1 = va_arg(args, pOperand);
        code->u.if_goto.relop = va_arg(args, pOperand);
        code->u.if_goto.op2 = va_arg(args, pOperand);
        code->u.if_goto.label = va_arg(args, pOperand);
        break;
    // dec
    case I_DEC:
        code->u.dec.op = va_arg(args, pOperand);
        code->u.dec.size = va_arg(args, int);
        break;
    }
    return code;
}

void deleteInterCode(pInterCode code)
{
    assert(code != NULL);
    switch (code->kind)
    {
    // single op
    case I_LABEL:
    case I_FUNCTION:
    case I_GOTO:
    case I_RETURN:
    case I_ARG:
    case I_ARG_ADDR:
    case I_PARAM:
    case I_READ:
    case I_WRITE:
        deleteOperand(code->u.sinop.op);
        break;
    // assign
    case I_ASSIGN:
    case I_CALL:
    case I_GET_ADDR:
    case I_READ_ADDR:
    case I_WRITE_ADDR:
        deleteOperand(code->u.assign.left);
        deleteOperand(code->u.assign.right);
        break;
    // binary op
    case I_ADD:
    case I_SUB:
    case I_MUL:
    case I_DIV:
        deleteOperand(code->u.binop.result);
        deleteOperand(code->u.binop.op1);
        deleteOperand(code->u.binop.op2);
        break;
    // if goto
    case I_IF_GOTO:
        deleteOperand(code->u.if_goto.op1);
        deleteOperand(code->u.if_goto.relop);
        deleteOperand(code->u.if_goto.op2);
        deleteOperand(code->u.if_goto.label);
        break;
    // dec
    case I_DEC:
        deleteOperand(code->u.dec.op);
        break;
    }
    free(code);
}

void printInterCode(FILE *fp, pInterCodeList list)
{
    // assert(fp != NULL);
    assert(list != NULL);
    pInterCodes codes = list->head;
    while (codes != NULL)
    {
        switch (codes->code->kind)
        {
        case I_LABEL:
            fprintf(fp, "LABEL ");
            printOp(fp, codes->code->u.sinop.op);
            fprintf(fp, " :");
            break;
        case I_FUNCTION:
            fprintf(fp, "FUNCTION ");
            printOp(fp, codes->code->u.sinop.op);
            fprintf(fp, " :");
            break;
        case I_ASSIGN:
            printOp(fp, codes->code->u.assign.left);
            fprintf(fp, " := ");
            printOp(fp, codes->code->u.assign.right);
            break;
        case I_GET_ADDR:
            printOp(fp, codes->code->u.assign.left);
            fprintf(fp, " := &");
            printOp(fp, codes->code->u.assign.right);
            break;
        case I_READ_ADDR:
            printOp(fp, codes->code->u.assign.left);
            fprintf(fp, " := *");
            printOp(fp, codes->code->u.assign.right);
            break;
        case I_WRITE_ADDR:
            fprintf(fp, "*");
            printOp(fp, codes->code->u.assign.left);
            fprintf(fp, " := ");
            printOp(fp, codes->code->u.assign.right);
            break;
        case I_ADD:
            printOp(fp, codes->code->u.binop.result);
            fprintf(fp, " := ");
            printOp(fp, codes->code->u.binop.op1);
            fprintf(fp, " + ");
            printOp(fp, codes->code->u.binop.op2);
            break;
        case I_SUB:
            printOp(fp, codes->code->u.binop.result);
            fprintf(fp, " := ");
            printOp(fp, codes->code->u.binop.op1);
            fprintf(fp, " - ");
            printOp(fp, codes->code->u.binop.op2);
            break;
        case I_MUL:
            printOp(fp, codes->code->u.binop.result);
            fprintf(fp, " := ");
            printOp(fp, codes->code->u.binop.op1);
            fprintf(fp, " * ");
            printOp(fp, codes->code->u.binop.op2);
            break;
        case I_DIV:
            printOp(fp, codes->code->u.binop.result);
            fprintf(fp, " := ");
            printOp(fp, codes->code->u.binop.op1);
            fprintf(fp, " / ");
            printOp(fp, codes->code->u.binop.op2);
            break;
        case I_GOTO:
            fprintf(fp, "GOTO ");
            printOp(fp, codes->code->u.sinop.op);
            break;
        case I_IF_GOTO:
            fprintf(fp, "IF ");
            printOp(fp, codes->code->u.if_goto.op1);
            fprintf(fp, " ");
            printOp(fp, codes->code->u.if_goto.relop);
            fprintf(fp, " ");
            printOp(fp, codes->code->u.if_goto.op2);
            fprintf(fp, " GOTO ");
            printOp(fp, codes->code->u.if_goto.label);
            break;
        case I_RETURN:
            fprintf(fp, "RETURN ");
            printOp(fp, codes->code->u.sinop.op);
            break;
        case I_DEC:
            fprintf(fp, "DEC ");
            printOp(fp, codes->code->u.dec.op);
            fprintf(fp, " %d", codes->code->u.dec.size);
            break;
        case I_ARG:
            fprintf(fp, "ARG ");
            printOp(fp, codes->code->u.sinop.op);
            break;
        case I_ARG_ADDR:
            fprintf(fp, "ARG &");
            printOp(fp, codes->code->u.sinop.op);
            break;
        case I_CALL:
            printOp(fp, codes->code->u.assign.left);
            fprintf(fp, " := CALL ");
            printOp(fp, codes->code->u.assign.right);
            break;
        case I_PARAM:
            fprintf(fp, "PARAM ");
            printOp(fp, codes->code->u.sinop.op);
            break;
        case I_READ:
            fprintf(fp, "READ ");
            printOp(fp, codes->code->u.sinop.op);
            break;
        case I_WRITE:
            fprintf(fp, "WRITE ");
            printOp(fp, codes->code->u.sinop.op);
            break;
        }
        fprintf(fp, "\n");
        codes = codes->next;
    }
}

pInterCodes newInterCodes(pInterCode code)
{
    pInterCodes codes = (pInterCodes)malloc(sizeof(InterCodes));
    codes->code = code;
    codes->next = NULL;
    codes->prev = NULL;
    return codes;
}

pInterCodeList newInterCodeList()
{
    pInterCodeList list = (pInterCodeList)malloc(sizeof(InterCodeList));
    list->head = NULL;
    list->tail = NULL;
    list->arrType = NULL;
    list->norVarCnt = 0;
    list->tmpVarCnt = 0;
    list->labelCnt = 0;
    return list;
}

void deleteInterCodes(pInterCodes codes)
{
    assert(codes != NULL);
    deleteInterCode(codes->code);
    codes->code = NULL;
    codes->next = NULL;
    codes->prev = NULL;
    free(codes);
}

void deleteInterCodeList(pInterCodeList list)
{
    assert(list != NULL);
    pInterCodes codes = list->head;
    while (codes != NULL)
    {
        pInterCodes next = codes->next;
        deleteInterCodes(codes);
        codes = next;
    }
    list->head = NULL;
    list->tail = NULL;
    free(list);
}

void addInterCode(pInterCodeList list, pInterCodes codes)
{
    assert(list != NULL);
    assert(codes != NULL);
    if (list->head == NULL)
    {
        list->head = codes;
        list->tail = codes;
    }
    else
    {
        list->tail->next = codes;
        codes->prev = list->tail;
        list->tail = codes;
    }
}

pArg newArg(pOperand op)
{
    pArg arg = (pArg)malloc(sizeof(Arg));
    arg->op = op;
    arg->next = NULL;
    return arg;
}

pArgList newArgList()
{
    pArgList list = (pArgList)malloc(sizeof(ArgList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void deleteArg(pArg arg)
{
    assert(arg != NULL);
    deleteOperand(arg->op);
    arg->op = NULL;
    arg->next = NULL;
    free(arg);
}

void deleteArgList(pArgList list)
{
    assert(list != NULL);
    pArg arg = list->head;
    while (arg != NULL)
    {
        pArg next = arg->next;
        deleteArg(arg);
        arg = next;
    }
    list->head = NULL;
    list->tail = NULL;
    free(list);
}

void addArg(pArgList list, pArg arg)
{
    assert(list != NULL);
    assert(arg != NULL);
    if (list->head == NULL)
    {
        list->head = arg;
        list->tail = arg;
    }
    else
    {
        list->tail->next = arg;
        list->tail = arg;
    }
}

pOperand newTmp()
{
    char *name = (char *)malloc(sizeof(char) * MAX_NAME_LEN);
    sprintf(name, "t%d", interCodeList->tmpVarCnt++);
    return newOperand(O_VARIABLE, name);
}

pOperand newLabel()
{
    char *name = (char *)malloc(sizeof(char) * MAX_NAME_LEN);
    sprintf(name, "label%d", interCodeList->labelCnt++);
    return newOperand(O_LABEL, name);
}

int getSize(Type type)
{
    if (type->kind == BASIC)
    {
        return 4;
    }
    else if (type->kind == ARRAY)
    {
        return type->u.array.size * getSize(type->u.array.elem);
    }
    else if (type->kind == STRUCTURE)
    {
        int size = 0;
        FieldList field = type->u.structure.structbody;
        while (field != NULL)
        {
            size += getSize(field->type);
            field = field->next;
        }
        return size;
    }
    else
    {
        assert(0);
    }
}

Type getElement(Type type)
{
    assert(type != NULL);
    if (type->kind == ARRAY)
    {
        return getElement(type->u.array.elem);
    }
    else
    {
        return type;
    }
}

void genInterCodes(pNode node)
{
    if (node == NULL)
    {
        return;
    }
    else if (!strcmp(node->name, "ExtDefList"))
    {
        printf("you have come to the genintercodesexdeflist\n");
        translateExtDefList(node);
    }
    else
    {
        pNode child = node->child;
        while (child != NULL)
        {
            genInterCodes(child);
            child = child->nextsibling;
        }
    }
}

void genInterCode(int kind, ...)
{
    printf("you have come to genintercode\n");
    pOperand op1, op2, relop, res, tmp;
    pInterCodes codes = NULL;
    int size = 0;

    va_list args;
    va_start(args, kind);
    printf("kind: %d\n", kind);
    switch (kind)
    {
    case I_LABEL:
    case I_FUNCTION:
    case I_GOTO:
    case I_RETURN:
    case I_PARAM:
    case I_ARG:
    case I_ARG_ADDR:
    case I_READ:
    case I_WRITE:
        op1 = va_arg(args, pOperand);
        codes = newInterCodes(newInterCode(kind, op1));
        addInterCode(interCodeList, codes);
        break;
    case I_ASSIGN:
    case I_CALL:
    case I_GET_ADDR:
    case I_READ_ADDR:
    case I_WRITE_ADDR:
        printf("come in\n");
        op1 = va_arg(args, pOperand);
        op2 = va_arg(args, pOperand);
        if (kind == I_ASSIGN &&
            (op1->kind == O_ADDRESS || op2->kind == O_ADDRESS))
        {
            printf("you have come &x=&y\n");
            if (op1->kind == O_ADDRESS && op2->kind == O_ADDRESS)
            {
                // a[i] = b[j];
                tmp = newTmp();
                genInterCode(I_READ_ADDR, tmp, op2);
                genInterCode(I_WRITE_ADDR, op1, tmp);
            }
            else if (op1->kind == O_ADDRESS)
            {
                // a[i] = x;
                genInterCode(I_WRITE_ADDR, op1, op2);
            }
            else if (op2->kind == O_ADDRESS)
            {
                // x = a[i];
                genInterCode(I_READ_ADDR, op1, op2);
            }
            else
                assert(0);
        }
        else
        {
            // x = y;
            printf("you have come x=y\n");
            codes = newInterCodes(newInterCode(kind, op1, op2));
            addInterCode(interCodeList, codes);
        }
        break;
    case I_ADD:
    case I_SUB:
    case I_MUL:
    case I_DIV:
        res = va_arg(args, pOperand);
        op1 = va_arg(args, pOperand);
        op2 = va_arg(args, pOperand);
        printf("you have get I_ADDSUBMULDIV op1,op2\n");
        if (op1->kind == O_ADDRESS && op2->kind == O_ADDRESS)
        {
            tmp = newTmp();
            genInterCode(I_READ_ADDR, tmp, op1);
            op1 = tmp;
            tmp = newTmp();
            genInterCode(I_READ_ADDR, tmp, op2);
            op2 = tmp;
        }
        codes = newInterCodes(newInterCode(kind, res, op1, op2));
        addInterCode(interCodeList, codes);
        printf("you have come out IADDSUBMULDIV\n");
        break;
    case I_IF_GOTO:
        res = va_arg(args, pOperand);
        relop = va_arg(args, pOperand);
        op1 = va_arg(args, pOperand);
        op2 = va_arg(args, pOperand);
        codes = newInterCodes(newInterCode(kind, res, relop, op1, op2));
        addInterCode(interCodeList, codes);
        break;
    case I_DEC:
        op1 = va_arg(args, pOperand);
        size = va_arg(args, int);
        codes = newInterCodes(newInterCode(kind, op1, size));
        addInterCode(interCodeList, codes);
        break;
    default:
        assert(0);
    }
}

void translateExp(pNode node, pOperand place)
{
    /*
    Exp: Exp ASSIGNOP Exp
        |   Exp AND Exp
        |   Exp OR Exp
        |   Exp RELOP Exp
        |   Exp PLUS Exp
        |   Exp MINUS Exp
        |   Exp STAR Exp
        |   Exp DIV Exp
        |   LP Exp RP
        |   MINUS Exp
        |   NOT Exp
        |   ID LP Args RP
        |   ID LP RP
        |   Exp LB Exp RB
        |   Exp DOT ID
        |   ID
        |   INT
        |   FLOAT
    */
    assert(node != NULL);
    if (node->lineno <= 0)
        return;
    assert(!strcmp(node->name, "Exp"));
    pNode child = node->child;
    printf("you have come to hte translateexp child->name:%s\n", child->name);
    if (!strcmp(child->name, "LP"))
    {
        // LP Exp RP
        translateExp(child->nextsibling, place);
    }
    else if (!strcmp(child->name, "Exp") || !strcmp(child->name, "NOT"))
    {
        pNode op = child->nextsibling;
        // Exp -> Exp AND Exp
        // Exp -> Exp OR ID
        // Exp -> Exp RELOP Exp
        // Exp -> NOT Exp
        // For boolean value
        if (!strcmp(child->name, "NOT") ||
            !strcmp(op->name, "AND") ||
            !strcmp(op->name, "OR") ||
            !strcmp(op->name, "RELOP"))
        {
            if (place == NULL)
                return;
            pOperand label1 = newLabel();
            pOperand label2 = newLabel();
            pOperand zero = newOperand(O_CONSTANT, 0);
            pOperand one = newOperand(O_CONSTANT, 1);
            genInterCode(I_ASSIGN, place, zero);
            translateCond(node, label1, label2);
            genInterCode(I_LABEL, label1);
            genInterCode(I_ASSIGN, place, one);
            genInterCode(I_LABEL, label2);
        }
        // Exp -> Exp ASSIGNOP Exp
        else if (!strcmp(op->name, "ASSIGNOP"))
        {
            pOperand t2 = newTmp();
            translateExp(op->nextsibling, t2);
            pOperand t1 = newTmp();
            printf("you have going to\n");
            translateExp(child, t1);
            genInterCode(I_ASSIGN, t1, t2);
        }
        // Exp PLUS Exp
        // Exp MINUS Exp
        // Exp STAR Exp
        // Exp DIV Exp
        else if (!strcmp(op->name, "PLUS") ||
                 !strcmp(op->name, "MINUS") ||
                 !strcmp(op->name, "STAR") ||
                 !strcmp(op->name, "DIV"))
        {
            pOperand t1 = newTmp();
            pOperand t2 = newTmp();
            printf("you have into add\n");
            translateExp(op->nextsibling, t2);
            printf("you have out add\n");
            translateExp(child, t1);
            if (!strcmp(op->name, "PLUS"))
                genInterCode(I_ADD, place, t1, t2);
            else if (!strcmp(op->name, "MINUS"))
                genInterCode(I_SUB, place, t1, t2);
            else if (!strcmp(op->name, "STAR"))
                genInterCode(I_MUL, place, t1, t2);
            else if (!strcmp(op->name, "DIV"))
                genInterCode(I_DIV, place, t1, t2);
            else
                assert(0);
        }
        // Exp DOT ID
        else if (!strcmp(op->name, "DOT"))
        {
            if (place == NULL)
                return;
            pOperand t1 = newTmp();
            translateExp(child, t1);
            pOperand tar = NULL;
            printf("xxxxxxxxxxxxxxxxx%d\n", t1->kind);
            if (t1->kind == O_ADDRESS)
            {
                // 如果Exp是结构体的地址，tar为地址
                tar = newOperand(O_ADDRESS, newStr(t1->u.name));
            }
            else
            {
                // 否则tar为临时变量
                tar = newTmp();
                genInterCode(I_GET_ADDR, tar, t1);
            }
            char *name = op->nextsibling->content;
            pOperand id = newTmp();
            int offset = 0;
            // Struct s = getStructByName(t1->u.name);
            printf(">>>>>>%s\n", t1->u.name);
            // printf("you have into dot:%s\n", s == NULL ? "NULL" : s->name);
            FieldList f = getBasicByName(t1->u.name)->type->u.structure.structbody;
            while (f != NULL)
            {
                if (!strcmp(f->name, name))
                    break;
                offset += getSize(f->type);
                f = f->next;
            }
            pOperand offsetOp = newOperand(O_CONSTANT, offset);
            genInterCode(I_ADD, place, tar, offsetOp);
            setOperand(place, O_ADDRESS, newStr(id->u.name));
        }
        // Exp LB Exp RB
        else if (!strcmp(op->name, "LB"))
        {
            if (place == NULL)
                return;
            pOperand t1 = newTmp();
            pOperand t2 = newTmp();
            char *oldName = newStr(t2->u.name);
            translateExp(op->nextsibling, t1);
            translateExp(child, t2);
            pOperand tar = NULL, width = NULL;
            pOperand offset = newTmp();
            width = newOperand(O_CONSTANT, getSize(t2->type));
            genInterCode(I_MUL, offset, t1, width);
            if (t2->kind == O_VARIABLE)
            {
                // ID[Exp]
                tar = newTmp();
                genInterCode(I_GET_ADDR, tar, t2);
            }
            else
            {
                // Exp.ID[Exp]
                tar = t2;
            }
            genInterCode(I_ADD, place, tar, offset);
            place->kind = O_ADDRESS;
            if (t2->type->kind == ARRAY)
            {
                place->type = t2->type->u.array.elem;
            }
            if (strcmp(oldName, t2->u.name))
            {
                interCodeList->arrType = t2->type;
            }
            free(oldName);
        }
        else
        {
            assert(0);
        }
    }
    // MINUS Exp
    else if (!strcmp(child->name, "MINUS"))
    {
        if (place == NULL)
            return;
        pOperand t1 = newTmp();
        translateExp(child->nextsibling, t1);
        pOperand zero = newOperand(O_CONSTANT, 0);
        genInterCode(I_SUB, place, zero, t1);
    }
    // ID LP Args RP
    //    |  ID LP RP
    else if (!strcmp(child->name, "ID") && child->nextsibling != NULL && !strcmp(child->nextsibling->name, "LP"))
    {
        Func f = getFunc(child);
        pOperand funcTmp = newOperand(O_FUNCTION, newStr(f->name));
        if (!strcmp(child->nextsibling->nextsibling->name, "Args"))
        {
            // ID LP Args RP
            pArgList argList = newArgList();
            translateArgs(child->nextsibling->nextsibling, argList);
            if (!strcmp(f->name, "write"))
            {
                genInterCode(I_WRITE, argList->head->op);
            }
            else
            {
                // 传参
                pArg arg = argList->head;
                while (arg != NULL)
                {
                    if (arg->op->kind == O_VARIABLE)
                    {
                        printf("?????%s\n", arg->op->u.name);
                        if (getBasicByName(arg->op->u.name) != NULL && getBasicByName(arg->op->u.name)->type->kind == STRUCTURE)
                        {
                            // Parameters of array and structure as address
                            pOperand varTmp = newTmp();
                            genInterCode(I_GET_ADDR, varTmp, arg->op);
                            pOperand varTmpCopy = newOperand(O_ADDRESS, varTmp->u.name);
                            genInterCode(I_ARG_ADDR, varTmpCopy);
                        }
                        else
                        {
                            genInterCode(I_ARG, arg->op);
                        }
                    }
                    else if (arg->op->kind == O_ADDRESS)
                    {
                        genInterCode(I_ARG_ADDR, arg->op);
                    }
                    else
                    {
                        genInterCode(I_ARG, arg->op);
                    }
                    arg = arg->next;
                }
                if (place != NULL)
                {
                    genInterCode(I_CALL, place, funcTmp);
                }
                else
                {
                    pOperand t = newTmp();
                    genInterCode(I_CALL, t, funcTmp);
                }
            }
        }
        else
        {
            // ID LP RP
            if (!strcmp(f->name, "read"))
            {
                printf("you have come to read\n");
                genInterCode(I_READ, place);
            }
            else
            {
                if (place != NULL)
                {
                    genInterCode(I_CALL, place, funcTmp);
                }
                else
                {
                    pOperand t = newTmp();
                    genInterCode(I_CALL, t, funcTmp);
                }
            }
        }
    }
    // ID
    else if (!strcmp(child->name, "ID"))
    {
        if (place == NULL)
            return;
        printf("you have come to child->bame id\n");
        if (findBasic(child))
        {
            if (getBasic(child)->type->kind == BASIC)
                setOperand(place, O_VARIABLE, newStr(child->content));
            else
                setOperand(place, O_ADDRESS, newStr(child->content));
        }
    }
    // INT
    else if (!strcmp(child->name, "INT"))
    {
        if (place == NULL)
            return;
        printf("child->val: %d\n", child->type_int);
        setOperand(place, O_CONSTANT, child->type_int);
        printf("you have come off the exp->int\n");
    }
    else
    {
        assert(0);
    }
}

void translateArgs(pNode node, pArgList argList)
{
    /*
    Args: Exp COMMA Args
        |   Exp
    */
    assert(node != NULL);
    if (node->lineno <= 0)
        return;
    printf("you have come to the translateargs\n");
    assert(!strcmp(node->name, "Args"));
    pNode child = node->child;
    if (child->nextsibling != NULL)
    {
        translateArgs(child->nextsibling->nextsibling, argList);
    }
    // Exp
    pArg arg = newArg(newTmp());
    translateExp(child, arg->op);
    addArg(argList, arg);
}

void translateCond(pNode node, pOperand labelTrue, pOperand labelFalse)
{
    /*
    Exp: Exp RELOP Exp
        |   Exp AND Exp
        |   Exp OR Exp
        |   NOT Exp
    */
    assert(node != NULL);
    if (node->lineno <= 0)
        return;
    printf("you have come to the translatecond\n");
    assert(!strcmp(node->name, "Exp"));
    pNode child = node->child;
    // NOT Exp
    if (!strcmp(child->name, "NOT"))
    {
        translateCond(child->nextsibling, labelFalse, labelTrue);
    }
    // Exp RELOP Exp
    else if (!strcmp(child->nextsibling->name, "RELOP"))
    {
        pOperand t1 = newTmp();
        pOperand t2 = newTmp();
        translateExp(child, t1);
        translateExp(child->nextsibling->nextsibling, t2);
        pOperand relop = newOperand(O_RELOP, newStr(child->nextsibling->content));
        if (t1->kind == O_ADDRESS)
        {
            pOperand tmp = newTmp();
            genInterCode(I_READ_ADDR, tmp, t1);
            t1 = tmp;
        }
        if (t2->kind == O_ADDRESS)
        {
            pOperand tmp = newTmp();
            genInterCode(I_READ_ADDR, tmp, t2);
            t2 = tmp;
        }
        genInterCode(I_IF_GOTO, t1, relop, t2, labelTrue);
        genInterCode(I_GOTO, labelFalse);
    }
    // Exp AND Exp
    else if (!strcmp(child->nextsibling->name, "AND"))
    {
        pOperand label1 = newLabel();
        translateCond(child, label1, labelFalse);
        genInterCode(I_LABEL, label1);
        translateCond(child->nextsibling->nextsibling, labelTrue, labelFalse);
    }
    // Exp OR Exp
    else if (!strcmp(child->nextsibling->name, "OR"))
    {
        pOperand label1 = newLabel();
        translateCond(child, labelTrue, label1);
        genInterCode(I_LABEL, label1);
        translateCond(child->nextsibling->nextsibling, labelTrue, labelFalse);
    }
    else
    {
        pOperand t1 = newTmp();
        translateExp(node, t1);
        pOperand zero = newOperand(O_CONSTANT, 0);
        pOperand relop = newOperand(O_RELOP, newStr("!="));
        if (t1->kind == O_ADDRESS)
        {
            pOperand tmp = newTmp();
            genInterCode(I_READ_ADDR, tmp, t1);
            t1 = tmp;
        }
        genInterCode(I_IF_GOTO, t1, relop, zero, labelTrue);
        genInterCode(I_GOTO, labelFalse);
    }
}

void translateVarDec(pNode node, pOperand place)
{
    /*
    VarDec: ID
        |   VarDec LB INT RB
    */
    assert(node != NULL);
    if (node->lineno <= 0)
        return;
    printf("you have come to the translatevardec\n");
    assert(!strcmp(node->name, "VarDec"));
    pNode child = node->child;
    if (child->nextsibling == NULL)
    {
        // ID
        if (findBasic(child))
        {
            printf("the child can be find\n");
            Basic var = getBasic(child);
            if (var->type->kind == BASIC)
            {
                if (place != NULL)
                {
                    interCodeList->tmpVarCnt--;
                    printf("you have get ready for setoperand\n");
                    setOperand(place, O_VARIABLE, newStr(child->content));
                    printf("you have get off the setop\n");
                }
            }
            else if (var->type->kind == ARRAY || var->type->kind == STRUCTURE)
            {
                genInterCode(I_DEC, newOperand(O_VARIABLE, newStr(child->content)), getSize(var->type));
            }
            else
            {
                assert(0);
            }
        }
        // else if (findArray(child))
        // {
        //     genInterCode(I_DEC, newOperand(O_VARIABLE, newStr(child->content)), getSize(child->type));
        // }
        // else if (findIfStruct(child))
        // {
        //     genInterCode(I_DEC, newOperand(O_VARIABLE, newStr(child->content)), getSize(child->type));
        // }
        else
        {
            assert(0);
        }
    }
    else
    {
        // VarDec LB INT RB
        if (getArray(child)->type->u.array.elem->kind != ARRAY)
            translateVarDec(child, place);
        else
        {
            printf("Cannot translate: Code contains variables of multi-dimensional array type or parameters of array type.\n");
            exit(0);
        }
    }
}

void translateDec(pNode node)
{
    /*
    Dec:    VarDec
        |   VarDec ASSIGNOP Exp
    */
    assert(node != NULL);
    if (node->lineno <= 0)
        return;
    printf("you have come to the translatedec\n");
    assert(!strcmp(node->name, "Dec"));
    pNode child = node->child;
    if (child->nextsibling == NULL)
    {
        // VarDec
        translateVarDec(child, NULL);
    }
    else
    {
        // VarDec ASSIGNOP Exp
        pOperand op1 = newTmp();
        translateVarDec(child, op1);
        pOperand op2 = newTmp();
        translateExp(child->nextsibling->nextsibling, op2);
        genInterCode(I_ASSIGN, op1, op2);
    }
    printf("you have successfully get off translatedec\n");
}

void translateDecList(pNode node)
{
    /*
    DecList:    Dec
        |       Dec COMMA DecList
    */
    assert(node != NULL);
    if (node->lineno <= 0)
        return;
    printf("you have come to the transaltedeclist\n");
    assert(!strcmp(node->name, "DecList"));
    pNode child = node->child;
    if (child != NULL)
    {
        translateDec(child);
        if (child->nextsibling != NULL)
            translateDecList(child->nextsibling->nextsibling);
    }
}

void translateDef(pNode node)
{
    /*
    Def: Specifier DecList SEMI
    */
    assert(node != NULL);
    if (node->lineno <= 0)
        return;
    printf("you have come to the translatedef\n");
    if (node->lineno <= 0)
        return;
    assert(!strcmp(node->name, "Def"));
    translateDecList(node->child->nextsibling);
}

void translateDefList(pNode node)
{
    /*
    DefList:    Def DefList
        |       empty
    */
    assert(node != NULL);
    if (node->lineno <= 0)
        return;
    printf("you have come to the translatedeflist\n");
    assert(!strcmp(node->name, "DefList"));
    pNode child = node->child;
    if (child != NULL)
    {
        translateDef(child);
        if (child->nextsibling != NULL)
            translateDefList(child->nextsibling);
    }
}

void translateCompSt(pNode node)
{
    /*
    CompSt:     LC DefList StmtList RC
    */
    assert(node != NULL);
    if (node->lineno <= 0)
        return;
    printf("you have come to the translatecompst\n");
    assert(!strcmp(node->name, "CompSt"));
    // DefList
    pNode child = node->child->nextsibling;
    if (!strcmp(child->name, "DefList"))
    {
        translateDefList(child);
        child = child->nextsibling;
    }
    if (!strcmp(child->name, "StmtList"))
    {
        translateStmtList(child);
    }
    // translateDefList(node->child->nextsibling);
    //  StmtList
    // translateStmtList(node->child->nextsibling->nextsibling);
}

void translateStmt(pNode node)
{
    /*
    Stmt:   Exp SEMI
        |   CompSt
        |   RETURN Exp SEMI
        |   IF LP Exp RP Stmt
        |   IF LP Exp RP Stmt ELSE Stmt
        |   WHILE LP Exp RP Stmt
    */
    assert(node != NULL);
    if (node->lineno <= 0)
        return;
    printf("you have come to the translate stmt\n");
    assert(!strcmp(node->name, "Stmt"));
    pNode child = node->child;
    if (!strcmp(child->name, "Exp"))
    {
        // Exp SEMI
        translateExp(child, NULL);
    }
    else if (!strcmp(child->name, "CompSt"))
    {
        // CompSt
        translateCompSt(child);
    }
    else if (!strcmp(child->name, "RETURN"))
    {
        // RETURN Exp SEMI
        if (!strcmp(child->nextsibling->name, "Exp"))
        {
            pOperand op1 = newTmp();
            printf("you haev successfully into return\n");
            translateExp(child->nextsibling, op1);
            printf("you haev successfully leave exp\n");
            genInterCode(I_RETURN, op1);
            printf("you have successfuly leavev return\n");
        }
        // else
        // {
        //     genInterCode(I_RETURN, NULL);
        // }
    }
    else if (!strcmp(child->name, "IF"))
    {
        // IF LP Exp RP Stmt
        pNode exp = child->nextsibling->nextsibling;
        pNode stmt = exp->nextsibling->nextsibling;
        pOperand label1 = newLabel();
        pOperand label2 = newLabel();
        printf("you have get ready for transalte cond\n");
        translateCond(exp, label1, label2);
        printf("you have get off translate cond\n");
        genInterCode(I_LABEL, label1);
        translateStmt(stmt);
        if (stmt->nextsibling != NULL)
        {
            // IF LP Exp RP Stmt ELSE Stmt
            pOperand label3 = newLabel();
            genInterCode(I_GOTO, label3);
            genInterCode(I_LABEL, label2);
            translateStmt(stmt->nextsibling->nextsibling);
            genInterCode(I_LABEL, label3);
        }
        else
        {
            // IF LP Exp RP Stmt
            genInterCode(I_LABEL, label2);
        }
    }
    else if (!strcmp(child->name, "WHILE"))
    {
        // WHILE LP Exp RP Stmt
        pOperand label1 = newLabel();
        pOperand label2 = newLabel();
        pOperand label3 = newLabel();
        genInterCode(I_LABEL, label1);
        translateCond(child->nextsibling->nextsibling, label2, label3);
        genInterCode(I_LABEL, label2);
        translateStmt(child->nextsibling->nextsibling->nextsibling->nextsibling);
        genInterCode(I_GOTO, label1);
        genInterCode(I_LABEL, label3);
    }
    else
    {
        assert(0);
    }
}

void translateStmtList(pNode node)
{
    /*
    StmtList:   Stmt StmtList
        |       empty
    */
    assert(node != NULL);
    if (node->lineno <= 0)
        return;
    printf("you have come to the translatestmtlist\n");
    assert(!strcmp(node->name, "StmtList"));
    pNode child = node->child;
    if (child != NULL)
    {
        translateStmt(child);
        if (child->nextsibling != NULL)
            translateStmtList(child->nextsibling);
    }
}

void translateFunDec(pNode node)
{
    /*
    FunDec:     ID LP VarList RP
        |       ID LP RP
    */
    assert(node != NULL);
    if (node->lineno <= 0)
        return;
    printf("you have come to the tanslagfunc\n");
    assert(!strcmp(node->name, "FunDec"));
    Func func = NULL;
    func = getFunc(node->child);
    genInterCode(I_FUNCTION, newOperand(O_FUNCTION, newStr(func->name)));
    printf("you have successfully getintercode\n");
    // VarList
    for (int i = 0; i < func->varNum; i++)
    {
        if (func->varType[i]->kind == ARRAY)
        {
            printf("Cannot translate: Code contains variables of multi-dimensional array type or parameters of array type.\n");
            exit(0);
        }
        else if (func->varType[i]->kind == STRUCTURE)
        {
            genInterCode(I_PARAM, newOperand(O_ADDRESS, func->varName[i]));
        }
        else
        {
            genInterCode(I_PARAM, newOperand(O_VARIABLE, func->varName[i]));
        }
    }
    printf("you have successfully leave translatefunc\n");
}

void translateExtDef(pNode node)
{
    /*
    ExtDef:     Specifier ExtDecList SEMI
        |       Specifier SEMI
        |       Specifier FunDec CompSt
        |       Specifier FunDec SEMI
    */
    assert(node != NULL);
    if (node->lineno <= 0)
        return;
    printf("you have come to the translateexdef\n");
    assert(!strcmp(node->name, "ExtDef"));
    //"ExtDef -> Specifier FunDec CompSt"
    if (!strcmp(node->child->nextsibling->name, "FunDec"))
    {
        translateFunDec(node->child->nextsibling);
        translateCompSt(node->child->nextsibling->nextsibling);
    }
}

void translateExtDefList(pNode node)
{
    /*
    ExtDefList:     e
        |       ExtDef ExtDefList
    */
    assert(node != NULL);
    if (node->lineno <= 0)
        return;
    printf("you have come to the translateextdeflist\n");
    assert(!strcmp(node->name, "ExtDefList"));
    pNode child = node->child;
    translateExtDef(child);
    if (child->nextsibling != NULL)
        translateExtDefList(child->nextsibling);
}
