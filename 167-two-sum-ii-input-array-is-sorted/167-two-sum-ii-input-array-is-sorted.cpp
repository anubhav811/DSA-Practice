class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int start = 0 ;
        int end = numbers.size()-1;
        
        while(start<end){
            int k = numbers[start] + numbers[end];
            if (k == target) {
               vector<int> ans{start+1,end+1}; 
               return ans;
            }
            if(k<target){
                start++;
            } else {
                end--;
            }
        }
        
        return numbers;    
    }
        
};
