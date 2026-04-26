class Solution {
public:
    bool dfs(int r,int c, vector<vector<char>>& grid,vector<vector<int>>& vis,int parent_r, int parent_c){
        vis[r][c]=1;
        vector<pair<int,int>>dir={{-1,0},{1,0},{0,-1},{0,1}};

        for(auto it : dir){
            int nr= r+it.first;
            int nc=c+it.second;
            if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size()){
                if(grid[nr][nc]!=grid[r][c]){
                    continue;
                }
                if(vis[nr][nc]==0){
                    if(dfs(nr,nc,grid,vis,r,c)==true){
                        return true;
                    }
                }
                else if(vis[nr][nc]==1){
                    if(nr!=parent_r || nc!=parent_c){
                        return true;
                    }
                }
            }
        }
        return false;

    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0){
                    if(dfs(i,j,grid,vis,-1,-1)==true){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};