// William Zheng (z5313015)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 10000

void changeLower(int numOfInputs, char inputs[MAX_LENGTH]);

int main(int argc, char *argv[]) {
    int i = 1;
    while (i < argc) {
        changeLower(argc, argv[i]);
        printf("%s", argv[i]);
        printf(" ");
        i++;
    }
    printf("\n");
    return 0;
}

void changeLower(int numOfInputs, char inputs[MAX_LENGTH]) {
    int len = strlen(inputs);
    int i = 0;
    while (i < len) {
        if (inputs[i] >= 'A' && inputs[i] <= 'Z') {
            inputs[i] += 32;
        }
        i++;
    }
}

