class Solution {
public:
     vector<int> twoSum(vector<int> &nums, int target)
    {   
         unordered_map<int,int> m;
         for (int i = 0; i < nums.size(); i++)
        {
             int x = nums[i]           ;   //  Current value
           int y=target-x;
             if(m.find(y)!=m.end()){       // check if "key" i.e the value according to array exists in the map
                 return {i,m[y]};
             }
             m[x]=i;                       // then insert anyways.
        }
        
        return {-1,-1};
     }
};