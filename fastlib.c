#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void f0(unsigned char* a, char* b, char* c, char* d)
{
    int e = 0;
    int f = 0;
    int g = 0;
    int h = 0;

    while (e < strlen(b))
    {
        switch (b[e])
        {
            case '+':
                a[f]++;
                break;
            case '-':
                a[f]--;
                break;
            case '>':
                f++;
                break;
            case '<':
                f--;
                break;
            case '[':
                if (a[f] == 0)
                {
                    int balance = 0;
                    while (e < strlen(b))
                    {
                        if (b[e]=='[')
                        {
                            balance++;
                        } else if (b[e]==']')
                        {
                            balance--;
                            if (balance == 0)
                            {
                                break;
                            }
                        }
                        e++;
                    }
                    if (balance != 0)
                    {
                        return;
                    }
                }
                break;
            case ']':
                if (a[f] != 0)
                {
                    int balance = 0;
                    while (e >= 0)
                    {
                        if (b[e]==']')
                        {
                            balance++;
                        } else if (b[e]=='[')
                        {
                            balance--;
                            if (balance == 0)
                            {
                                break;
                            }
                        }
                        e--;
                    }
                    if (balance != 0)
                    {
                        return;
                    }
                }
                break;
            case '.':
                d[h++] = a[f];
                break;
            case ',':
                a[f] = c[g++];
                break;
            default:
                break;
        }
        e++;
    }
}

unsigned char f1(unsigned char e)
{
    char a[] = ",>+<[->>+<[>-<-]>[-<+>]<<]>[-<+>]<.";
    char b[1] = {e,};
    char c[1] = {0,};
    unsigned char* d = (unsigned char*)calloc(3, 1);

    f0(d, a, b, c);

    free(d);

    return c[0];
}

unsigned char f2(unsigned char a, unsigned char b)
{
    char c[] = ", >> , << # [->+>-[>+>>#]>[+[-<+>#]>+>>#]<<<<<<#] >>>.";
    char d[2] = {a, b};
    char e[1] = {0,};
    unsigned char* f = (unsigned char*)calloc(7, 1);

    f0(f, c, d, e);

    free(f);

    return e[0];
}

unsigned char f3(unsigned char g, unsigned char h)
{
    char i[] = ", >> , << # [->+>-[>+>>#]>[+[-<+>#]>+>>#]<<<<<<#] >>>>.";
    char j[2] = {g, h};
    char k[1] = {0,};
    unsigned char* l = (unsigned char*)calloc(7, 1);

    f0(l, i, j, k);

    free(l);

    return k[0];
}

unsigned char f4(char* a)
{
    char b[] = ">>+[-,[<<+>>[-]<+>]<[>+<-]>]<<.";
    char c[1] = {0,};
    unsigned char* d = (unsigned char*)calloc(3, 1);

    f0(d, b, a, c);

    free(d);

    return c[0];
}

unsigned char f5(char* a)
{
    char c[] = ">>+[-,[[<<+>>-]<+>]<[>+<-]>]<<.";
    char b[1] = {0,};
    unsigned char* d = (unsigned char*)calloc(3, 1);

    f0(d, c, a, b);

    free(d);

    return b[0];
}

unsigned char f6(unsigned char a, unsigned char b)
{
    char r[] = ",>,<[>[>+>+<<-]>>[<<+>>-]<[>>+<<-]<<-]>>>>.";
    char s[2] = {a, b};
    char t[1] = {0,};
    unsigned char* c = (unsigned char*)calloc(5, 1);

    f0(c, r, s, t);
    free(c);

    return t[0];
}
