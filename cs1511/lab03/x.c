// z5313015, William Zheng

#include <stdio.h>

int main()
{
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    int rows = 1;
    int column;
    while (rows <= size)
    {
        column = 1;
        while (column <= size)
        {
            if (column == rows || column == size - rows + 1)
            {
                printf("*");
            }
            else
            {
                printf("-");
            }
            column++;
        }
        rows++;
        printf("\n");
    }
    return 0;
}
