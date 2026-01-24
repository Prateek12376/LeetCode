class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>>adj(n);
        vector<int>neighbour(n,0);

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        int src=n-1;
        while(src>=0){
            int count=0;
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;  //{weight,node}
            vector<int>dist(n,INT_MAX);
            dist[src]=0;
            pq.push({0,src});

            while(!pq.empty()){
                auto it = pq.top();
                pq.pop();
                int cost= it.first;
                int node =it.second;
                if(cost>dist[node]){
                    continue;
                }
                for(auto it: adj[node]){
                    int adjN=it.first;
                    int adjC=it.second;
                    if(adjC+cost<dist[adjN] && adjC+cost<=distanceThreshold){
                        dist[adjN]=adjC+cost;
                        pq.push({dist[adjN],adjN});
                    }
                }
            }
            for(int i=0;i<n;i++){
                if(dist[i]<=distanceThreshold && i!=src){
                    count++;
                }
            }
            neighbour[src]=count;
            src--;
        }
        int ans=neighbour[0];
        int ans2=0;
        for(int i=1;i<n;i++){
            if(neighbour[i]<=ans){
                ans=neighbour[i];
                ans2=i;
            }
        }
        return ans2;
    }
};