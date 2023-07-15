#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void solve(string &str, int index, vector<string> &ans)
    {
        if (index >= str.length())
        {
            ans.push_back(str);
            return;
        };
        for (int i = index; i < str.length(); i++)
        {
            swap(str[index], str[i]);
            solve(str, index + 1, ans);
            swap(str[index], str[i]);
        }
    }

public:
    vector<string> permutation(string &str)
    {
        vector<string> ans;
        int index = 0;
        solve(str, index, ans);
        return ans;
    }
};

int main()
{

    return 0;
}