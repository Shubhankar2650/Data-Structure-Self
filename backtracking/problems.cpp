#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// ✒️ 4 number with highest xor
// It states you jhave to pass a array A from R(which gives subset of A) then the output is pass to X(which gives the xor of the subsets)
//      You have to find the maximum xor given that k is the no. of elements in the subsets.
class problem1
{
private:
    int ans;
    void solve(vector<int> v, int k, int index, int n, int x)
    {
        // base case
        if (n == k)
        {
            ans = max(ans, x);
            return;
        }
        // we go out of the bound
        if (n == v.size())
        {
            return;
        }

        // exclude
        solve(v, k, index + 1, n, x);

        // include
        x = x ^ v[index];
        solve(v, k, index + 1, n + 1, x);
    }

public:
    int solution(vector<int> A, int k)
    {
        int ans = 0;
        solve(A, k, 0, 0, 0);
        return ans;
    }
};

//

class Problem2
{
private:
    int count;
    void solve(vector<int> &a, int b, int c, int d)
    {
        if (b == 0)
        {
            int total = 0;
            for (auto i : a)
            {
                if (i > d)
                    total++;
            }
            if (total >= c)
                count++;
            return;
        }

        // delete  the first element
        int temp = a[0];
        a.erase(a.begin());
        solve(a, b - 1, c, d);
        a.insert(a.begin(), temp);

        // delete the  last element
        temp = a.back();
        a.pop_back();
        solve(a, b - 1, c, d);
        a.push_back(temp);

        // increment the 1st element
        a[0]++;
        solve(a, b - 1, c, d);
        a[0]--;

        // increment last element
        a[a.size() - 1]++;
        solve(a, b - 1, c, d);
        a[a.size() - 1]--;
    }

public:
    int solution(vector<int> A, int B, int C)
    {
        int count = 0;
        int d = 0;
        for (int i = 0; i < A.size(); i++)
        {
            d = d ^ A[i];
        }
        solve(A, B, C, d);
        return count;
    }
};

int main()
{

    return 0;
}