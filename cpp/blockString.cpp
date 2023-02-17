#include <bits/stdc++.h>
using namespace std;


int findKth(int N, string s, int X, int K)
{
    int ans = 0;
    vector<vector<int>> blocks;
    int i = 1, bl;
    if(N%X==0) bl = N/X;
    else bl = N/X+1; 
    while (i <= bl)
    {
        vector<int> block;
        int start = ((i - 1) * X + 1);
        int end = min(N, (i * X));
        for (int x = start; x <= end; x++)
        {
            block.push_back(s[x-1]-'0');
        }
        sort(block.begin(), block.end());
        blocks.push_back(block);
        i++;
    }
    int temp=1;
    for(auto c : blocks){
        temp *= c.size();
    }
    // int temp = pow(blocks[0].size(),X-1)*blocks[blocks.size()-1].size();
    for(i=0;i<blocks.size();i++){
        temp = temp/blocks[i].size();
        // cout <<temp << endl;
        int j=0;
        // for(j=0;j<blocks[i].size();j++){
            while(temp < K){
                K -= temp;
                j++;
                cout << K << endl;
            }
            // break;
        // }
        ans = ans*10 + blocks[i][j];
    }
    return ans;
}
int main()
{
    int N, X, K;
    string s;

    cin >> N >> X >> K;
    cin >> s;
    int ans = findKth(N, s, X, K);

    cout << ans << endl;

    return 0;
}