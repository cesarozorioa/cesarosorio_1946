#include <stdio.h>
main()
{
    int a = 1;
    int b(2);
    int c{3};
    int d = {4};
    int e = int(5);
    printf("a=%d,b=%d,c=%d,d=%d,e=%d\n",a,b,c,d,e);
}