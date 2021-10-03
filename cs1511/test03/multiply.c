// z5313015, William Zheng

#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    
    if ((a>0 && b>0) || (a<0 && b<0))
    {
        printf("%d\n", a*b);
    }
    else if ((a<0 && b==0) || (b<0 && a==0))
    {
        printf("zero\n");
    }
    else if ((a==0 && b==0) || (a==0 || b==0))
    {
        printf("zero\n");
    }
    else if (a<0 || b<0)
    {
        printf("%d\n", -1*(a*b));
    }
    

    return 0;
}
