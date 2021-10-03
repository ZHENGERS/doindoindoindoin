// z5313015, William Zheng

#include <stdio.h>

int main(void) {
    
    double a, b, c;
    printf("Please enter three numbers: ");
    scanf("%lf %lf %lf", &a,&b,&c);
    
    //if a<b<c then up
    if (a<b && b<c)
    {
        printf("up\n");
    }
    //if a>b>c then down
    else if (a>b && b>c)
    {
        printf("down\n");
    }
    //everything else neither
    else
    {
        printf("neither\n");
    }
    return 0;
}
