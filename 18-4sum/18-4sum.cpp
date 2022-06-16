/*//Simple SET
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int sum;
        
        for(int i=0;i<n-3;++i) {
            //if(i>0 and nums[i]==nums[i-1])  continue;   //Skip same values for index i to avoid duplicates
            for(int j=i+1;j<n-2;++j) {
                //if(j>i+1 and nums[j]==nums[j-1])    continue;   //Skip same values for index j to avoid duplicates
                for(int k=j+1;k<n-1;++k) {
                    //if(k>j+1 and nums[k]==nums[k-1])    continue;   //Skip same values for index k to avoid duplicates
                    for(int l=k+1;l<n;++l) {
                        //if(l>k+1 and nums[l]==nums[l-1])    continue;   //Skip same values for index l to avoid duplicates
                        sum=nums[i]+nums[j]+nums[k]+nums[l];
                        if(sum>target)
                            break;
                        else if(sum==target) {
                            vector<int> t;
                            t.push_back(nums[i]);
                            t.push_back(nums[j]);
                            t.push_back(nums[k]);
                            t.push_back(nums[l]);
                            ans.insert(t);
                        }
                    }
                }
            }
        }
        vector<vector<int>> res;
        for(auto it: ans)
            res.push_back(it);
        return res;
    }
};
*/

//2-pointers + SET
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long sum;
        
        for(int i=0;i<n-3;++i) {
            if(i>0 and nums[i]==nums[i-1])  continue;   //Skip same values for index i to avoid duplicates
            for(int j=i+1;j<n-2;++j) {
                if(j>i+1 and nums[j]==nums[j-1])  continue;   //Skip same values for index j to avoid duplicates
                int left=j+1,right=n-1;
                
                while(left<right)   {   //2 pointer technique
                    sum=(long)nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum>target)
                        right-=1;
                    else if(sum==target) {
                        vector<int> t;
                        t.push_back(nums[i]);
                        t.push_back(nums[j]);
                        t.push_back(nums[left]);
                        t.push_back(nums[right]);
                        ans.insert(t);
                        left+=1;
                    }
                    else
                        left+=1;
                }
            }
        }
        vector<vector<int>> res;
        for(auto it: ans)
            res.push_back(it);
        return res;
    }
};
/*
//HashMap
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        if(n<4)
            return ans;
        
        sort(nums.begin(),nums.end());
        unordered_map<int,vector<pair<int,int>>> m;    //key->SUM...Value->(i,j) pair of index where i<j
        //Store all sum pairs in map
        for(int i=0;i<n-1;++i)
            for(int j=i+1;j<n;++j)
                m[nums[i]+nums[j]].push_back(make_pair(i,j));
        
        for(int i=0;i<n-1;++i) {
            if(i>0 and nums[i]==nums[i-1])  continue;
            for(int j=i+1;j<n;++j) {
                if(j>i+1 and nums[j]==nums[j-1])  continue;
                int sum = target-nums[i]-nums[j];
                if(m.find(sum)!=m.end()) {
                    for(auto it: m[sum])    {
                        int k=it.first;
                        int l=it.second;
                        if(k>j) {   //Maintain the increasing order of index (i,j,k,l).....i<j<k<l
                            //Skip invalid cases
                            if(!ans.empty() and ans.back()[0]==nums[i] and ans.back()[1]==nums[j] and ans.back()[2]==nums[k] and ans.back()[3]==nums[l])
                                continue;
                            vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                            ans.push_back(temp);
                        }
                    }
                }
            }
        }
        return ans;
    }
};
*/