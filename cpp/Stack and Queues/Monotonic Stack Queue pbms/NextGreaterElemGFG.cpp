#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> a, int n){
        // Your code here
        vector<long long> res(a.size(),-1);
        
        // TLE Brute Force O(N^2)
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(a[j]>a[i]){
        //             res[i]=a[j];
        //             break;
        //         }
        //     }
        // }
        
        // Stack Approach
        
        stack<long long> s;

        for(int i=n-1;i>=0;i--){
            while(!s.empty() and s.top()<=a[i]) 
                s.pop();
            
            if(s.empty()) 
                res[i] = -1;
            
            else 
                res[i] = s.top();
                
            s.push(a[i]);
        }
        
        return res;
    }
};
int main()
{

    return 0;
}