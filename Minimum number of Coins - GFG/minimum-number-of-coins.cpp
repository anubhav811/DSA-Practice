//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    vector<int> minPartition(int N)
    {
        // code here
        // vector<int> arr = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    
        int coins[] = {2000,500,200,100,50,20,10,5,2,1};

        vector<int> output;

        int i = 0;

        while(N != 0)

        {

            if(N >= coins[i])

            {

                output.push_back(coins[i]);

                N = N-coins[i];

            }

            else

                i++;

        }

        return output;

    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends