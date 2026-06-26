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

    void join(int u, int v){
        int ultp_u= find_UP(u);
        int ultp_v= find_UP(v);

        if(ultp_u==ultp_v){
            return;
        }

        if(size[ultp_u]>size[ultp_v]){
            parent[ultp_v]=ultp_u;
            size[ultp_u]+=size[ultp_v];
        }
        else{
            parent[ultp_u]=ultp_v;
            size[ultp_v]+=size[ultp_u];
        }
    }

};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU dsu(n+1);
        vector<int>ans(2);

        for(auto it : edges){
            int u=it[0];
            int v=it[1];

            if(dsu.find_UP(u)==dsu.find_UP(v)){
                ans[0]=u;
                ans[1]=v;
            }
            else{
                dsu.join(u,v);
            }
        }
        return ans;
    }
};