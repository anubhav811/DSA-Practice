class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int ans=-1;
        int mid;
        int l = 0;
        int r = nums.size()-1;
        while(l<=r){
            mid= (l+r)/2;         
            if (nums[mid] == target)
                ans= mid; 

            if (nums[l] <= nums[mid]) { 
              if (nums[l] <= target && nums[mid] >= target)
                r = mid - 1; 
              else
                l = mid + 1;
            } else { 
              if (nums[mid] <= target && target <= nums[r])
                l = mid + 1;
              else
                r = mid - 1;
            }
        }
        return ans;
    }
};