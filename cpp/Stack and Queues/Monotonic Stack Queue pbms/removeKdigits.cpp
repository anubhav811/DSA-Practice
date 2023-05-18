#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;

        for(auto it : num){
            while(k>0 and !s.empty() and s.top()>it){
                s.pop();
                k--;
            }
            if(s.empty() && it=='0')
                continue; // So that preceeding zeroes dont get added
            s.push(it);
        }

        while(!s.empty() and k--){
            s.pop();
        }

        string str = "";

        while(!s.empty()){
            str+=s.top();
            s.pop();
        }

        reverse(str.begin(),str.end());

        return str=="" ? "0" : str;

    }
};
int main()
{

    return 0;
}