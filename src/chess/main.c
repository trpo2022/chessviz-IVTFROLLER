#include <stdio.h>
#include "libchess/printBoard.h"
#include "libchess/graffitiPrint.h"

#define BOARD_ROWS 10
#define BOARD_COLUMNS 10



int main()
{
    graffitiPrint();


    int flag = 1;
    char move[6];


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

    while(flag != 0){
        linePrint();
        printf("\n");
        boardPrint(board);
        printf("\nMove: ");
        for(int i = 0; i < 6;i++){
            scanf("%c", &move[i]);
            if(move[0] == 'q'){
                flag = 0;
                break;
            }
        }

        printf("\nThe move was: %s\n", move);
        
    }

    printf("\n");

    return 0;
}