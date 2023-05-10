#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {         
        
        stack<char> open,star;

        for(int i=0;i<s.size();i++){
            if(s[i]=='(') open.push(i);
            if(s[i]=='*') star.push(i);
            else if(s[i]==')'){
                if(!open.empty()) open.pop();
                else{
                    if(!star.empty()) star.pop();
                    else{
                        return false;
                    }
                }
            }
        }

        // We have processed the closing brackets . Now we will process the opening brackets
        // Now if our opening bracket is at index "x" 
        // then we should have the star at an index > x

        while(!open.empty() and !star.empty() and open.top()<star.top()){
            open.pop();
            star.pop();
        }

        return (open.empty()) ? true : false;
    }
};

// Different solution
class Solution {
public:
    bool checkValidString(string s) {         
        int cmin = 0, cmax = 0;
        for (char c : s) {
            if (c == '(')
                cmax++, cmin++;
            if (c == ')')
                cmax--, cmin = max(cmin - 1, 0);
            if (c == '*')
                cmax++, cmin = max(cmin - 1, 0);
            if (cmax < 0) return false;
        }
        return cmin == 0;
    }
};