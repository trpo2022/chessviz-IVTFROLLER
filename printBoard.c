#include <stdio.h>

#define BOARD_ROWS 10
#define BOARD_COLUMNS 10


void boardPrint(char board[BOARD_ROWS][BOARD_COLUMNS])
{
    for (int i = 0; i < BOARD_COLUMNS; i++) {
        for (int j = 0; j < BOARD_ROWS; j++) {
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }

}

void linePrint()
{
    printf("_____________________\n");
}