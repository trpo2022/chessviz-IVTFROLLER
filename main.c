#include <stdio.h>

#define BOARD_ROWS 10
#define BOARD_COLUMNS 10



int main()
{
    char board[BOARD_ROWS][BOARD_COLUMNS]
            = {{'8', '|', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'7', '|', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
               {'6', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'5', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'4', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'3', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'2', '|', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
               {'1', '|', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
               {' ', ' ', '_', '_', '_', '_', '_', '_', '_', '_'},
               {' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'},
               };

    printf("\n");


    for (int i = 0; i < BOARD_ROWS; i++) {
        for (int j = 0; j < BOARD_COLUMNS; j++) {
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}