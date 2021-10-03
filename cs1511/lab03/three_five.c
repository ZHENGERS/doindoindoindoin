// z5313015, William Zheng

#include <stdio.h>

int main(void) {
    
    int num;
    printf("Enter number: ");
    scanf("%d", &num);
    int i = 1;
    while (i < num)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            printf("%d\n", i);

        }
        i++;
    }
    
    
    
    return 0;
}
