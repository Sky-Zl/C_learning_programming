#include <iostream>
#include<cstring>

using namespace std;

void revertWord(char *p, char *p1)
{
    char c;
    for (; p < p1; p++, p1--) {
        c = *p;
        *p = *p1;
        *p1 = c;
    }
}

void revert(char *p) 
{
    char *p1;
    while (*p && *p == ' ')
        p++;
    if (!*p)
        return;
    p1 = p;
    while (*p && *p != ' ')
        p++;
    revertWord(p1, p - 1);
    revert(p);
}

int main() 
{
    char line[] = "hello world.";
    revert(line);
    printf("%s\n", line);
    return 0;
}

