class Solution {
public:
    void dfs(int row, int col,vector<vector<int>>& grid,vector<vector<int>>& vis){
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        vector<pair<int,int>>dir= {{-1,0},{1,0},{0,-1},{0,1}};
        for(auto d: dir){
            int n_row= row+ d.first;
            int n_col=col+d.second;

            if(n_row>=0 && n_row<n && n_col>=0 && n_col<m && !vis[n_row][n_col] && grid[n_row][n_col]==1){
                dfs(n_row,n_col,grid,vis);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        // first and last col
        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]==1){
                dfs(i,0,grid,vis);
            }
            if(!vis[i][m-1] && grid[i][m-1]==1){
                dfs(i,m-1,grid,vis);
            }
        }
        // first and last col
        for(int j=0;j<m;j++){
            if(!vis[0][j] && grid[0][j]==1){
                dfs(0,j,grid,vis);
            }
            if(!vis[n-1][j] && grid[n-1][j]==1){
                dfs(n-1,j,grid,vis);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};