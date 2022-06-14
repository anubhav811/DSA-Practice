class Solution {
public:
     vector<int> twoSum(vector<int> &nums, int target)
    {   
          unordered_map<int,int> m;
         for (int i = 0; i < nums.size(); i++)
        {
             int x = nums[i]           ;  //  Current value
           int y=target-x;
             if(m.find(y)!=m.end()){       // check if "key" i.e the value according to array exists in the map
                 return {i,m[y]};
             }
             m[x]=i;                       // then insert anyways.
        }
        
        return {-1,-1};
     }
         
//          APPROACH 3
//          vector<pair<int,int>> v;
//          for(int i =0 ;i<nums.size();i++){ 
//              v.push_back({nums[i],i});
//          }
//          sort(v.begin(),v.end());
//          int s = 0;
//          int e = nums.size()-1;
//          while(s<e){
//              if(v[s].first + v[e].first == target){
//                  return {v[s].second,v[e].second};
//              }
//              else if(v[s].first + v[e].first > target){
//                  e--;
//              }
//              else{
//                  s++;
//              }
//          }
         
//          return {-1,-1};
         
        
};