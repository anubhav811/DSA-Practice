class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        double ans ;
        for(auto it : nums1){
            res.push_back(it);
        }
         for(auto it : nums2){
            res.push_back(it);
        }
        
        sort(res.begin(),res.end());
          
        if(res.size()%2==0){
            ans = (res[(res.size()-1)/2]+res[(res.size()-1)/2+1])/2.0 ;
            return ans; 
        }
        ans = res[(res.size()-1)/2];
        return ans;
        
    }
};