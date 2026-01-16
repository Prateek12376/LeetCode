class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n= grid.size();
        if(grid[n-1][n-1]==1 || grid[0][0]==1){
            return -1;
        }
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        dist[0][0]=1;

        queue<pair<int,pair<int,int>>>pq; // {dist,row,col}

        vector<pair<int,int>> dir = {{-1, -1}, {-1, 0}, {-1, 1},{ 0, -1},{ 0, 1},{ 1, -1}, { 1, 0}, { 1, 1}};

        pq.push({1,{0,0}});


        while(!pq.empty()){
            int dis= pq.front().first;
            int r= pq.front().second.first;
            int c= pq.front().second.second;
            pq.pop();

            for(auto d: dir){
                int nr= d.first+r;
                int nc = d.second+c;

                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0 && dis + 1 < dist[nr][nc]){
                    dist[nr][nc]=1+dis;
                    pq.push({1+dis,{nr,nc}});
                }
            }
        }

        int ans = dist[n-1][n-1];

        if(ans==INT_MAX){
            return -1;
        }

        return ans;



    }
};