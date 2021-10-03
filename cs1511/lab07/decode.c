// William Zheng (z5313015)

#include <stdio.h>
#include <string.h>

#define ALPHA_SIZE 27
#define SIZE 101

void decode(char newLetters[ALPHA_SIZE], char message[SIZE]);

int main(void) {
    char newAlpha[ALPHA_SIZE] = {0};
    fgets(newAlpha, ALPHA_SIZE, stdin);
    char message[SIZE] = {0};
    fgets(message, SIZE, stdin);
    while (fgets(message, SIZE, stdin) != NULL) {
        decode(newAlpha, message);
        //message[strlen(message)-1] = '\0';                  
        printf("%s", message);
    }
}

void decode(char newLetters[ALPHA_SIZE], char message[SIZE]) {
    char alpha[ALPHA_SIZE] = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
                              'n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int count = strlen(message);
    int i = 0;
    int index = 0;
    while (i < count) {
        if (message[i]>='a' && message[i]<='z') {
            int j = 0;
            while (j < ALPHA_SIZE) {
                if (newLetters[j]==message[i]) {
                    index = j; 
                }
                j++;
            }
            message[i] = alpha[index];              
        }
        else if (message[i]>='A' && message[i]<='Z') {
           int j = 0;
            while (j < ALPHA_SIZE) {
                if (newLetters[j]==message[i]+32) {
                    index = j; 
                }
                j++;
            }
            message[i] = alpha[index]-32;                
        }
        i++;
    }
}
