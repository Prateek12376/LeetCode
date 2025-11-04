class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;

        int cfresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else if(grid[i][j]==1){
                    cfresh++;
                }
            }
        }
        int count=0;
        int maxi=0;
        vector<pair<int,int>>dir= {{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            maxi=max(maxi,t);
            for(auto d: dir){
                int n_row=r+d.first;
                int n_col=c+d.second;
                if(n_row<n && n_row>=0 && n_col>=0 && n_col<m && vis[n_row][n_col]!=2 && grid[n_row][n_col]==1){
                    q.push({{n_row,n_col},t+1});
                    vis[n_row][n_col]=2;
                    count++;
                }
            }
            
        }
        if(cfresh!=count){
            return -1;
        }
        return maxi;
    }
};