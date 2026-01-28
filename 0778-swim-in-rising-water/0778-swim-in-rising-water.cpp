class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n= grid.size();
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        dist[0][0]=grid[0][0];
        pq.push({grid[0][0],{0,0}}); // {weight,{row,col}};
        vector<pair<int,int>>dir = {{0,-1},{0,1},{-1,0},{1,0}};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int r= it.second.first;
            int c= it.second.second;
            int time = it.first;
            if(r==n-1 && c==n-1){
                return time;
            }

            for(auto it : dir){
                int nr= r+ it.first;
                int nc= c+ it.second;

                if(nr<n && nr>=0 && nc<n && nc>=0){
                    int new_time=  max(time,grid[nr][nc]);
                    if(new_time<dist[nr][nc]){
                        dist[nr][nc]=new_time;
                        pq.push({dist[nr][nc],{nr,nc}});
                    }
                }

            }
        }
        return {};
    }
};