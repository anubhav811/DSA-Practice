class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
/*  
  // Approach 2 Hashset
       unordered_set<int> s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
	   int longest = 0;
	   for(int num : s) {
        if(s.count(num - 1)) continue;
		int j = 1;
		while(s.count(num + j)) j++; 
		longest = max(longest, j);
	}
	return longest;

    }
  */      
       // Approach 1 Brute Force
        if(nums.size()==0){
            return 0;
        }    
        
        sort(nums.begin(),nums.end());
        
        int ans = 1;
        int prev = nums[0];
        int cur = 1;
        
        for(int i = 1;i < nums.size();i++){
            if(nums[i] == prev+1){
                cur++;
            }
            else if(nums[i] != prev){
                cur = 1;
            }
            prev = nums[i];
            ans = max(ans, cur);
        }
        return ans;
    }

};