#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr,arr+n);
        sort(dep,dep+n);
        
        int i=0;
        int j=0;
        
        int maxi = INT_MIN;
        int platform = 0;
        
        while(i<n && j<n){
            if(arr[i]<=dep[j]){
                platform++;
                i++;
                maxi =  max(platform,maxi);
            }
            else{
                j++;
                platform--;
            }
        }
        
        return maxi;
    }
};
    
int main()
{

    return 0;
}