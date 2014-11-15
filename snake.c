#include<stdio.h>
#include<windows.h>

int board(void); // prints game board on screen
int SL(int a); // snake and ladder logic function
int dice(void); // generates a random number
int start(void);


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
            scanf(" %c", &c);
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
            scanf(" %c", &ch);
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

int board(void) {

    puts("100  99  98  97  96  95  94  93  92  91");
    puts(" 81  82  83  84  85  86  87  88  89  90");
    puts(" 80  79  78  77  76  75  74  73  72  71");
    puts(" 61  62  63  64  65  66  67  68  69  70");
    puts(" 60  59  58  57  56  55  54  53  52  51");
    puts(" 41  42  43  44  45  46  47  48  48  49");
    puts(" 40  39  38  37  36  35  34  33  32  31");
    puts(" 21  22  23  24  25  26  27  28  29  30");
    puts(" 20  19  18  17  16  15  14  13  12  11");
    puts("  1   2   3   4   5   6   7   8   9  10");

    return 0;
}

int SL(int a) {
        if (a == 24) {
            a -= 23;
            printf("\nOoops!! You caught a snake\nYour new position is %d", a);
        } else if (a == 55) {
            a -= 42;
            printf("\nOoops!! You caught a snake\nYour new position is %d", a);
        } else if (a == 71)  {
            a -= 42;
            printf("\nOoops!! You caught a snake\nYour new position is %d", a);
        } else if (a == 88) {
            a -= 21;
            printf("\nOoops!! You caught a snake\nYour new position is %d", a);
        } else if (a == 99) {
            a -= 93;
            printf("\nOoops!! You caught a snake\nYour new position is %d", a);
        } else if (a == 8) {
            a += 23;
            printf("\nGreat!! You caught a ladder\nYour new position is %d", a);
        } else if (a == 15) {
            a += 82;
            printf("\nGreat!! You caught a ladder\nYour new position is %d", a);
        } else if (a == 42) {
            a += 39;
            printf("\nGreat!! You caught a ladder\nYour new position is %d", a);
        } else if (a == 66) {
            a += 21;
            printf("\nGreat!! You caught a ladder\nYour new position is %d", a);
        } else {
            printf("\nYour new position is %d", a);
        }
    return a;
}
int dice(void) {
    int n, num = 0;
    time_t t;
    n = 1;

   //Initializes random number generator
   srand((unsigned) time(&t));

   //Print 5 random numbers from 0 to 49

      num = rand() % 6;
      num++;
    return num;
}
int start(void) {
    int z;
    system("color f3");
    MessageBox(0,"Welcome to \"SNAKE AND LADDER GAME\"\nPress OK to continue...","The Board Game" ,1);
    printf("\n\n\nLOADING");
    for (z=0;z<30;z++) {
        Sleep(100);
        printf(".");
    }
    Sleep(400);
    system("cls");
    return 0;
}






