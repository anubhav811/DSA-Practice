#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> s;
        
        if(x.size()<=1) return false;
        
        for(int i = 0 ; i < x.size(); i++){
            if(x[i]=='(' || x[i]=='{' || x[i]=='[')
                s.push(x[i]);
            else{
                if(s.empty()) return false;
                if(x[i]==')' && s.top()=='('){
                    s.pop();
                }
                else if(x[i]=='}' && s.top()=='{'){
                    s.pop();
                }
                else if(x[i]==']' && s.top()=='['){ 
                    s.pop();
                }
                else{
                    return false;
                }
            }
        }        



        return (s.empty()) ? true : false;
    }

};