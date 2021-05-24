#include <stdio.h>

void update(int *a, int *b)
{
    int aa=*a;
    *a=aa+*b;
    *b=aa-*b;

    if(*b<0)
    {
        *b *=-1;
    }
}

int main()
{
    int a, b;
    int *pa=&a, *pb=&b;

    scanf("%d %d",&a,&b);
    update(pa,pb);
    printf("%d\n%d",a,b);

    return 0;
}
