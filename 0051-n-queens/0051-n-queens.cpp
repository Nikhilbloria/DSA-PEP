class Solution {
public:
vector<vector<string>>ans;
    bool isSafe(vector<string>&board,int row, int col, int n){
        // vertical  check
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }
        //horizontal check
        for(int j =0;j<n;j++){
            if(board[row][j]=='Q'){
                return false;
            }
        }
        //left diagonal
        int i = row;
        int j = col;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
        }
        // right diagonal
        i = row;
        j = col;
        while(i>=0 && j<n){
            if(board[i][j]=='Q'){
                return false;
            }
            i--;
            j++;
        }
        return true;
    }
    void solve(vector<string>&board,int row,int n){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(isSafe(board,row,col,n)){
                board[row][col]='Q';
                solve(board,row+1,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        solve(board,0,n);
        return ans;
    }
};