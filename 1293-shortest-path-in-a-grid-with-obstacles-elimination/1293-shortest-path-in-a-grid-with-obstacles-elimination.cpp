class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m= grid[0].size();

        vector<vector<vector<int>>>vis(n,vector<vector<int>>(m,vector<int>(k+1,0)));
        vector<pair<int,int>>dir={{-1,0},{1,0},{0,-1},{0,1}};

        priority_queue<pair<int,pair<int,pair<int,int>>>,vector<pair<int,pair<int,pair<int,int>>>>,greater<pair<int,pair<int,pair<int,int>>>>>pq;

        pq.push({0,{0,{0,0}}});
        vis[0][0][0]=1;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int steps = it.first;
            int canR = it.second.first;
            int r = it.second.second.first;
            int c = it.second.second.second;
            if(r==n-1 && c==m-1){
                return steps;
            }

            for(auto it : dir){
                int nr = r+ it.first;
                int nc= c+ it.second;

                if(nr<n && nr>=0 && nc<m && nc>=0 && vis[nr][nc][canR]==0){
                    if(grid[nr][nc]==1){
                        if(canR<k && vis[nr][nc][canR+1]==0){
                            pq.push({steps+1,{canR+1,{nr,nc}}});
                            vis[nr][nc][canR+1]=1;
                        }
                    }
                    else{
                        pq.push({steps+1,{canR,{nr,nc}}});
                        vis[nr][nc][canR]=1;
                    }
                }
            }
            
        }
        return -1;

    }
};