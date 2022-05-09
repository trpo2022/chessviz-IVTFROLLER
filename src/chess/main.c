#include <stdio.h>
#include "libchess/printBoard.h"
#include "libchess/graffitiPrint.h"

#define BOARD_ROWS 8
#define BOARD_COLUMNS 8

int pawnWhitePosition[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int pawnBlackPosition[8] = {0, 0, 0, 0, 0, 0, 0, 0};


char board[BOARD_ROWS][BOARD_COLUMNS] = {
                    { 'R' , 'H' , 'B' , 'K' , 'Q' , 'B' , 'H' , 'R' },
                    { 'P' , 'P' , 'P' , 'P' , 'P' , 'P' , 'P' , 'P' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
                    { 'p' , 'p' , 'p' , 'p' , 'p' , 'p' , 'p' , 'p' },
                    { 'r' , 'h' , 'b' , 'k' , 'q' , 'b' , 'h' , 'r' }
                    };



void main()
{
    int  x = 0;
    char ch;
    char firstPlayerName[20];
    char secondPlayerName[20];
    char flag;

    printf("\n\t-> CHESS GAME <- \n");
    printf("\n     Press any button to start \n");

    getchar();
    system("clear");

    printf("Please, enter the name for the first player(No more than 20 symbols): ");
    scanf("%s", firstPlayerName);

    system("clear");

    printf("Please, enter the name for the second player(No more than 20 symbols): ");
    scanf("%s", secondPlayerName);

    system("clear");


    do
    {
        x++ ;
        system("clear") ;
        displayDesk(board);
        while(1){
        if((x % 2) == 0){
            secondPlayerMove(secondPlayerName);
            x++;
            system("clear");
            displayDesk(board);
        }else {
            firstPlayerMove(firstPlayerName);
            x++;
            system("clear");
            displayDesk(board);
        }
    }

    printf( " \n\nPress Enter To Continue ! \n\n " ) ;

    ch = getchar();
    }while( ch == 13 ) ;


}

