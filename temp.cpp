// class Solution {
// private:
//     void subsequence(vector<int> nums, int index, vector<int> output, vector<vector<int>> & ans){
//         if(output.size() == 3){
//             ans.push_back(output);
//             return;
//         }
//         if(index >= nums.size()){
//             return;
//         }

//         subsequence(nums,index+ 1,output, ans);

//         int a = nums[index];
//         output.push_back(a);
//         subsequence(nums,index+1,output, ans);
//     }

// public:
//     bool find132pattern(vector<int>& nums) {

//         vector<vector<int>> ans;
//         vector<int> output;
//         int index = 0;
//         solve(nums,index,output,ans);

//         bool sol = false;
//         for(auto i:ans){
//             if((i[0]<i[2]) && (i[2]<i[1])){
//                 sol = true;
//                 break;
//             }
//         }

//         return sol;
//     }
// };

#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    int solve(int x,int y, int c, int d, int m){
        if(x==c || y == d) return 1;
        else{
            return 1+ min(min(solve((x&y),y,c,d,m),solve((x|y),y,c,d,m)) ,
                         min(solve(x,(x^y),c,d,m),solve(x,(y^m),c,d,m)));
        }
    }
}

int main()
{
    
    return 0;
}