#include <iostream>
#include<vector>
using namespace std;

// class sol{
//     private:


//     public:
//         bool ratMaze(vector<vector<int>> v){
//             vector<vector<int>> chk;
//             for(int i = 0; i<v.size(); i++){
//                 for(int j = 0; j<v[i].size(); j++){
//                     chk[i][j] = 0;
//                 }
//             }
//             int c = v[0].size(),
//                 r = v.size();
//             int i = 0, j= 0;
//             while(i<c && j<r){
//                 if(i == c-1 && j == r-1){
//                     return true;
//                 }
//                 if(i+1 <c && chk[i+1][j] == 0){
//                 chk[i+1][j] = 1;
//                 i++;
//                 }
//                 if(j+1 <r && chk[i][j+1] == 0){
//                     chk[i][j+1] = 1;
//                     j++;
//                 }
//                 if(i-1 >=0 && chk[i-1][j] == 0){
//                     chk[i-1][j] = 1;
//                     i--;
//                 }
//                 if(j-1 >= 0 && chk[i][j-1] == 0){
//                     chk[i][j-1] = 1;
//                 }
//             }
//             return false;
// };
// };

class Solution{
    public:
        Solution(vector<vector<bool>> maze, int n){
            bool sol[n][n] = {0};
            bool isSafe(int i, int j){
                if(i<n-1 && j <n-1 &&  maze[i][j] == 1){
                    return true;
                }else return false;
            }

            bool solveMazeRec(int i , int j){
                if(i == n-1 && j = n-1){sol[i][j] = 1; return true;}

                if(isSafe(i,j) == true){
                    sol[i][j] = 1;
                    if(solveMazeRec(i+1, j) == true) return true;
                    else if(solveMazeRec(i, j+1) == true) return true;
                    sol[i][j] = 0;
                }
                return false;
            }

            bool solveMaze(){
                if(solveMazeRec(0,0) == false){
                    return false;
                }else{
                    print(sol);
                    return true;
                }
            }
        }
};

int main(){
    vector<vector<int>>   Maze = {{1,0,0,0},
                                  {1,1,0,0},
                                  {0,1,0,0},
                                  {1,1,1,1}};
    return 0;
}