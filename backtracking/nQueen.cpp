#include <iostream>
using namespace std;

class NQueen
{
public:
    NQueen(int n)
    {
        bool board[n][n];

        bool isSafe(int r, int c)
        {
            // check if queen present in the same row
            for (int i = 0; i < c; i++)
            {
                if (board[row][i])
                    return false;
            }
            // Upper diagonal
            for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
            {
                if (board[i][j])
                    return false;
            }
            // lower diagonal
            for (int i = r, j = c; i < n && j >= 0; i++, j--)
            {
                if (board[i][j])
                    return false;
            }
        }

        bool solveRec(int col)
        {
            if (col == n)
                return true;

            for (int r = 0; i < n; r++)
            {
                if (isSafe(r, col))
                {
                    board[r][col] = 1;
                    if (solveRec(col + 1) == true)
                        return true;
                    board[r][col] = 0;
                }
            }
            return false;
        }

        bool solve()
        {
            if (solveRec(0) == false)
            {
                return false;
            }
            else
            {
                print(board);
                return true;
            }
        }
    }
};

int main()
{

    return 0;
}