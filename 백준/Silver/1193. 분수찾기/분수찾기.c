#include<stdio.h>
int main(void)
{
    int num, i;
    scanf("%d", &num);
    for (i = 0; i < num; i++)
        num -= i;
    if(i%2==0) printf("%d/%d\n", num, (i + 1 - num));
    else printf("%d/%d\n",(i+1-num), num);
}