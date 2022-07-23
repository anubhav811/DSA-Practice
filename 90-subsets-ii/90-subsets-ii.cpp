class Solution {
public:
    // FUNCTION for APPROACH 2
    void solveRecur(int start , vector<int> currSubset, vector<int> &nums , vector<vector<int>> &superSet){
        superSet.push_back(currSubset);
        for(int i=start ; i<nums.size(); i++){
            if(i>start && nums[i]  == nums[i-1]){
                continue;
            }
            // picked side
            currSubset.push_back(nums[i]);
            solveRecur(i+1,currSubset,nums,superSet);
            // not picked side
            currSubset.pop_back();
        }
    }

    // FUNCTION for APPROACH 1
//     void solveRecur(int start ,vector<int> currSubset , vector<int> &arr, set<vector<int>> &superSet){
//         // if start pointer reaches end
//         if(start == arr.size()){
//             sort(currSubset.begin(),currSubset.end());
//             superSet.insert(currSubset);
//             return;
//         }

//         // if picked
//         currSubset.push_back(arr[start]);
//         solveRecur(start+1,currSubset , arr, superSet);
//         // if not picked
//         currSubset.pop_back();
//         solveRecur(start+1,currSubset,arr,superSet);
//     }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        // Approach 2 : Optimal
        vector<vector<int>> ans ; 
        vector<int> currSubset; 
        sort(nums.begin(),nums.end());
        solveRecur(0,currSubset,nums,ans);
        
        return ans;
        
        //  Approach 1  : Brute Force
        // set<vector<int>> res;
        // vector<int> currSubset;
        // solveRecur(0,currSubset,nums,res);
        // vector<vector<int>> ans; 
        // for (auto it = res.begin(); it != res.end(); it++) {
        //   ans.push_back( * it);
        // }
        // return ans;

    }
};