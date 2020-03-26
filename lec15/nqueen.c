#include <stdio.h>
/*
 * Solve 4x4 n Queen problem using recursion with backtracking
 */

#define N 4
#define true 1
#define false 0

void printSolution(int board[N][N]);
// Solve N-queen probelm by placing (N-row) queens starting from row 
int Solve(int board[N][N], int row);
// Utility function to check if a queen can be placed on board[row][col]
int isSafe(int board[N][N], int row, int col);

int main()
{
    //int board[N][N] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    int board[N][N] = {0};

    if(Solve(board, 0) == false)
        printf("Solution does not exist. \n");

    printf("solution is\n");
    printSolution(board);
}

int Solve(int board[N][N], int row)
{
    int j;//index for column
    if(row == N)
        return true;
    else{
        for(j=0;j<N;j++){
            if(isSafe(board, row, j) == true){
                board[row][j] = 1;
                // increment row to place the next queen
                if(Solve(board, row+1)== true)
                    return true;
                else
                    board[row][j] = 0; //remove the queen
            }
        }
        return false;
    }
}

int isSafe(int board[N][N], int row, int col)
{
    int i,j;

    // Check this col on upper side
    for(i=0; i<row; i++)
    {
        if(board[i][col] == 1)
            return false;
    }
    // Check upper diagonal on left side
    for(i=row, j=col; i>=0 && j>=0 ; i--, j--)
    {
        if(board[i][j] == 1)
            return false;
    }
    // Check upper diagonal on right side
    for(i=row, j=col; i>=0 && j<N ; i--, j++)
    {
        if(board[i][j] == 1)
            return false;
    }
    return true;
}

void printSolution(int board[N][N])
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
    printf("\n");
}

