#include<bits/stdc++.h>
using namespace std;
/*
Sort both the vectors check how many biscuit can satisfy the greed of children hence start with minimum
so that less greed wala gets satisfied pehle 

*/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int i=0, j=0;
        int n = g.size();
        int m = s.size();

        int contentChildren = 0;

        while(i<n && j<m){
            if(g[i]<=s[j]){ 
                contentChildren++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }

        return contentChildren;

    }
};