#include "common.h"

int value(char c)
{
    switch (c)
    {
    case '0':return 0;
    case '1':return 1;
    case '2':return 2;
    case '3':return 3;
    case '4':return 4;
    case '5':return 5;
    case '6':return 6;
    case '7':return 7;
    case '8':return 8;
    case '9':return 9;
    case 'a':case 'A':return 10;
    case 'b':case 'B':return 11;
    case 'c':case 'C':return 12;
    case 'd':case 'D':return 13;
    case 'e':case 'E':return 14;
    case 'f':case 'F':return 15;
    default:return -1;
    }
}

int pow(int x, int y)
{
    int res = x;
    for (int i = 0; i < y - 1; i++)
    {
        res *= x;
    }
    return res;
}

int stoi(const char *str)
{
    int res = 0;
    int k = 10;//default dec
    int n = 1;
    int len = strlen(str);
    //HEX
    if(len > 2 && str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
    {
        k = 16;
        for (int i = len - 1; i >= 2; i--)
        {
            res += value(str[i]) * n;
            n *= k;
        }
    }
    //OCT
    else if(len > 1 && str[0] == '0')
    {
        k = 8;
        for (int i = len - 1; i >= 1; i--)
        {
            res += value(str[i]) * n;
            n *= k;
        }
    }
    //DEC
    else
    {
        k = 10;
        for (int i = len - 1; i >= 0; i--)
        {
            res += value(str[i]) * n;
            n *= k;
        }        
    }
    return res;
}

float stof(const char *str)
{
    int i = 0;
    int flag = 0;
    int expn = 0;
    float res = 0;
    float power = 1;
    int len = strlen(str);

    for (;str[i] != '.';i++)
    {
        res = res * 10 + value(str[i]);
    }
    if(str[i] == '.')i++;
    for (;str[i] != 'e' && str[i] != 'E' && i < len;i++)
    {
        res = res * 10 + value(str[i]);
        flag++;
    }
    if(i == len)
    {
        power = pow(10, flag);
        return res / power;
    }
    if(str[i] == 'e' || str[i] == 'E')
    {
        i++;
        if (str[i] == '-')
        {
            i++;
            for (;i < len;i++)
            {
                expn = expn * 10 + value(str[i]);
                expn += flag;
                power = pow(10, expn);
                return res / power;
            }
        }
        else
        {
            if(str[i] == '+')i++;
            for (; i < len; i++)
            {
                expn = expn * 10 + value(str[i]);
                expn -= flag;
                power = pow(10, expn);
                return res * power;
            }            
        }
    }
    return 0.0f;
}
