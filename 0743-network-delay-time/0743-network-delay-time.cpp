class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>time(n+1);
        vector<int>dist(n+1,INT_MAX);
        for(int i=0;i<times.size();i++){
            int src= times[i][0];
            int dst= times[i][1];
            int tt= times[i][2];
            time[src].push_back({dst,tt});
        }

        queue<pair<int,int>>pq;
        pq.push({0,k});
        dist[k]=0;

        while(!pq.empty()){
            auto it = pq.front();
            pq.pop();
            int timeT= it.first;
            int node = it.second;

            for(auto it: time[node]){
                int adjN = it.first;
                int adjT = it.second;

                if(timeT+adjT<dist[adjN]){
                    dist[adjN]=timeT + adjT;
                    pq.push({dist[adjN],adjN});
                }
            }
        }
        int maxi=INT_MIN;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            maxi=max(maxi,dist[i]);
        }
        return maxi;
    }
};