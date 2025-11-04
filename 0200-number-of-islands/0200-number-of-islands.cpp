class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vector<pair<int,int>> dir= {{-1,0},{1,0},{0,-1},{0,1}};
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        q.push({row,col});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(auto d : dir){
                int n_row= row+ d.first;
                int n_col= col+ d.second;
                if(n_row<n && n_row>=0 && n_col<m && n_col>=0 && grid[n_row][n_col]=='1' && !vis[n_row][n_col]){
                    vis[n_row][n_col]=1;
                    q.push({n_row,n_col});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return count;
    }
};