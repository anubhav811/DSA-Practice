//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        
        stack<long long> st;
        vector<long long> nge(n,0);
        // next = n-1 se  0
        // prev = 0 se n-1
        // greater  arr[i]>= st.top()
        // smaller  arr[i]<= st.top()
        
        for(int i=n-1;i>=0;i--){
            
            // jab tak mei baap hu
            while(!st.empty() and arr[i]>=st.top()){
                st.pop();
            }
            
            if(st.empty()){
                nge[i] = -1;
            }
            else{
                nge[i] = st.top();
            }
            
            // hona hi hai har baar
            st.push(arr[i]);
        }
        
        return nge;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends