class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        vector<vector<pair<int,int>>>dir(7);
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        dir[1]={{0,-1},{0,1}};
        dir[2]={{-1,0},{1,0}};
        dir[3]={{0,-1},{1,0}};
        dir[4]={{0,1},{1,0}};
        dir[5]={{0,-1},{-1,0}};
        dir[6]={{0,1},{-1,0}};
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0]=1;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r=it.first;
            int c= it.second;
            if(r==n-1 && c==m-1){
                return true;
            }
            for(auto it : dir[grid[r][c]]){
                int nr= r+ it.first;
                int nc=c+it.second;

                if(nr<n && nr>=0 && nc>=0 && nc<m && vis[nr][nc]==0){
                    for(auto reverse : dir[grid[nr][nc]]){
                        int nrB=nr+reverse.first;
                        int ncB=nc+reverse.second;
                        if(nrB==r && ncB==c){
                            vis[nr][nc]=1;
                            q.push({nr,nc});
                            break;
                        }
                    }
                }
            }
        }
        return false;
    }
};