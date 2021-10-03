// Author: William Zheng, z5313015
// Date: 11/07/2020
// UNSW Freefall assignment.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 15
#define MAX_NEGATIVE_INDEX 150
#define EMPTY 0
#define MOVE_PLAYER 1
#define MOVE_RIGHT 1
#define MOVE_LEFT -1
#define STONE 1
#define LASER 2
#define FLIP_MAP 4
#define MOVE_STONES 3

void printMap(int map[SIZE][SIZE], int playerX);
void placeStones(int map[SIZE][SIZE], int numLines, int playerX, int 
aboveMap[SIZE][SIZE]);
void fireLaser(int map[SIZE][SIZE], int playerX);
void moveStonesDown(int map[SIZE][SIZE]);
void shiftAboveMap(int map[SIZE][SIZE], int aboveMap[MAX_NEGATIVE_INDEX][SIZE]);
void checkWin(int map[SIZE][SIZE]);
int checkLose(int map[SIZE][SIZE]);
void verticalFlip(int map[SIZE][SIZE], int commandOne);
int findTntSize(int map[SIZE][SIZE], int playerX);
int findTntRow(int map[SIZE][SIZE], int playerX); 
void useTntBlock(int map[SIZE][SIZE], int playerX);
void marchLeft(int map[SIZE][SIZE]);
void marchRight(int map[SIZE][SIZE]);

int main (void) {
    // Create an empty 2d array for map.
    int map[SIZE][SIZE] = {EMPTY};
    int aboveMap[MAX_NEGATIVE_INDEX][SIZE] = {EMPTY};

    // Create a player starting in the middle.
    int playerX = SIZE / 2;

    // Scan in the number of lines of stone the user wishes to input.
    int numLines;
    printf("How many lines of stone? ");
    scanf("%d", &numLines);

    printf("Enter lines of stone:\n");
    placeStones(map, numLines, playerX, aboveMap);
    printMap(map, playerX);

    int commandOne, commandTwo;
    int flipCounter = 0;
    // Main game loop, takes in commands then prints the map each time.
    // Scans in commands until EOF.
    while (scanf("%d", &commandOne) == 1) {
        if (commandOne == LASER) {
            fireLaser(map, playerX);
            printMap(map, playerX);
            checkWin(map);
        }
        else if (commandOne == MOVE_STONES) {
            // Checks if checkLose returns any stones on the last row,
            // if not then move all stones down.
            if (checkLose(map) > 0) {
                printMap(map, playerX);
                printf("Game Lost!\n");
                exit(0);
            }
            else {
                moveStonesDown(map);
                shiftAboveMap(map, aboveMap);
                printMap(map, playerX);
            }
        }
        else if (commandOne == FLIP_MAP) {
            if (flipCounter == 0) {
                verticalFlip(map, commandOne);
                printMap(map, playerX);
            }
            else {
                printMap(map, playerX);               
            }
            // Increase the value of flipCounter after the first flip
            // so that it can only be used once.
            flipCounter++;
        }
        else if (commandOne == MOVE_PLAYER) {
            scanf("%d", &commandTwo);
            // Scans in another command to determine which direction 
            // the player will move.    
            if (commandTwo == MOVE_RIGHT) {
                playerX++;
                printMap(map, playerX);
            }
            else if (commandTwo == MOVE_LEFT) {          
                playerX--;
                printMap(map, playerX);
            }
            // Leave map unchanged if no conditions for commandTwo are true.
            else {
                printMap(map, playerX);
            }
        }
        // Leave map unchanged if no conditions for commandOne are true.
        else {
            printMap(map, playerX);
        }
    }
    return 0;
}

// Print out the contents of the map array. Then print out the player line
// which will depends on the playerX variable.
void printMap(int map[SIZE][SIZE], int playerX) {
    // Print values from the map array.
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            printf("%d ", map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }    
    
    // Print the player line.
    i = 0;
    while (i < playerX) {
        printf("  ");
        i++;
    }
    printf("P\n");
}

// Scans in inputs of lines from user, then prints the line onto the map
// or above the map.
void placeStones(int map[SIZE][SIZE], int numLines, int playerX, int 
aboveMap[MAX_NEGATIVE_INDEX][SIZE]) {
    int row, column, length, value;
    int negativeRow;
    int lineCounter = 0;
    while (lineCounter < numLines) {
        scanf("%d %d %d %d", &row, &column, &length, &value);
        int stoneEnd = column + length - 1;
        // Goes back to start of loop is stones are outside the columns of 
        // the map or above the map.
        if (column < 0 || (stoneEnd >= SIZE)) {
            lineCounter++;
            continue;
        }
        // Places stones above the map by converting the negative index to 
        // an index on aboveMap, then places the stones on aboveMap.
        if (row < 0 && column >= 0) {
            negativeRow = SIZE - (-1 * row);
            while (column <= stoneEnd) {
                aboveMap[negativeRow][column] = value;
                column++;
            }
        }
        // Places stones on the map.
        else {
            while (column <= stoneEnd) {
                map[row][column] = value; 
                column++;       
            }
        }
        lineCounter++;        
    }
}

// Fires the laser at the map straight up from the 
// position of playerX.
void fireLaser(int map[SIZE][SIZE], int playerX) {
    int col = playerX;
    int row = SIZE-1;
    int stoneCounter = 0;
    // Loop from the last row to the first row of the array
    // in the column which playerX lies.
    while (row >= 0) {
        if (map[row][col] == 1 || map[row][col] == 2) {
            map[row][col] = EMPTY;
            stoneCounter++;
        }
        // Tnt explodes if laser hits a tnt block.
        if (map[row][col] >= 3 && map[row][col] <= 9) {
            useTntBlock(map, playerX);
            stoneCounter = 3;
        }
        // Ensures the laser only fires through 3 stones at a time.
        if (stoneCounter == 3) {
            stoneCounter = 0;
            row = SIZE-1;
            return;
        }
        row--;
    }
}

// Moves all stones on map down one position on the map by looping
// from the botttom row to the top of each column.
void moveStonesDown(int map[SIZE][SIZE]) {
    int col = 0;
    while (col < SIZE) {
        int row = SIZE-1;
        while (row >= 0) {
            if (map[row][col] != EMPTY && row < SIZE-1) {
                map[row+1][col] = map[row][col];
                map[row][col] = EMPTY;
            }
            if (row == SIZE-1) {
                map[row][col] = EMPTY;
            }
            row--;
        }
        col++;
    }
}

// Moves all blocks above the map one position down in aboveMap, but copying 
// them to the top of map if there are stones on the last row.
void shiftAboveMap(int map[SIZE][SIZE], int aboveMap[MAX_NEGATIVE_INDEX][SIZE]) {
    int col = 0;
    while (col < SIZE) {
        int row = SIZE-1;
        while (row >= 0) {
            if (aboveMap[row][col] != EMPTY && row == SIZE-1) {
                map[0][col] = aboveMap[row][col];
                aboveMap[row][col] = EMPTY;
            }
            else {
                aboveMap[row+1][col] = aboveMap[row][col];
                aboveMap[row][col] = EMPTY;
            }   
            row--;
        }
        col++;
    }   
}

// Checks if the player has won the game, i.e. no stones on the map,
// by using countStones to count the number of stones on the map.
void checkWin(int map[SIZE][SIZE]) {
    int row = 0;
    int countStones = 0;
    while (row < SIZE) {
        int col = 0;
        while (col < SIZE) {
            if (map[row][col] != 0) {
                countStones++;
            }
            col++;
        }
        row++;
    }
    if (countStones == 0) {
        printf("Game Won!\n");
        exit(0);
    }
}

// Checks if the player is about to lose the game by returning 
// the number of stones on the last row of the map.
int checkLose(int map[SIZE][SIZE]) {
    int row = 0;
    // Counts the number of stones on the last row.
    int stoneCounter = 0;
    while (row < SIZE) {
        int col = 0;
        while (col < SIZE) {
            if (map[row][col] != 0 && row == SIZE-1) {
                stoneCounter++;
            }
            col++;
        }
        row++;
    }
    // Returns the number of stones to main, if greater than zero
    // dont move the stones down and game is lost.
    return stoneCounter;
}

// Vertically flips the map by copying the flipped values of the stones onto an
// empty array of same size, then copying this temporary array back onto the map.
void verticalFlip(int map[SIZE][SIZE], int commandOne) {
    int col = 0;
    int mapCopy[SIZE][SIZE] = {0};
    // Loops through map and copy all stones flipped onto mapCopy.
    while (col < SIZE) {
        int row = 0;
        while (row < SIZE) {
            if (map[row][col] != EMPTY) {
                mapCopy[SIZE-1-row][col] = map[row][col];
            }
            row++;
        }
        col++;
    }
    // Loops through mapCopy and copys all the flipped stones 
    // back onto the original map.
    int colCopy = 0;
    while (colCopy < SIZE) {
        int rowCopy = 0;
        while (rowCopy < SIZE) {
            map[rowCopy][colCopy] = mapCopy[rowCopy][colCopy];
            rowCopy++;
        }
        colCopy++;
    }
}

// Finds the value of tnt block in the same column as playerX (if there is one)
// and returns it to the useTntBlock function.
int findTntSize(int map[SIZE][SIZE], int playerX) {
    int col = playerX;
    int row = SIZE-1;
    int tntBlock = 0;
    while (row >= 0) {
        if (map[row][col] >= 3 && map[row][col] <= 9) {
            tntBlock = map[row][col];
            row = 0;
        }
        row--;
    }
    return tntBlock;
}

// Finds the row of the tnt block in the same column as playerX (if there 
// is one) and returns it to the useTntBlock function.
int findTntRow(int map[SIZE][SIZE], int playerX) {
    int col = playerX;
    int row = SIZE-1;
    int tntRow = 0;
    while (row >= 0) {
        if (map[row][col] >= 3 && map[row][col] <= 9) {
            tntRow = row;
            row = 0;
        }
        row--;
    }
    return tntRow;
}

// Explodes the tnt block if hit, creating a circle around the block with a 
// radius of the size of the tnt block.
void useTntBlock(int map[SIZE][SIZE], int playerX) {
    int tntRow = findTntRow(map, playerX);
    int tntSize = findTntSize(map, playerX);
    int tntCol = playerX;
    int row = 0;
    // Loops through the entire map and sets any blocks within the circle to 0.
    while (row < SIZE) {
        int col = 0;
        while (col < SIZE) {
            double distanceFromTnt = sqrt((col - tntCol) * (col - tntCol) + 
                                          (row - tntRow) * (row - tntRow));
            // Checks if the distance from the tnt to the block is less 
            // than the tnt value.
            if (distanceFromTnt < tntSize) {
                map[row][col] = EMPTY;
            }
            col++;
        }
        row++;
    }
}

// Moves marching blocks one position left on the map.
// NOTE: Did not use this function.
void marchLeft(int map[SIZE][SIZE]) {
    int row = 0;
    while (row < SIZE) {
        int col = 0;
        while (col < SIZE) {
            if (map[row][col] == 2) {
                map[row][col-1] = map[row][col];
                map[row][col] = EMPTY;
            }
            col++;
        }
        row++;    
    }
}

// Moves marching blocks one position right on the map.
// NOTE: Did not use this function.
void marchRight(int map[SIZE][SIZE]) {
    int row = 0;
    while (row < SIZE) {
        int col = SIZE-1;
        while (col >= 0) {
            if (map[row][col] == 2) {
                map[row][col+1] = map[row][col];
                map[row][col] = EMPTY;
            }
            col--;
        }
        row++;
    }
}

