class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
              
        // Approach 2:
        sort(nums.begin(),nums.end());
                
        vector<vector<int>> res;
        int left,right;
        
        //fixing a
    for (int i = 0; i < (int)(nums.size())-2; i++) {
            
            if (i == 0 || (i > 0 && nums[i] != nums[i-1])) {

            left = i+1;
            right = nums.size()-1;
        
            int sum  = 0 - nums[i];
            
            while(left<right){
                if(nums[left]+nums[right]==sum){
                    
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);
                    res.push_back(temp);
                    
                    while(left<right && nums[left]==nums[left+1])
                        left++;
                    while(left<right && nums[right]==nums[right-1])
                        right--;
                    
                    left++;
                    right--;
                }
                else if(nums[left] + nums[right] < sum)
                    left++;
                else
                    right--;
            }
            }
        }
        return res;
    }
    
//           // Approach 1 : Using set
    
//         vector<int> temp;
        
//         set <vector<int>> st;
        
//         sort(nums.begin(),nums.end());
        
//         if(nums.size() == 0 || nums.size() < 3) return {}; // return empty vector 
        
//         for(int i = 0 ; i < nums.size()-2 ; i++) {
//             for(int j = i+1 ; j < nums.size()-1 ; j++) {
//                 for(int k = j+1 ; k < nums.size() ; k++) {
//                     if(nums[i]+nums[j]+nums[k]==0) {
//                     temp.push_back(nums[i]);
//                     temp.push_back(nums[j]);
//                     temp.push_back(nums[k]);
//                     st.insert(temp);  //set helps in keeping only the unique triplets
//                     temp.clear();
//                     }
//                 } 
//             }
//         }
//         vector<vector<int>> ans(st.begin(),st.end());
//         return ans; 
};