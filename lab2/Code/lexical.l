%option yylineno

%{
    #include "syntax.tab.h"
    #include "tree.h"
    #include<stdio.h>
    #include<stdlib.h>
    int yycolumn = 1;
    #define YY_USER_ACTION \
      yylloc.first_line = yylloc.last_line = yylineno; \
      yylloc.first_column = yycolumn; \
      yylloc.last_column = yycolumn + yyleng - 1; \
      yycolumn += yyleng;
%}

newline   \n
ws        [ \t\n]+
digit     [0-9]
letter_    [_a-zA-Z]

SEMI      ";"
COMMA     ","
ASSIGNOP  "="
RELOP     ">"|"<"|">="|"<="|"=="|"!="
PLUS      "+"
MINUS     "-"
STAR      "*"
DIV       "/"
AND       "&&"
OR        "||"
DOT       "."
NOT       "!"
TYPE      "int"|"float"
LP        "("
RP        ")"
LB        "["
RB        "]"
LC        "{"
RC        "}"
STRUCT    "struct"
RETURN    "return"
IF        "if"
ELSE      "else"
WHILE     "while"

DEC       0|[1-9]{digit}*
OCT       0[1-7][0-7]*
HEX       0[xX][0-9a-fA-F]+
INT       {DEC}|{OCT}|{HEX}

GEN_FLOAT {digit}+\.{digit}+
SCI_FLOAT ({digit}*\.{digit}+|{digit}+\.{digit}*)[eE][+-]?{digit}+
FLOAT     {GEN_FLOAT}|{SCI_FLOAT}

ID        {letter_}({letter_}|{digit})*

%%
{newline}  {yycolumn = 1;}
{ws}       {}
{SEMI}     {yylval.type_node=addNode("SEMI",0,yylineno);return SEMI;}
{COMMA}    {yylval.type_node=addNode("COMMA",0,yylineno);return COMMA;}
{ASSIGNOP} {yylval.type_node=addNode("ASSIGNOP",0,yylineno);return ASSIGNOP;}
{RELOP}    {yylval.type_node=addNode("RELOP",0,yylineno);return RELOP;}
{PLUS}     {yylval.type_node=addNode("PLUS",0,yylineno);return PLUS;}
{MINUS}    {yylval.type_node=addNode("MINUS",0,yylineno);return MINUS;}
{STAR}     {yylval.type_node=addNode("STAR",0,yylineno);return STAR;}
{DIV}      {yylval.type_node=addNode("DIV",0,yylineno);return DIV;}
{AND}      {yylval.type_node=addNode("AND",0,yylineno);return AND;}
{OR}       {yylval.type_node=addNode("OR",0,yylineno);return OR;}
{DOT}      {yylval.type_node=addNode("DOT",0,yylineno);return DOT;}
{NOT}      {yylval.type_node=addNode("NOT",0,yylineno);return NOT;}
{TYPE}     {yylval.type_node=addNode("TYPE",0,yylineno);return TYPE;}
{LP}       {yylval.type_node=addNode("LP",0,yylineno);return LP;}
{RP}       {yylval.type_node=addNode("RP",0,yylineno);return RP;}
{LB}       {yylval.type_node=addNode("LB",0,yylineno);return LB;}
{RB}       {yylval.type_node=addNode("RB",0,yylineno);return RB;}
{LC}       {yylval.type_node=addNode("LC",0,yylineno);return LC;}
{RC}       {yylval.type_node=addNode("RC",0,yylineno);return RC;}
{STRUCT}   {
  yylval.type_node=addNode("STRUCT",0,yylineno);
  stackTop++;
  maxStructNum++;
  structNumStack[stackTop]=maxStructNum;
  structopttagline[stackTop]=yylineno;
  stackIndexTop++;
  structIndexStack[stackIndexTop]=0;
  return STRUCT;}
{RETURN}   {yylval.type_node=addNode("RETURN",0,yylineno);return RETURN;}
{IF}       {yylval.type_node=addNode("IF",0,yylineno);return IF;}
{ELSE}     {yylval.type_node=addNode("ELSE",0,yylineno);return ELSE;}
{WHILE}    {yylval.type_node=addNode("WHILE",0,yylineno);return WHILE;}

{INT}      {yylval.type_node=addNode("INT",0,yylineno);return INT;}
{FLOAT}    {yylval.type_node=addNode("FLOAT",0,yylineno);return FLOAT;}
{ID}       {yylval.type_node=addNode("ID",0,yylineno);return ID;}
.          {iftrue=0; printf("Error type A at Line %d: Mysterious characters \'%s\'\n",yylineno,yytext);}
%%

