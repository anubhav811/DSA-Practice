#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, k;
vector<int> arr(100100);
int ans = 0;
int MaxSubarraySum(vector<int> nums, int k)
{
    unordered_set<int> map;
    int left = 0, res = -1, sum = 0;
    for (int right = 0; right < nums.size(); right++)
    {
        while (left < right && (map.count(nums[right]) || map.size() >= k))
        {
            sum -= nums[left];
            map.erase(nums[left]);
            left++;
        }
        sum += nums[right];
        map.insert(nums[right]);

        if (map.size() == k)
            res = max(res, sum);
    }
    return res;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
            arr[i]--;
    }

    if (MaxSubarraySum(arr, k) <= 1)
        cout << 0 << endl;
    else
        cout << MaxSubarraySum(arr, k) << endl;
    return 0;
}
