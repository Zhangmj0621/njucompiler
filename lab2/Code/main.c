#include <stdio.h>
#include "tree.h"
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
    // 初始化
    initSymbolList();

    yyrestart(f);
    yyparse();
    // if (iftrue)
    // {
    //     if (firstNode != NULL)
    //         dfs(firstNode, 0);
    // }

    return 0;
}
