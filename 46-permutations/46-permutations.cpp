class Solution {
public:
    
    // Approach 2: swap each index with each other index and itself
    // Tc : O(n!xn)  SC : O(1)
    void solveRecur(int start ,vector<int> &nums, vector<vector<int>> &ans){
        
        if(start==nums.size()){
            ans.push_back(nums);
            return;
        }       
        for(int i=start ; i<nums.size();i++){
            swap(nums[start],nums[i]);
            solveRecur(start+1,nums,ans);
            swap(nums[start],nums[i]);
        }
    }
    
    
    // Approach 1: Keep track of elements visited  Tc : O(n!xn)  SC : O(n)
    // void solveRecur(vector<int> &nums , vector<int> &currPermutation , vector<vector<int>> &ans,int visited[]){
    //     if(currPermutation.size()==nums.size()){
    //         ans.push_back(currPermutation);
    //         return;
    //     }
    //     for(int i = 0 ; i<nums.size();i++){
    //         if(visited[i]==0){
    //             currPermutation.push_back(nums[i]);
    //             visited[i]=1;
    //             solveRecur(nums,currPermutation,ans,visited);
    //             visited[i]=0;
    //             currPermutation.pop_back();
    //         }
    //     }
    // }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        //For Approach 2
         solveRecur(0,nums,ans);
        
        
        //  For Approach 1
        // vector<int> currPermutation;
        // int visited[nums.size()];
        // for(int i = 0 ; i<nums.size();i++){
        //     visited[i]=0;
        // }
        // solveRecur(nums,currPermutation,ans,visited);


        return ans;
    }
};