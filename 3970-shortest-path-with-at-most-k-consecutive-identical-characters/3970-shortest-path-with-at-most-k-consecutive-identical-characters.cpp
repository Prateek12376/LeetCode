class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it : edges){
            int u=it[0];
            int v=it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
        }
        

        vector<vector<long long>> dist(n,vector<long long>(k + 1, LLONG_MAX));

        priority_queue<pair<long long,pair<int,int>>,vector<pair<long long,pair<int,int>>>,greater<pair<long long,pair<int,int>>>>pq;

        dist[0][1] = 0;
        pq.push({0,{ 0, 1}});

        while(!pq.empty()){ 
            auto it = pq.top();
            pq.pop();
            
            long long d=it.first;
            int u=it.second.first;
            int streak=it.second.second;
            // if(d!=dist[u][streak]){
            //     continue;
            // } 

            for(auto it:adj[u]){
                int v= it.first;
                int w= it.second;
                int newStreak;
                if(labels[v] == labels[u]){
                    newStreak = streak + 1;
                }
                else{
                    newStreak = 1;
                }

                if(newStreak > k){
                    continue;
                } 

                long long newd = d + w;

                if(newd < dist[v][newStreak]){
                    dist[v][newStreak] = newd;
                    pq.push({newd,{v,newStreak}});
                }
            }
        }

        long long ans = LLONG_MAX;

        for(int i=1;i<=k;i++){
            ans = min(ans, dist[n-1][i]);
        }
        if(ans==LLONG_MAX){
            ans=-1;
        }
        return ans;
    }
};