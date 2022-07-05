class Solution {
public:
    
    void solveRecur(int start ,vector<int> currSubset , vector<int> &arr, set<vector<int>> &superSet){

        // if start pointer reaches end
        if(start == arr.size()){
            sort(currSubset.begin(),currSubset.end());
            superSet.insert(currSubset);
            return;
        }

         
        // if picked
        currSubset.push_back(arr[start]);
        solveRecur(start+1,currSubset , arr, superSet);
   
        // if not picked
        currSubset.pop_back();
        solveRecur(start+1,currSubset,arr,superSet);
       

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        set<vector<int>> res;
        vector<int> currSubset;
        solveRecur(0,currSubset,nums,res);
        vector<vector<int>> ans; 
        for (auto it = res.begin(); it != res.end(); it++) {
          ans.push_back( * it);
        }
        return ans;

    }
};