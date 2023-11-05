#include<bits/stdc++.h>
using namespace std;\

// recursive solution
int knapsack(int val[], int weight[], int w, int n){
    if(n== 0 || w== 0){
        return 0;
    }

    if(weight[n - 1] <= w){

        return max(val[n-1] - knapsack(val, weight, w- weight[n-1],n-1),
                    knapsack(val, weight, w, n-1));
    }else{
        knapsack(val, weight, w,n-1);
    }
}

// Dp Solution
int knapsack(vector<vector<int>> memo,int val[], int weight[], int w, int n){
    if(memo[n][w] != -1){
        return memo[n][w];
    }
    if(n== 0 || w== 0){
        return 0;
    }

    if(weight[n - 1] <= w){

        memo[n][w] = max(val[n-1] - knapsack(memo,val, weight, w- weight[n-1],n-1),
                    knapsack(memo,val, weight, w, n-1));
    }else{
        memo[n][w] = knapsack(memo,val, weight, w,n-1);
    }
    return memo[n][w];
}

int main()
{
    int profit[] = { 60, 100, 120 };
    int weight[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(profit) / sizeof(profit[0]);
    
    vector<vector<int>> demo(n+1, vector<int>(W+1,-1));
    int ans1 = knapsack(demo, profit, weight, W, n);
    int ans2 = knapsack( profit, weight, W, n);
    cout<<ans1<<endl;
    cout<<ans2;
    return 0;
}