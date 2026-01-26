class DisjointSet{
  vector<int>parent,size;
public:
  DisjointSet(int n){
    parent.resize(n+1);
    size.resize(n+1,1);
    
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
  void UnionBySize(int u, int v){
    int ultp_u = findUP(u);
    int ultp_v= findUP(v);
    if(ultp_u==ultp_v){
        return;
    }
    if(size[ultp_u]<size[ultp_v]){  
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<pair<int,int>>tuple;

        for(auto it : connections){
            int u= it[0];
            int v= it[1];

            tuple.push_back({u,v});;
        }
        DisjointSet Ds(n);
        int count =0;
        for(auto it: tuple){
            int u=it.first;
            int v=it.second;

            if(Ds.findUP(u)!=Ds.findUP(v)){
                Ds.UnionBySize(u,v);
            }
            else{
                count++;
            }
        }
        int req=0;
        for(int i=0;i<n;i++){
            if(Ds.findUP(i)==i){
                req++;
            }
        }
        req=req-1;
        if(count>=req){
            return req;
        }
        else{
            return -1;
        }

    }
};