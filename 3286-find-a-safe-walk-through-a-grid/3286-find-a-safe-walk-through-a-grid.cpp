class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        queue<pair<int,pair<int,int>>>q;
        int n=grid.size();
        int m=grid[0].size();

        if(grid[0][0]>=health){
            return false;
        }

        q.push({grid[0][0],{0,0}});
        vector<pair<int,int>>dir= {{0,-1},{0,1},{-1,0},{1,0}};
        vector<vector<vector<int>>>vis(n,vector<vector<int>>(m,vector<int>(health+1,0)));
        vis[0][0][grid[0][0]]=1;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int  h = it.first;
            int r= it.second.first;
            int c = it.second.second;

            if(r==n-1 && c==m-1){
                return true;
            }


            for(auto it : dir){
                int nr= r+it.first;
                int nc = c+it.second;

                if(nr<n && nc<m && nr>=0 && nc>=0 && vis[nr][nc][h]==0){
                    if(grid[nr][nc]==1){
                        if(h+1<health && vis[nr][nc][h+1]==0){
                            q.push({h+1,{nr,nc}});
                            vis[nr][nc][h+1]=1;
                        }
                    }
                    else{
                        q.push({h,{nr,nc}});
                        vis[nr][nc][h]=1;
                    }
                }
            }
        }
        return false;
    }
};