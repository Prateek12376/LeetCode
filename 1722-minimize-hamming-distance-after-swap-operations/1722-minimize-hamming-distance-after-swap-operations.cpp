class DisjointSet{
    public:
    vector<int>parent;
    vector<int>size;
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUP(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUP(parent[node]);
    }
    void Union(int u, int v){
        int ultp_v=findUP(v);
        int ultp_u=findUP(u);
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
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size();
        DisjointSet ds(n);
        unordered_map<int,vector<int>>mpp;
        for(auto it : allowedSwaps){
            int u=it[0];
            int v=it[1];
            if(ds.findUP(u)!=ds.findUP(v)){
                ds.Union(u,v);
            }
        }

        for(int i=0;i<n;i++){
            int UPI=ds.findUP(i);
            mpp[UPI].push_back(i);
        }
        int ans=0;
        for(auto& it :mpp){
            unordered_map<int,int>freq;
            vector<int>arr=it.second;

            for(int i=0;i<arr.size();i++){
                freq[source[arr[i]]]++;
            }
            for(int i=0;i<arr.size();i++){
                if(freq[target[arr[i]]]>0){
                    freq[target[arr[i]]]--;
                }
                else{
                    ans++;
                }
            }
        }
        return ans;
        
        
    }
};