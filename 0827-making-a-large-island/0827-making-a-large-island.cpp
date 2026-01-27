class DisjointSet{
public:
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
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet Ds(n*n);
        vector<pair<int,int>>dir = {{-1,0},{1,0},{0,-1},{0,1}};
        int maxi= 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    continue;
                }
                int r=i;
                int c=j;
                for(auto it : dir){
                    int nr = r+ it.first;
                    int nc= c+ it.second;
                    if(nr<n && nr>=0 && nc<n && nc>=0){
                        if(grid[nr][nc]==1){
                            int u= r*n + c;
                            int v= nr*n + nc;

                            if(Ds.findUP(u)!=Ds.findUP(v)){
                                Ds.UnionBySize(u,v);
                            }
                        }
                    }
                }
            }
        }
        // find max existing island 
        int maxiE =0;
        for(int i=0;i<n*n;i++){
            if(Ds.findUP(i)==i){
                maxiE=max(maxiE,Ds.size[i]);
            }
        }
        //2
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    continue;
                }
                int r=i;
                int c=j;
                unordered_set<int>comp;
                for(auto it: dir){
                    int nr= r+ it.first;
                    int nc= c+ it.second;

                    if(nr<n && nr>=0 && nc<n && nc>=0){
                        if(grid[nr][nc]==1){
                            int node = nr*n + nc;
                            comp.insert(Ds.findUP(node));
                        }
                    }
                }
                int sizeT =1;
                for(auto it : comp){
                    sizeT+= Ds.size[it];
                }
                mx=max(mx,sizeT);
            }
        }
        return max(mx,maxiE);

    }
};