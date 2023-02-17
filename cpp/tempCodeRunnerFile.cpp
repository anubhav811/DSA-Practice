int ans = 0;
    vector<vector<int>> blocks;
    int i = 1;
    while (i <= X)
    {
        vector<int> block;
        int start = ((i - 1) * X + 1);
        int end = min(N, (i * X));
        for (int x = start; x <= end; x++)
        {
            block.push_back(s[x-1]-'0');
        }
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