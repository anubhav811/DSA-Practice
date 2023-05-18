#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        
        // Brute Force -> O(N^2)
        
        // for(int i=0;i<n;i++){
        //     // row -> Saare zero hone chahiye to be the celebrity
        //     bool row = true;
        //     for(int j=0;j<n;j++){
        //         if(M[i][j]!=0){
        //             row = false;
        //             break;
        //         }
        //     }
        //     // col -> Saare one hone chahiye except diagonal elemetns , to be the celebrity
        //     bool col = true;
        //     for(int j=0;j<n;j++){
        //         if(M[j][i]!=1 and i!=j){
        //             col = false;
        //             break;
        //         }
        //     }
        //     if(row and col) return i;
        // }
        // return -1;
        
            
        // Optimal Solution -> O(N)
        
        stack<int> s;
        
        for(int i=0;i<n;i++) s.push(i);
        
        
        while(s.size()>1){
            int A = s.top();
            s.pop();
            int B = s.top();
            s.pop();
            
            // A knows B 
            if(M[A][B]==1){
                // A discared as it knows B , and hence cant be the celebrity
                // add B back to stack
                s.push(B);
            }
            
            // B knows A
           else{
                // B discared as it knows A , and hence cant be the celebrity
                // add A back to stack
                s.push(A);
            }
        }
        
        int potential = s.top();

        // row -> Saare zero hone chahiye to be the celebrity
        bool row = true;
        for(int j=0;j<n;j++){
            if(M[potential][j]!=0){
                row = false;
                break;
            }
        }
        // col -> Saare one hone chahiye except diagonal elemetns , to be the celebrity
        bool col = true;
        for(int j=0;j<n;j++){
            if(M[j][potential]!=1 and potential!=j){
                col = false;
                break;
            }
        }
        if(row and col) return potential;
        
        return -1;
        
    }
};
int main()
{

    return 0;
}