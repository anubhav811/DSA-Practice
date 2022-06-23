class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    
        // Optimised approach 2 : Use one pointer alongwith map to store char and its last occurence index . When L has to move it will only move +1 the last occurence index saving time 
        
      vector < int > mpp(256, -1);               // Because there can be 256 characters  (ASCII)

      int left = 0, right = 0;
      int n = s.size();
      int len = 0;
      while (right < n) {
        if (mpp[s[right]] != -1)             // if found previously i.e exists in map 
          left = max(mpp[s[right]] + 1, left);       // move L to +1 the found index to get left index of substring  range

        mpp[s[right]] = right;                      // update the value in map

        len = max(len, right - left + 1);            // calculate length of string 
        right++;                                     // move R ahead
      }
      return len;
    }       
        
        // Optimized approach 1 :  Use two pointers alongwith hash set

//       int maxans = INT_MIN;
//   unordered_set < int > set;
//   int l = 0;
//   for (int r = 0; r < str.length(); r++) // outer loop for traversing the string
//   {
//     if (set.find(str[r]) != set.end()) //if duplicate element is found
//     {
//       while (l < r && set.find(str[r]) != set.end()) {
//         set.erase(str[l]);                   // move left pointer ahead 
//         l++;
//       }
//     }
//     set.insert(str[r]);                  // insert the char in hashset
//     maxans = max(maxans, r - l + 1);
//   }
//         if(maxans==INT_MIN){
//             return 0;
//         }
//   return maxans;
// }
};