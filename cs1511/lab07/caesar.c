// William Zheng (z5313015)

#include <stdio.h>
#include <string.h>

#define SIZE 101

void encrypt(char message[SIZE], int key);

int main ()
{
    int key = 0;
    scanf("%d", &key);
    char message[SIZE] = {0};
    while (fgets(message, SIZE, stdin) != NULL) {
        encrypt(message, key);
        /*if (message[strlen(message)-1] == '\n') {
            message[strlen(message)-1] = '\0';
        }*/
        printf("%s", message);
    }
}

void encrypt(char message[SIZE], int key) {
    int i = 0;
    while(message[i] != '\0') {
        if (key < 0) {
            key = 26 - (-1 * key)%26;
        }
        if(message[i] >= 'a' && message[i] <= 'z'){
            message[i] = 'a' + ((message[i] - 'a') + key) % 26;
	    }
	    else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = 'A' + ((message[i] + 'A') + key) % 26;
	    } 
        i++;
    }
}
    
