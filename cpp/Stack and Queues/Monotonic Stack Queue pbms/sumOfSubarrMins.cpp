#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();
        stack<int> s;

        vector<int> NSL(n),NSR(n);

        // Nearest smallest to left
        for(int i=0;i<n;i++){
            while(!s.empty() and arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.empty())
                NSL[i] = -1;
            else
                NSL[i] = s.top();

            s.push(i);
        }

        while(!s.empty()) s.pop();

        // Nearest smallest to right
        for(int i=n-1;i>=0;i--){
            while(!s.empty() and arr[s.top()]>arr[i]){
                s.pop();
            }
            if(s.empty())
                NSR[i] = n;
            else
                NSR[i] = s.top();

            s.push(i);
        }

        int sum = 0;
        for(int i=0;i<n;i++){
            int leftCount = i-NSL[i];
            int rightCount = NSR[i]-i;

            int countOfSubarrays = (leftCount * rightCount)%mod;

            sum=(sum%mod + (1L*arr[i]%mod*countOfSubarrays)%mod)%mod;
        }

        return sum%mod;

        // TLE
        // long long sum = 0;

        // for(int i=0; i<arr.size() ; i++){
        //     int mini = arr[i];
        //     for(int j=i;j<arr.size();j++){
        //         mini =min(arr[j],mini);
        //         sum+=mini%mod;
        //     }
        // }   
        // return sum%mod;
    }
};
int main()
{

    return 0;
}