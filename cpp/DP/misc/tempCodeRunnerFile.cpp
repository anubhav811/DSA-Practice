int main()
{
    vector<int> a = {1, 2, 3, -4, -1, 4};

    vector<int> ans = rearrangeArray(a);

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}