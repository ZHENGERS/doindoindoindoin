// William Zheng (z5313015)
#include<stdio.h>
#include<string.h>

#define ALPHA_SIZE 27
#define SIZE 101

void remap(char newLetters[ALPHA_SIZE], char message[SIZE]);

int main(void) {
    char newAlpha[ALPHA_SIZE] = {0};
    fgets(newAlpha, ALPHA_SIZE, stdin);
    char message[SIZE] = {0};
    fgets(message, SIZE, stdin);
    while (fgets(message, SIZE, stdin) != NULL) {
        remap(newAlpha, message);
        //message[strlen(message)-1] = '\0';                  
        printf("%s", message);
    }

    return 0;
}

void remap(char newLetters[ALPHA_SIZE], char message[SIZE]) {
    int count = strlen(message);   
    int i = 0;
    while (i < count) {
        if (message[i]>='a' && message[i]<='z') {
            int index = message[i] - 97;  
            message[i] = newLetters[index];          
        }
        else if (message[i]>='A' && message[i]<='Z') {
            int index = message[i] - 65;  
            message[i] = newLetters[index] - 32;                  
        }
        else {
            message[i] = message[i];
        }
        i++;
    }
}
