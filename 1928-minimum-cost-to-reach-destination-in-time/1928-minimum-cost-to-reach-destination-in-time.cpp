class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n=passingFees.size();

        vector<vector<pair<int,int>>>adj(n);

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int t=edges[i][2];
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }
        vector<vector<int>>dist(n,vector<int>(maxTime+1,1e9));                      
        for(int i=0;i<=maxTime;i++){
            dist[0][i]=passingFees[0];
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({passingFees[0],{0,0}});

        while(!pq.empty()){
            auto it  = pq.top();
            pq.pop();
            int cost = it.first;
            int time = it.second.first;
            int node = it.second.second;

            for(auto it : adj[node]){
                int edgT =it.second;
                int edgN = it.first;
                int edgC = passingFees[edgN];
                int nT = time+edgT;

                if(nT<=maxTime && cost+edgC<dist[edgN][nT]){
                    dist[edgN][nT]=cost+edgC;

                    pq.push({dist[edgN][nT],{nT,edgN}});
                }

            }
        }
        int mini=INT_MAX;
        for(int i=0;i<=maxTime;i++){
            mini=min(mini,dist[n-1][i]);
        }
        
        if(mini>=1e9){
            return -1;
        }
        return mini;
    }
};