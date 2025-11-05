class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& vis,vector<vector<char>>& board){
        vis[row][col]=1;
        int n= board.size();
        int m=board[0].size();
        vector<pair<int,int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
        for(auto d: dir){
            int n_row= row+d.first;
            int n_col=col+ d.second;
            if(n_row>=0 && n_row<n && n_col>=0 && n_col<m && !vis[n_row][n_col] && board[n_row][n_col]=='O'){
                dfs(n_row,n_col,vis,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,vis,board);
            }
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(i,m-1,vis,board);
            }
        }
        for(int j=0;j<m;j++){
            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0,j,vis,board);
            }
            if(!vis[n-1][j] && board[n-1][j]=='O'){
                dfs(n-1,j,vis,board);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }

    }
};