// z5313015, William Zheng

#include<stdio.h>

int main(void) {
    
    int rows;
    printf("Enter size: ");
    scanf("%d",&rows);
    int i=1;
    int j;
    while (i<=rows) 
    {
        j = 1;
        while (j<=rows)
        {
            if (i==1 || i==rows)
            {
                printf("*");
            }
            j++;
        }
        i++;
        printf("\n");
    }
    
    return 0;
}
