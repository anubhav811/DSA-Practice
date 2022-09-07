class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int mini = INT_MAX;
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size()-1;i++){
            mini = min(mini,abs(arr[i]-arr[i+1]));
        }
        for(int i=0;i<arr.size()-1;i++){
            if(abs((arr[i]-arr[i+1]))==mini){
                ans.push_back({arr[i],arr[i+1]});
            }
        }
        return ans;
    }
};