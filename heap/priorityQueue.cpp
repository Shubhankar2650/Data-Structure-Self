// #include<bits/stdc++.h.txt>
#include<iostream>
#include<queue>
using namespace std;


// it is always implemented using c++ heap data struture
// by default it is the max.heap



int main(){
    priority_queue<int> pq;
    pq.top();// for getting the top element
    pq.empty();
    pq.pop();
    pq.push(12);
    pq.size();

    // priority queue having the minimum element at top
    // ✍️ whenever we want to change the order of element to the reverse order we use greater function

    priority_queue<int, vector<int>, greater<int>> pq_reverse;

    
}