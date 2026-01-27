class DisjointSet{
public:
  vector<int>parent,size;       // it is the disjoint set by size , the whole class 
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
    int removeStones(vector<vector<int>>& stones) {
        int No_of_stone = stones.size();
        int maxRow=0;
        int maxCol=0;

        for(auto it : stones){
            maxRow= max(maxRow,it[0]);
            maxCol= max(maxCol,it[1]);
        }
        int n=maxRow+1;
        int m=maxCol+1;
        unordered_map<int,int>stone_node;
        DisjointSet Ds(n+m);
        for(auto it : stones){
            int nodeR=it[0];
            int nodeC= it[1]+n;
            Ds.UnionBySize(nodeR,nodeC);
            stone_node[nodeR]=1;
            stone_node[nodeC]=1;
        }
        int count=0;
        for(auto it : stone_node){
            int node = it.first;
            if(Ds.findUP(node)==node){
                count++;
            }
        }
        int ans=No_of_stone- count;
        return ans;
    }
};