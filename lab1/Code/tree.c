#include"tree.h"

// int getnodelistId(tNode* node)
// {
//     for(int i=0;i<nodenum;i++)
//     {
//         if(nodelist[i]==node)
//             return i;
//     }
//     return -1;  //find error
// }

tNode* addNode(char* name,int num,...){
    printf("you have come to addnode");
    tNode* newNode=(tNode*)malloc(sizeof(tNode));
    tNode* temp;
    if(!newNode){
        //create error
        yyerror("create treeNode error");
        exit(0);
    }
    newNode->name=name;
    newNode->iflexcial=0;
    if(strcmp(name,"Program")==0) firstNode=newNode;
    //create valist
    va_list list;

    //start the valist
    va_start(list,num);

    if(num > 0)
    {
        temp=va_arg(list,tNode*);   //the first childNode
        newNode->child=temp;
        newNode->lineno=temp->lineno;

        //如果只有一个孩子节点，传递语义值
        if(num == 1)
        {
            newNode->content=temp->content;
        }
        for(int i = 0; i< num - 1; i++)
        {
            temp->nextsibling=va_arg(list,tNode*);
            temp=temp->nextsibling;
        }
    }
    else{
        newNode->child=NULL;
        newNode->lineno=va_arg(list,int);
        newNode->iflexcial=1;
        if(strcmp(newNode->name,"TYPE")==0 || strcmp(newNode->name,"ID")==0)    //save into val
        {
            newNode->val=(char*)malloc(strlen(yytext));
            strcpy(newNode->val,yytext);
            //同时存入语义content中
            newNode->content=(char*)malloc(strlen(yytext));
            strcpy(newNode->content,yytext);
        }
        //func atoi can not transfer OCT and HEX to DEC
        else if(strcmp(newNode->name,"INT")==0)
        {
            newNode->type_int=stoi(yytext);
            //将数据类型定义为int
            Type ntype;
            ntype->kind=BASIC;
            ntype->u.basic=0;
            newNode->type=ntype;
        }
        else if(strcmp(newNode->name,"FLOAT")==0)
        {
            newNode->type_float=stof(yytext);
            //将数据类型定义为float
            Type ntype;
            ntype->kind=BASIC;
            ntype->u.basic=1;
            newNode->type=ntype;
        }
        else{
            char* str=(char*)malloc(sizeof(char)*40);
            strcpy(str,yytext);
            newNode->content=str;
        }
    }
    return newNode;
}

void dfs(tNode* head,int level)
{
    if(head==NULL)
    {
        return;
    }
    if(head->lineno>0)
    {
        for(int i=0;i<level;i++)
        {
            printf("  ");
        }
        printf("%s",head->name);
        if(strcmp(head->name,"TYPE")==0 || strcmp(head->name,"ID")==0)    //save into val
        {
            printf(": %s",head->val);
        }
        else if(strcmp(head->name,"INT")==0)
        {
            printf(": %d",head->type_int);
        }
        else if(strcmp(head->name,"FLOAT")==0)
        {
            printf(": %f",head->type_float);
        }
        else if(head->iflexcial==0){
            printf(" (%d)",head->lineno);
        }
        printf("\n");
    }
    dfs(head->child,level+1);
    dfs(head->nextsibling,level);
    return;
}

yyerror(char* msg){
  iftrue=0;
  printf("Error type B at Line %d: %s\n",yylineno,msg);
}