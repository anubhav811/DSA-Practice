//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    static bool comp(Item a, Item b){
        return ((double)a.value/(double)a.weight > (double)b.value/(double)b.weight);
    }
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        
        sort(arr,arr+n,comp);
        
        double res = 0;
        double wt = 0;
        
        int i = 0;
        
        while(i<n){
            
            if(wt==W)
                return res;

            if(wt+arr[i].weight <= W){
                res+=arr[i].value;
                wt+=arr[i].weight;
            }
            else{
                int extra = W-wt;
                res+=((double)arr[i].value/(double)arr[i].weight)*(double)(W-wt);
                break;
            }
            i++;
        }
        
        return res;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends