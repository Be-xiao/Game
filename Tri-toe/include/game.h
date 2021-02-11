#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3

//*statement
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);

/*
*The player won - 'O'
*The computer won - 'X'
*A dead heat - 'D'
*countine - 'C'
*/
char IsWin(char board[ROW][COL], int row, int col);