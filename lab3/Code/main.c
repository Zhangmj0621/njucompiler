#include <stdio.h>
#include "tree.h"
#include "inter.h"
// extern FILE* yyin;

int main(int argc, char **argv)
{
    if (argc <= 1)
    {
        return 1;
    }
    FILE *f = fopen(argv[1], "r");
    if (!f)
    {
        perror(argv[1]);
        return 1;
    }
    FILE *fw = fopen(argv[2], "w");
    if (!fw)
    {
        perror(argv[2]);
        return 1;
    }
    // 初始化
    initSymbolList();

    yyrestart(f);
    yyparse();
    if (iftrue)
    {
        if (firstNode != NULL)
        {
            dfs(firstNode, 0);
            interCodeList = newInterCodeList();
            genInterCodes(firstNode);
            printInterCode(fw, interCodeList);
        }
    }

    return 0;
}
