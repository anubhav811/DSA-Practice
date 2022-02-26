class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> main;
        
        for(int i=0 ; i<numRows ; i++){
            vector<int> row(i+1,1);
            if(i>1){
                cout<<i<<endl;
                for(int j=1;j<i;j++){
                    row[j]=main[i-1][j-1]+main[i-1][j];
                }                
                main.push_back(row);

            }
            else{
            vector<int> row(i+1,1);
            main.push_back(row);
            }
        }
        
        return main;    }
};
        
//         [2][1] = 1[0]+1[1];

//         [3][1] = 2[0]+2[1];
//         [4][2] = 3[1]+3[2];
                           
//         [5][1] = 4[1]+4[2];
//         [5][2] = 4[1]+4[2];
//         [5][3] = 4[2]+4[3];
