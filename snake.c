#include<stdio.h>
#include "myHeaders/general.h"


int main(void) {
    char p1[50], p2[50];
    int position = 0, position1 = 0;
    char c = '\0', ch = '\0';
    start();
    printf("Enter the name of Player 1 : ");scanf("%s", &p1);
    printf("Enter the name of Player 2 : ");scanf("%s", &p2);
    Sleep(300);
    system("cls");
    board(); // prints game board on screen




    // game loop begins now
    while (position < 100 && position1 < 100) {

        do {
            printf("\n %s's turn ", p1);
            printf("\nPress \" R \" to roll the dice : ");
            c = getchar();
        } while (c != 'r' && c != 'R');


        if (c == 'r' || c == 'R') {
            position += dice();
            printf("\nYour dice rolled to %d", dice());
        }

        position = SL(position); // snake and ladder logic function
        if (position >= 100) {break;} // P1 wining condition
        printf("\n");

        do {
            printf("\n %s's turn ", p2);
            printf("\nPress \" R \" to roll the dice : ");
            ch = getchar();
        } while (ch != 'r' && ch != 'R');

        if (ch == 'r' || ch == 'R') {
            position1 += dice();
            printf("\nYour dice rolled to %d", dice());
        }

        position1 = SL(position1);

        printf("\n");


    } // end of while loop

    // game ending part
    if (position >= 100) {
        printf("\n\nCONGRATS %s!!! YOU WON THE GAME\n", p1);
    }
    if (position1 >= 100) {
        printf("\n\nCONGRATS %s!!! YOU WON THE GAME\n", p2);
    }



    getchar();
    getchar();
    return 0;
}







