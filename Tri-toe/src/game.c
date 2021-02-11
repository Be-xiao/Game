#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        //*Print one line of data
        for (int j = 0; j < col; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < col - 1)
                printf("|");
        }
        printf("\n");
        //*Print split line
        if (i < row - 1)
            for (int j = 0; j < col; j++)
            {
                printf("---");
                if (j < col - 1)
                    printf("|");
            }
        printf("\n");
    }
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
    int x, y;
    printf("Ask players to play chess\n");
    while (1)
    {
        printf("Please enter coordinater:>>>");
        scanf("%d%d", &x, &y);
        //*Judge the rationality of the coordinates
        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if (board[x - 1][y - 1] == ' ')
            {
                board[x - 1][y - 1] = 'O';
                break;
            }
            else

                printf("The coordinates are already in use\n");
        }
        else
            printf("Unreasonable coordinates,Please enter again\n");
    }
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
    int x, y;
    printf("The Computer to play chess\n");

    while (1)
    {
        x = rand() % row;
        y = rand() % col;
        if (board[x][y] == ' ')
        {
            board[x][y] = 'X';
            break;
        }
    }
}

//*return '1' the checkerboard is full
//*return '0' the checkerboard is not full
int IsFull(char board[ROW][COL], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(board[i][j] == ' ')
                return 0;
        }   
    }
    return 1;
}

char IsWin(char board[ROW][COL], int row, int col)
{
    //*Cross three  lines
    for (int i = 0; i < row; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
            return board[i][1];
    }

    //*Vertical three columns
    for (int i = 0; i < col; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
            return board[1][i];
    }

    //*Two diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board [2][2] && board [1][1] != ' ')
        return board[1][1];
    if(board[2][0] == board[1][1] && board[1][1] == board [0][2] && board [1][1] != ' ')
        return board[1][1];

    //*Decide if it's a tie
    if(1 == IsFull(board,ROW,COL))
        return 'Q';

    return 'C';
}