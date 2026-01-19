class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n= heights.size();
        int m= heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        vector<pair<int,int>>dir={{0,-1},{0,1},{-1,0},{1,0}};

        pq.push({0,{0,0}});
        dist[0][0]=0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff=it.first;
            int r = it.second.first;
            int c= it.second.second;
            if(r==n-1 && c==m-1){
                return diff;
            }

            for(auto d : dir){
                int nr = r+ d.first;
                int nc = c+ d.second;

                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int new_eff = max(abs(heights[nr][nc]-heights[r][c]),diff);
                    if(new_eff < dist[nr][nc]){
                        dist[nr][nc]=new_eff;
                        pq.push({new_eff,{nr,nc}});
                    }
                }
            }
        }
        return {};
    }
};