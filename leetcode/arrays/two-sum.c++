/*
problem : https://leetcode.com/problems/two-sum
*/
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        vector<int> results; // an extra vector to store the result
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {   
                if (nums.at(i) + nums.at(j) == target)
                {
                    results.push_back(i);
                    results.push_back(j);
                    break;
                }
            }
        }
        return results;
    }
};

class main{
    public static :
    main(){
        cin>>
    }
}