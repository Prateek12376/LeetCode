class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int,long long>>>adj(26);
        for(int i=0;i<original.size();i++){
            int u = original[i]-'a';
            int v= changed[i]-'a';
            long long wt =cost[i];
            adj[u].push_back({v,wt});
        }
        vector<vector<long long>>c_frm_node(26,vector<long long>(26,LLONG_MAX));
        for(int i=0;i<26;i++){
            int src=i;
            priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
            vector<long long>dist(26,LLONG_MAX);
            dist[src]=0;
            pq.push({0,src});
            while(!pq.empty()){
                auto it = pq.top();
                pq.pop();
                int node = it.second;
                long long wt = it.first;

                for(auto it : adj[node]){
                    int  adjN=it.first;
                    long long wtN = it.second;
                    if(wt+wtN<dist[adjN]){
                        dist[adjN]=wt+wtN;
                        pq.push({dist[adjN],adjN});
                    }
                }
            }
            c_frm_node[i]=dist;
        }
        long long min_cost=0;
        for(int i=0;i<source.size();i++){
            int from = source[i]-'a';
            int to = target[i]-'a';

            if(c_frm_node[from][to]==LLONG_MAX){
                return -1;
            }
            min_cost+=c_frm_node[from][to];
        }
        return min_cost;

        
    }
};