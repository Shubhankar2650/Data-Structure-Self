#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> & board, int val){
    for(int i = 0; i< board.size(); i++){
        // check the row
        if(board[row][i]== val) return false;

        // check the column 
        if(board[i][col] == val) return false;

        // check the cell of the size 9
        if(board[3 * (row/3) + i/3][3* (col/ 3) + i%3] == val) return false;

    }
    return true;
}

bool sudokuSolver(vector<vector<int>> & board){
    int n = board.size();
    
    for(int i = 0; i< n; i++){
        for(int j = 0; j<n; j++){
            if(board[i][j] == 0){
                for(int val = 0; val<n; val++){
                    if(isSafe(i,j,board,val)){
                        board[i][j] = val;

                        bool AgeePossibleHai = sudokuSolver(board);
                        if(!AgeePossibleHai){
                            // backtrack 
                            board[i][j] = 0;
                            return false;
                        }else return true;
                    }
                }
                return false;
            }
        }
    }
    return true;
}


int main()
{
    
    return 0;
}