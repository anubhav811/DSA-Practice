#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    long long subArrayRanges(vector<int>& arr) {

        // Brute Force O(N^2);    

        // long long sum = 0;

        // for(int i=0; i<nums.size() ; i++){
        //     int mx = nums[i];
        //     int mn = nums[i];
        //     for(int j=i+1;j<nums.size();j++){
        //         mx = max(mx,nums[j]);
        //         mn = min(mn,nums[j]);

        //         sum+= (mx-mn);
        //     }
        // }

        // return sum;


        // Better Solution - Monotonic stack;

        stack<int> s;
        int N = arr.size();
        vector<int> NSL(N),NSR(N),NGL(N),NGR(N);

        // Nearest smallest to left
        for(int i=0;i<N;i++){
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
        for(int i=N-1;i>=0;i--){
            while(!s.empty() and arr[s.top()]>arr[i]){
                s.pop();
            }
            if(s.empty())
                NSR[i] = N;
            else
                NSR[i] = s.top();

            s.push(i);
        }

        while(!s.empty()) s.pop();

        // Nearest greater to left
        for(int i=0;i<N;i++){
            while(!s.empty() and arr[s.top()]<=arr[i]){
                s.pop();
            }
            if(s.empty())
                NGL[i] = -1;
            else
                NGL[i] = s.top();

            s.push(i);
        }

        while(!s.empty()) s.pop();

        // Nearest greater to right
        for(int i=N-1;i>=0;i--){
            while(!s.empty() and arr[s.top()]<arr[i]){
                s.pop();
            }
            if(s.empty())
                NGR[i] = N;
            else 
                NGR[i] = s.top();

            s.push(i);
        }


        long long sum = 0, maxSum = 0 , minSum = 0;
        for(int i=0;i<N;i++){
            long long leftMin = i-NSL[i];
            long long rightMin = NSR[i]-i;
            
            long long leftMax = i - NGL[i];
            long long rightMax = NGR[i]-i;

            long long totalSum =((leftMax*rightMax) - (leftMin*rightMin))*arr[i];
            sum+=totalSum;
        }

        return sum;

    }
};
int main()
{

    return 0;
}