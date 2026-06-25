struct DSU{
public:
    vector<int>parent;
    vector<int>size;

    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int find_UP(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=find_UP(parent[node]);
    }

    void join(int v, int u){
        int ultp_v = find_UP(v);
        int ultp_u = find_UP(u);

        if(ultp_v==ultp_u){
            return;
        }
        if(size[ultp_v]>size[ultp_u]){
            parent[ultp_u]=ultp_v;
            size[ultp_v]+=size[ultp_u];
        }
        else{
            parent[ultp_v]=ultp_u;
            size[ultp_u]+=size[ultp_v];
        }
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<pair<int,pair<int,int>>>adj;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int dist = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj.push_back({dist,{i,j}});
            }
        }
        DSU dsu(n+1);
        int cost=0;

        sort(adj.begin(),adj.end());

        for(int i=0;i<adj.size();i++){
            int u= adj[i].second.first;
            int v=adj[i].second.second;
            int c= adj[i].first;

            if(dsu.find_UP(u)!=dsu.find_UP(v)){
                cost+=c;
                dsu.join(u,v);
            }
        }
        return cost;
    }
};