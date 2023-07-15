#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// ✍️✍️Longest Common Subsequence

// naive recursive solution
int lcs(string s1, string s2, int m, int n)
{
    // base case
    if (m == 0 || n == 0)
    {
        return 0;
    }

    if (s1[m - 1] == s2[n - 1])
    {
        return 1 + lcs(s1, s2, m - 1, n - 1);
    }
    else
    {
        return max(lcs(s1, s2, m - 1, n), lcs(s1, s2, m, n - 1));
    }
}

// memoization solution

class Solution
{
private:
    int memo[m + 1][n + 1];
    for (int i = 1; i < m + 1; m)
    public:
    int lcs(string s1, string s2, int m, int n)
    {
        if (memo[m - 1][n - 1] != -1)
        {
            return memo[m - 1][n - 1];
        }
        // base case
        if (m == 0 || n == 0)
        {
            memo[m][n] = 0;
        }
        else
        {
            if (s1[m - 1] == s2[n - 1])
            {
                return 1 + lcs(s1, s2, m - 1, n - 1);
            }
            else
            {
                return max(lcs(s1, s2, m - 1, n), lcs(s1, s2, m, n - 1));
            }
        }

        return memo[m][n];
    }
}

int
main()
{
    string s1 = "axyz",
           s2 = "baz";
    int m = s1.length(), n = s2.length();

    cout << lcs(s1, s2, s1.length(), s2.length());
    return 0;
}