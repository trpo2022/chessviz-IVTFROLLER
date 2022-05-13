#include <stdio.h>
#include <stdlib.h>
#include "ctest/ctest.h"
//#include "libchess/displayDesk.h"
//#include "libchess/graffitiPrint.h"

#define BOARD_ROWS 8
#define BOARD_COLUMNS 8

void firstPlayerMove(char[]);
void secondPlayerMove(char[]);
void changePosition(int, int, int, int);
void pawnMove(int, int);
void rookMove(int, int);
void horseMove(int, int);
void bishopMove(int, int);
void kingMove(int, int);
void queenMove(int, int);
void pawnBlackMove(int, int);
void displayDesk();

int checkFirstPosition(int, int);
int checkSecondPosition(int, int);


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

int promtsFlag = 0;


void main()
{
    int  x = 0;
    char ch;
    char firstPlayerName[20];
    char secondPlayerName[20];


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

        printf(" \n\nPress Enter To Continue ! \n\n ");


    ch = getchar();
    }while( ch == 13 );


}

void displayDesk()
{
    int i, j, k; 

    printf(" ");
    for(i = 0; i < 8;i++ )
        printf("    %d", i); 
    printf("\n");

    for(k = 0;k < 8;k++){
        printf("  ");
        for(i = 0;i < 42;i++ ){
            printf("-"); 
        } 
        printf("\n"); 
        printf("%d ", k);

        for(j = 0;j < 8;j++ ){
            printf("|| %c ", board[k][j]);
        }
        printf("|| \n") ;
    }

    printf("  ");

    for(i = 0;i < 42;i++ ){
        printf("-") ; 
        } 
    printf("\n") ;

}

void pawnMove(int r1, int c1) 
{
    pawnWhitePosition[c1]++;

    printf("Available are: \n");

   if(pawnWhitePosition[c1] == 1)      
    {
        if(board[r1 + 1][c1] == ' ')
            printf("%d%d , ", r1 + 1, c1);

        if(board[r1 + 2][c1] == ' ')
            printf("%d%d , ", r1 + 2, c1);

    }else {

        if(board[r1 + 1][c1] == ' ')
            printf("%d%d , ", r1 + 1, c1);

        if(checkFirstPosition(r1 + 1, c1 + 1) == 1)
            printf( "%d%d* , ", r1 + 1, c1 + 1);

        if(checkFirstPosition(r1 + 1, c1 - 1) == 1)
            printf( "%d%d* , ", r1 + 1, c1 - 1);
    }

}

void pawnBlackMove(int r1 ,int c1) 
{
    pawnBlackPosition[c1]++;

    printf("Available are: \n");


    if(pawnBlackPosition[c1] == 1)
    {
        if( board[r1-1][c1] == ' ')
            printf("%d%d , ", r1-1, c1);

        if(board[r1-2][c1] == ' ')
            printf("%d%d , ", r1 - 2, c1);
    }
    else
    {
        if(board[r1-1][c1] == ' ')
            printf("%d%d , ", r1 - 1, c1);

        if(checkSecondPosition(r1 - 1, c1 - 1) == 1)
            printf("%d%d* , ", r1 - 1, c1 - 1);

        if(checkSecondPosition(r1 - 1 , c1 + 1) == 1)
            printf("%d%d* , ", r1 - 1, c1 + 1);
    }

}

void rookMove(int r1, int c1)
{
    int n;

    printf("Available are: \n");

    n = c1;

    printf("Horizontally: \n");

    while(board[r1][n - 1] == ' ')
    {
        if(n ==0){ 
            break;
        }
        printf("%d%d , ", r1, n - 1);
        n--;
    }

    n = c1;

    while(board[r1][n + 1] == ' ' && (n + 1) <= 7)
    {
        printf("%d%d , ", r1, n + 1);
        ++n;
    }

    printf("\nVertically:\n");

    n = r1;

    while(board[n - 1][c1] == ' ' && n > -1)
    {
        printf("%d%d , ", n - 1, c1);
        --n;
    }

    n = r1;

    while((board[n + 1][c1] == ' ') && ((n) <= 7 ))
    {
        printf("%d%d , ", n + 1, c1);
        ++n;
    }

}

void horseMove(int r1, int c1)
{
    printf("Available are: ");


    if( board[r1 + 2][c1 + 1] == ' ' ) 
        printf("%d%d, ", r1 + 2,c1 + 1);

    if(board[r1 + 2][c1 - 1] == ' '){
        if((c1 - 1) > -1) 
            printf("%d%d, " , r1 + 2, c1 - 1); 
    }

    if(board[r1 + 1][c1 + 2] == ' '){  
        if((c1 + 2) != 8) 
            printf("%d%d, ", r1 + 1, c1 + 2); 
    }

    if(board[r1 - 1][c1 + 2] == ' '){  
        printf("%d%d, ", r1 - 1, c1 + 2); 
    }

    if(board[r1 - 2][c1 - 1] == ' ')
    {
        if((c1 - 1) != -1)
        printf("%d%d, ", r1 - 2, c1-1);
    }

    if(board[r1 - 2][c1 + 1] == ' ') 
        printf("%d%d, ", r1 - 2, c1 + 1);

    if(board[r1+1][c1-2] == ' ') 
        printf("%d%d, ", r1 + 1, c1 - 2);

    if(board[r1 - 1][c1 - 2] == ' ')
    {
        if((c1-2) != -1)
            printf("%d%d, ", r1 - 1, c1 - 2);
    }
}


void bishopMove( int r1 , int c1 )
{
    int a, b;
    printf("Available are: \n");


    a = 1;
    b = 1;

    while(board[r1-a][c1+b] == ' ')
    {
        if((r1 - a) == -1 || (c1 + b) == 8) 
            break;
        printf("%d%d , ", r1 - a, c1 + b);
        a++;
        b++;
    }


    a = 1; 
    b = 1;

    while(board[r1+a][c1-b] == ' ')
    {
        if((r1 + a) == 8 || (c1 - b) == -1) 
            break;
        printf("%d%d , ", r1 + a, c1 - b);
        a++;
        b++;
    }

    a = 1;
    b = 1;


    while(board[r1+a][c1+b] == ' ')
    {
        if((r1 + a) == 8 || (c1 + b) == 8) 
            break;
        printf("%d%d , ", r1 + a, c1 + b);
        a++;
        b++;
    }

    a = 1;
    b = 1;

    while(board[r1-a][c1-b] == ' ')
    {
        if((r1 - a) == -1 || (c1 - b) == -1) 
            break;
        printf("%d%d , ", r1 - a, c1 - b);
        a++;
        b++;
    }

}

void kingMove(int r1, int c1)
{
    printf("Available are: ");
    if(board[r1][c1 + 1] == ' ') 
        printf( "%d%d , ", r1, c1 + 1);

    if(board[r1][c1 - 1] == ' ') 
        printf("%d%d , ", r1, c1 - 1);

    if(board[r1 + 1][c1] == ' ') 
        printf("%d%d , ", r1 + 1, c1);

    if(board[r1 - 1][c1] == ' ') 
        printf("%d%d , ", r1 - 1, c1);

    if(board[r1 + 1][c1 + 1] == ' ') 
        printf("%d%d , ", r1 + 1, c1 + 1);

    if(board[r1 - 1][c1 - 1] == ' ') 
        printf("%d%d , ", r1 - 1, c1 - 1);

    if(board[r1 - 1][c1 + 1] == ' ') 
        printf("%d%d , ", r1 - 1, c1 + 1);

    if(board[r1 + 1][c1 - 1] == ' ') 
        printf("%d%d , ", r1 + 1, c1 - 1);
}

void queenMove(int r1, int c1)
{
    int x = 1, y = 1, a, b;
    printf("Available are: ");

    printf("Horizontal: ");

    while(board[r1][c1 - y] == ' ')
    {
        if((c1 - y) == -1) 
            break;
        printf("%d%d , ", r1, c1 - y);
        y++;
    }

    y = 1;

    while(board[r1][c1 + y] == ' ')
    {
        if((c1 + y) == 8) 
            break;
        printf("%d%d , ", r1, c1 + y);
        y++;
    }

    printf("Vertical: ");

    x = 1;

    while(board[r1 - x][c1] == ' ')
    {
        if((r1 - x) == -1) 
            break;
        printf("%d%d , ", r1 - x, c1);
        x++;
    }

    x = 1;

    while(board[r1 + x][c1] == ' ')
    {
        if((r1 + x) == 8) 
            break;
        printf("%d%d , ", r1 + x, c1);
        x++;
    }

    printf("Diagonally: ");

    a = 1; 
    b = 1;

    while(board[r1 - a][c1 + b] == ' ')
    {
        if((r1 - a) == -1 || (c1 + b) == 8) 
            break;
        printf("%d%d , ", r1 - a, c1 + b);
        a++;
        b++;
    }


    a = 1; 
    b = 1;

    while(board[r1 + a][c1 - b] == ' ')
    {
        if((r1  + a) == 8 || (c1 - b) == -1) 
            break;
        printf("%d%d , ", r1 + a, c1 - b);
        a++;
        b++;
    }

    a = 1;
    b = 1;


    while(board[r1 + a][c1 + b] == ' ')
    {
        if((r1 + a) == 8 || (c1 + b) == 8) 
            break;
        printf("%d%d , ", r1 + a, c1 + b);
        a++;
        b++;
    }

    a = 1;
    b = 1;

    while(board[r1 - a][c1 - b] == ' ')
    {
        if((r1 - a) == -1 || (c1 - b) == -1) 
            break;
        printf("%d%d , ", r1 - a, c1 - b);
        a++;
        b++;
    }

}

void changePosition(int r1, int c1, int r2, int c2)
{
    char temp;

    temp = board[r1][c1];
    board[r1][c1] = board[r2][c2];
    board[r2][c2] = temp;

}

void firstPlayerMove(char playerName[])
{
    int p1, p2, c1, r1, c2, r2;


    printf("\n%s's Move - Upper Case\n", playerName);

    again1:
    if(promtsFlag == 0){
        printf("( To move the figure, firstly write the right\n");
        printf("cordinate, then write the left one, beside\n");
        printf("do it with a solid number )\n");

        printf("( Enter '-1' for exit program )\n");
    }

    promtsFlag++;

    printf("\nEnter position of element to change: ");
    scanf("%d" , &p1);
    if(p1 == -1){
        exit(0);
    }


    c1 = p1 % 10;
    r1 = p1 / 10;

    switch(board[r1][c1])
    {
        case 'P': pawnMove(r1, c1);
                  break;
        case 'R': rookMove(r1, c1);
                  break;
        case 'H': horseMove(r1, c1);
                  break;
        case 'C': bishopMove(r1, c1);
                  break;
        case 'K': kingMove(r1, c1);
                  break;
        case 'Q': queenMove(r1 ,c1);
                  break;
        default: printf("\nInvalid move!\nYou cannot go that way or this fugire is not belongs to you.\n") ; goto again1 ;
    }

    printf( "\nEnter Position of Place to Send: ");
    scanf( "%d" , &p2 ) ;

    c2 = p2 % 10 ;
    r2 = p2 / 10  ;


    changePosition(r1,c1,r2,c2);


}

void secondPlayerMove(char playerName[])
{
    int p1, p2, c1, r1, c2, r2;


    printf("\n%s's Move - Lower Case \n", playerName);
    again2:
    if(promtsFlag == 1){
        printf("( To move the figure, firstly write the right\n");
        printf("cordinate, then write the left one, beside\n");
        printf("do it with a solid number )\n");

        printf("( Enter '-1' for exit program )\n");
    }

    promtsFlag++;

    printf("\nEnter position of element to change: ");
    scanf("%d" , &p1);
    if(p1 == -1){
        exit(0);
    }

    c1 = p1 % 10;
    r1 = p1 / 10;

    switch(board[r1][c1])
    {
        case 'p': pawnBlackMove(r1, c1);
                  break;
        case 'r': rookMove(r1,c1);
                  break;
        case 'h': horseMove(r1,c1);
                  break;
        case 'c': bishopMove(r1,c1);
                  break;
        case 'k': kingMove(r1,c1);
                  break;
        case 'q': queenMove(r1, c1);
                  break;
        default: printf("\nInvalid move!\nYou cannot go that way or this fugire is not belongs to you.\n") ; goto again2 ;
    }


    printf("\nEnter Position of Place to Send: ");
    scanf("%d" , &p2);

    c2 = p2 % 10;
    r2 = p2 / 10;


    changePosition(r1,c1,r2,c2);
}

int checkFirstPosition(int x, int y)
{
    switch(board[x][y])
    {
        case 'p':
        case 'r':
        case 'h':
        case 'c':
        case 'k':
        case 'q': return 1 ; break ;
        default: return 0 ;
    }
}

int checkSecondPosition(int x, int y)
{
    switch(board[x][y])
    {
        case 'P':
        case 'R':
        case 'H':
        case 'C':
        case 'K':
        case 'Q': return 1 ; break ;
        default: return 0 ;
    }
}


