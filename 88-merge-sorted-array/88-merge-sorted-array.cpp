class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
//         int s1 = m-1;
//         int s2 = n-1;
//         int ind = m+n-1;
        
//         while(s2>=0){
//             if(nums1[s1]>nums2[s2] && s1>=0){
//                 nums1[ind]=nums1[s1];
//                 s1--;
//                 ind--;
//             }else{
//                 nums1[ind]=nums2[s2];
//                 s2--;
//                 ind--;
//             }
//         }
        
        int i = m-1;
        int j =n-1;
        int tar = n+m-1;
        
        while (j >=0){
            if (i>=0 && nums1[i] > nums2[j]){
                nums1[tar] = nums1[i];
                tar -=1;
                i -=1;
            }
            else{
                nums1[tar] = nums2[j];
                tar -=1;
                j -=1;
            }
        }

    }
};