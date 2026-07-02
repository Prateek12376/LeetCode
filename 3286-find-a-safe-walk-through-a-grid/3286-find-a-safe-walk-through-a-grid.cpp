class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
       int n= grid.size();
       int m= grid[0].size();

        if(grid[0][0]>=health){
            return false;
        }

        queue<pair<int,pair<int,int>>>q;
        vector<vector<vector<int>>>vis(n,vector<vector<int>>(m,vector<int>(health,0)));
        q.push({grid[0][0],{0,0}});

        vector<pair<int,int>>dir={{0,-1},{0,1},{-1,0},{1,0}};
        vis[0][0][grid[0][0]]=1;

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r=it.second.first;
            int c=it.second.second;
            int h = it.first;
            if(r==n-1 && c==m-1){
                return true;
            }

            for(auto it : dir){
                int nr= r+it.first;
                int nc= c+ it.second;

                if(nr<n && nr>=0 && nc<m && nc>=0){
                    if(grid[nr][nc]==1){
                        if(1+h<health && vis[nr][nc][1+h]==0){
                            q.push({1+h,{nr,nc}});
                            vis[nr][nc][1+h]=1;
                        }
                    }
                    else if(vis[nr][nc][h]==0){
                        vis[nr][nc][h]=1;
                        q.push({h,{nr,nc}});
                    }
                }
            }
        }
        return false;


    }
};