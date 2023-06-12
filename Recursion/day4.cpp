#include <iostream>
using namespace std;

// ** Perform recursion on strings

// reverse a string

void reverse(string &s, int i, int j)
{
    if (i > j)
        return;
    swap(s[i], s[j]);
    i++;
    j--;
    reverse(s, i, j);
}

// check palindrome

bool palindrome(string s, int i, int j)
{
    if (i > j)
        return true;
    if (s[i] != s[j])
    {
        return false;
    }
    else
    {
        i++;
        j--;
        return palindrome(s, i, j);
    }
}

// calculating power

int power(int a, int b)
{
    if (b == 0)
        return 1;
    int ans = power(a, b / 2);
    if (b % 2 == 0)
    {
        return (ans * ans);
    }
    if (b % 2 != 0)
    {
        return (a * ans * ans);
    }
}

// Bubble Sort using recursion

void bubbleSort(int *arr, int n)
{
    if (n <= 1)
        return;
    bool isSorted = false;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
            isSorted = true;
        }
    }
    if (!isSorted)
        return;
}

// printing array
void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ",";
    }
}

int main()
{
    string s = "abcde";
    string s1 = "abba";
    // cout << s << endl;
    // reverse(s, 0, s.length() - 1);
    // cout << palindrome(s, 0, s.length() - 1) << endl;
    // cout << palindrome(s1, 0, s1.length() - 1)<<endl;

    // finding 2^8;
    // cout << power(2, 7);

    // using the bubble sort on an array performed using the recursion
    int arr[] = {3, 2, 6, 4, 5, 7, 9, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, size);
    print(arr, size);
    return 0;
}