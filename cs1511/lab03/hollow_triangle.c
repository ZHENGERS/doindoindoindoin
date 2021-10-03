// z5313015, William Zheng

#include<stdio.h>

int main(void) {

    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    int row = 0;
    int column;
    while (row < size)
    {
        column = 0;
        while (column<=row)
        {
            if(column==row || column==0 || row==size-1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
            column++;
        }
        row++;
        printf("\n");
    }
    
    return 0;
}
