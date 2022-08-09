class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        sort(arr.begin(),arr.end());
        map<int,long> mp;
        long MOD = pow(10, 9) + 7;
        long ans;
        
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=1;
            for(int j=0;j<i;j++){
                if (arr[i] % arr[j] == 0)
                    mp[arr[i]] = (mp[arr[i]] + mp[arr[j]] * mp[arr[i] / arr[j]]) % MOD;
            }
            
            ans = (ans+mp[arr[i]]) % MOD;
        }
    return ans;
    }
};