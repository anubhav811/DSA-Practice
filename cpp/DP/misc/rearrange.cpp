#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums = {1, 2, 3, -4, -1, 4};

    vector<int> pos;
    vector<int> neg;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
            pos.push_back(nums[i]);
        else
            neg.push_back(nums[i]);
    }

    int maxsz = max(pos.size(), neg.size());
    int i = 0;
    while (i < maxsz)
    {
        if (i < pos.size())
            ans.push_back(pos[i]);

        if (i < neg.size())
            ans.push_back(neg[i]);
        i++;
    }

    for (auto it : nums)
    {
        cout << it << " ";
    }
    return 0;
}
