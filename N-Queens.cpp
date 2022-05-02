class Solution {
public:
    void solve(int col,vector<string> &board,vector<vector<string>> &ans,vector<bool> leftRow,vector<bool> upperDiag,vector<bool> lowerDiag,int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row<n;++row){
            if(!leftRow[row] && !upperDiag[row+col] && !lowerDiag[n-1 + col-row]){
                board[row][col] = 'Q';
                leftRow[row] = true;
                upperDiag[row+col] = true;
                lowerDiag[n-1 + col-row] = true;
                solve(col+1,board,ans,leftRow,upperDiag,lowerDiag,n);
                board[row][col] = '.';
                leftRow[row] = false;
                upperDiag[row+col] = false;
                lowerDiag[n-1 + col-row] = false;
            }
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;++i){
            board[i] = s;
        }
        
        vector<bool> leftRow(n,false), upperDiag(2*n - 1,false), lowerDiag(2*n -1,false);
        solve(0,board,ans,leftRow,upperDiag,lowerDiag,n);
        return ans;
    }
};
