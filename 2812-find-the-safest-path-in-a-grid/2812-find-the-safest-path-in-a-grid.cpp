class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1){
            return 0;
        }
        vector<vector<int>>dist(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        vector<pair<int,int>>dir = {{0,-1},{0,1},{-1,0},{1,0}};
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                for(auto it :dir){
                    int nr=it.first+r;
                    int nc=it.second+c;

                    if(nr<n && nr>=0 && nc<m && nc>=0 && grid[nr][nc]==0 && dist[nr][nc]==-1){
                        dist[nr][nc]=1+ dist[r][c];
                        q.push({nr,nc});
                    }
                }
            }
        }

        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({dist[0][0],{0,0}});
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int dis = it.first;
            int r = it.second.first;
            int c= it.second.second;
            if(vis[r][c]){
                continue;
            }
            vis[r][c]=1;
            if(r==n-1 && c==m-1){
                return dis;
            }

            for(auto it : dir){
                int nr = it.first+r;
                int nc=it.second+c;
                if(nr<n && nr>=0 && nc<m && nc>=0 && vis[nr][nc]!=1){
                    int curr=dis;
                    curr = min(curr,dist[nr][nc]);
                    pq.push({curr,{nr,nc}});
                }
            }        
        }

        return -1;
        
    }
};