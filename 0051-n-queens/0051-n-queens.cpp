class Solution {
public:
    bool safety(int row, int col, vector<string>& board,vector<vector<string>>& ans, int n){
        int drow=row;
        int dcol=col;
        
        while(row>=0 && col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }

        row=drow;
        col=dcol;
        while(col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            col--;
        }

        row=drow;
        col=dcol;
        while(row<n && col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            col--;
            row++;
        }
        return true;
    }
    void find_queen(int col, vector<string>& board,vector<vector<string>>& ans, int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(safety(row,col,board,ans,n)){
                board[row][col]='Q';
                find_queen(col+1,board,ans,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        find_queen(0,board,ans,n);
        return ans;
    }
};