#include<stdio.h>
#define false 0
#define true 1
void printSolution(int board[100][100], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}
int isSafe(int board[100][100], int row, int col,int N)
{
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;
    for (i=row, j=col; j>=0 && i<N; i++, j--)
        if (board[i][j])
            return false;
 
    return true;
}
int solveNQUtil(int board[100][100], int col,int N)
{
    if (col >= N)
        return true;
    for (int i = 0; i < N; i++)
    {
        if ( isSafe(board, i, col,N) )
        {
            board[i][col] = 1;
            if ( solveNQUtil(board, col + 1,N) )
                return true;
            board[i][col] = 0; 
        }
    }
    return false;
}
int solveNQ()
{
    printf("enter the numner of queens:\n");
    int N;
    scanf("%d",&N);
    int board[100][100];
    if ( solveNQUtil(board, 0,N) == false )
    {
      printf("Solution does not exist");
      return false;
    }
 
    printSolution(board,N);
    return true;
}
int main()
{
    solveNQ();
    return 0;
}