#include "game.h"

void menu()
{
    printf("**************************\n");
    printf("**** 1. play   0. exit****\n");
    printf("**************************\n");
}

void game()
{
    //*Store checkerboard information
    char board[ROW][COL], ret;
    //*initialize checkerboard
    InitBoard(board, ROW, COL);
    //*Printed board
    DisplayBoard(board, ROW, COL);
    //*play board game
    while (1)
    {
        //*player game player
        PlayerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        //*Determine if the player has won
        ret = IsWin(board, ROW, COL);
        if (ret != 'C')
            break;
        //*The computer to player
        ComputerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        //*Determine if the comperter has won
        ret = IsWin(board, ROW, COL);
        if (ret != 'C')
            break;
    }

    switch (ret)
    {
    case 'O':
        printf("The player won\n");
        break;

    case 'X':
        printf("The computer won\n");
        break;
    default:
        printf("A dead heat\n");
    }
}

void test()
{
    int input;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("please select:>>>");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            printf("Start Game\n");
            game();
            break;

        case 0:
            printf("Quit a Game\n");
            break;

        default:
            printf("Please enter again\n");
        }
    } while (input);
}

int main()
{
    test();
    return 0;
}