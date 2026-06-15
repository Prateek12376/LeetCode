class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        pq.push({0,{0,0}});
        vector<pair<int,int>>dir={{0,-1},{0,1},{-1,0},{1,0}};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int r = it.second.first;
            int c= it.second.second;
            int remove = it.first;
            if(r==n-1 && c==m-1){
                return remove;
            }

            if (vis[r][c]==1){
                continue;
            }
            vis[r][c]=1;
            for(auto it : dir){
                int nr = it.first +r;
                int  nc= it.second+ c;

                if(nr<n && nr>=0 && nc<m && nc>=0 && vis[nr][nc]==0){
                    if(grid[nr][nc]==1){
                        pq.push({remove+1,{nr,nc}});
                    }
                    else{
                        pq.push({remove,{nr,nc}});
                    }
                }
            }
        }
        return -1;

    }
};