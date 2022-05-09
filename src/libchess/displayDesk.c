#include <stdio.h>

#define BOARD_ROWS 8
#define BOARD_COLUMNS 8


void displayDesk(char board[][])
{
    int i, j, k; 

    printf(" ") ;
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