class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n  = matrix.size();
        
        int move_by = n-1;
        
        for(int i = 0 ; i < n; i++){
            for(int j = i ; j < n; j++){    
                swap(matrix[j][i],matrix[i][j]);
            }
    
        reverse(matrix[i].begin(), matrix[i].end());
    }}
    void swap (int &a,int &b){
        int temp = a;
        a=b;
        b=temp;
    }
};