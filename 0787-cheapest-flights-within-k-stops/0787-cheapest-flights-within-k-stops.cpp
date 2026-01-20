class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size();i++){
            int price = flights[i][2];
            int u = flights[i][0];
            int v = flights[i][1];
            adj[u].push_back({v,price});
        }
        vector<int>dist(n,INT_MAX);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,src,0});  // {stop,node,dist};
        dist[src]=0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it[1];
            int cost = it[2];
            int stops= it[0];
            if(stops>k){
                continue;
            }
            for(auto s : adj[node]){
                int adjNode = s.first;
                int adjC  = s.second;
                if(cost+adjC<dist[adjNode] && stops<=k){
                    dist[adjNode]=cost+adjC;
                    pq.push({stops+1,adjNode,dist[adjNode],});
                } 
            }
        }
        if(dist[dst]==INT_MAX){
            return -1;
        }
        return dist[dst];
    }
};