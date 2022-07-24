class Solution {
public:
    bool canBePlaced(int row , int col , vector<string> &board , int n){
        int rowCopy = row;
        int colCopy = col;
        
        
        //check top - left
        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        
        row = rowCopy;
        col = colCopy;
        // check left (horizantally)
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        
         row = rowCopy;
        col = colCopy;
        //check bottom - left
        while(row<n && col>=0){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }
        
        return true;
    
    }
    
    void solveRecur(vector<string> &board , int col , vector<vector<string>> &ans , int n){
        
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row = 0 ; row <n ; row ++){
            if(canBePlaced(row,col,board,n)){
                board[row][col] = 'Q';
                solveRecur(board,col+1,ans,n);
                board[row][col] = '.';
                
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        vector<string> board;
        string row = string(n,'.');
        for(int i = 0 ; i<n;i++){
            board.push_back(row);
        }
        
        solveRecur(board,0,ans,n);
        
        return ans;
    }
};