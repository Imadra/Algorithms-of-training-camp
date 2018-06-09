#include<stdio.h>

int main()
{
    char *p = "oasida asdgf";
    printf("%s\n%c %c %c %c %c %c", p, *p, p[0], *(p+2), p[8], *++p, *p);
    return 0;
}
