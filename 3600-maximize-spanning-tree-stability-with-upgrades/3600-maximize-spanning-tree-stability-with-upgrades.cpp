class DSU{
    public:
    int group=0;
    vector<int>parent,size;
    public:
    DSU(int n){
        group=n;
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUP(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node]=findUP(parent[node]);
    }
    void UnionBySize(int u,int v){
        int ultp_u= findUP(u);
        int ultp_v = findUP(v);
        if(ultp_u==ultp_v){
            return;
        }
        group--;
        if(size[ultp_u]<size[ultp_v]){
            parent[ultp_u]=ultp_v;
            size[ultp_v]+= size[ultp_u];
        }
        else{
            parent[ultp_v]=ultp_u;
            size[ultp_u]+=size[ultp_v];
        }
    }
};
class Solution {
public:
    bool can_perform(int n, vector<vector<int>>& edges , int k,int x,vector<pair<int,pair<int,int>>>& opTuple){
        DSU ds(n);
        for(auto edge : edges){
            int u=edge[0];
            int v=edge[1];
            int st=edge[2];
            int must= edge[3];
            if(must==0){
                continue;
            }
            if(ds.findUP(u)==ds.findUP(v)){
                return false;
            }
            else if(st<x){
                return false;
            }
            ds.UnionBySize(u,v);
        }
       
        for(auto edge : opTuple){
            int u=edge.second.first;
            int v=edge.second.second;
            int st=edge.first;
            if(ds.findUP(u)== ds.findUP(v)){
                continue;
            }
            if(st>=x){
                ds.UnionBySize(u,v);
            }
            else if( (2*st>=x) && k>0){
                k--;
                ds.UnionBySize(u,v);
            }
        }
        if(ds.group==1){
            return true;
        }
        else{
            return false;
        }
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        vector<pair<int,pair<int,int>>>opTuple;
        for(auto edge : edges){
            int u=edge[0];
            int v=edge[1];
            int st=edge[2];
            int must = edge[3];
            if(must==0){
                opTuple.push_back({st,{u,v}});
            }
        }
        sort(opTuple.rbegin(),opTuple.rend());
        int l=INT_MAX;
        int r= INT_MIN;
        for(auto it : edges ){
            l=min(l,it[2]);
            r=max(r,it[2]*2);
        }
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(can_perform(n,edges,k,mid,opTuple)==true){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};