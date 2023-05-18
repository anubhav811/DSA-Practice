#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> st;
        vector<int> res;

        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] < 0) {
                while (!st.empty() && st.top() < abs(asteroids[i])) st.pop();
                if (st.empty()) res.push_back(asteroids[i]);
                else if (st.top() == abs(asteroids[i])) st.pop();
            } 
            else 
                st.push(asteroids[i]);
        }  

        int m = st.size();
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.end() - m, res.end());
        
        return res;
    }
};
int main()
{

    return 0;
}