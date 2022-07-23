class Solution {
public:
    void solveRecur(vector<int> &nums , vector<int> &currPermutation , vector<vector<int>> &ans,int visited[]){
        if(currPermutation.size()==nums.size()){
            ans.push_back(currPermutation);
            return;
        }
        for(int i = 0 ; i<nums.size();i++){
            if(visited[i]==0){
                currPermutation.push_back(nums[i]);
                visited[i]=1;
                solveRecur(nums,currPermutation,ans,visited);
                visited[i]=0;
                currPermutation.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> currPermutation;
        int visited[nums.size()];
        for(int i = 0 ; i<nums.size();i++){
            visited[i]=0;
        }
        solveRecur(nums,currPermutation,ans,visited);
        return ans;
    }
};