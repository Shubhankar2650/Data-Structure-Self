#include<bits/stdc++.h.txt>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int> stk;
        for(int i = 0; i< s.length(); i++){
            if(s[i] == '{' && stk.top()|| s[i] == '('|| s[i] == '[' ){
                
                case ']':
                    if(stk.top() != s[i]){
                        return false;
                    }else{
                        stk.pop();
                        break;

            }
            }
        
            stk.push(s[i]);
        }
        }
        stk.empty
    }
};