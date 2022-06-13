class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int s1 = m-1;
        int s2 = n-1;
        int ind = m+n-1;
        
        while(s2>=0 && s1>=0){
            if(nums1[s1]>nums2[s2] ){
                nums1[ind]=nums1[s1];
                s1=s1-1;
                ind= ind-1;
            }else{
                nums1[ind]=nums2[s2];
              s2=s2-1;
                ind= ind-1;
            }
        }
        while(s2>=0){
            nums1[ind] = nums2[s2];
            ind = ind-1;
            s2= s2-1;
            }
    }
};