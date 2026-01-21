class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>edges(n);
        vector<long long>dist(n,LLONG_MAX);
        vector<int>ways(n,0);

        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int d = roads[i][2];
            edges[u].push_back({v,d});
            edges[v].push_back({u,d});
        }
        int mod = 1e9+7;

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;

        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});  
        int count=0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int node = it.second;
            long long cost = it.first;

            for(auto it : edges[node]){
                int adjN = it.first;
                int adjC = it.second;
                long long newC = cost+ 1ll*adjC;

                if(newC<dist[adjN]){
                    dist[adjN]=cost+adjC;
                    pq.push({dist[adjN],adjN});
                    ways[adjN]=ways[node];
                }
                else if(newC==dist[adjN]){
                    ways[adjN]= (ways[adjN]+ways[node])%mod;
                }
            }
        }
        return ways[n-1];

    }
};