class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, int cnt, int& maxP,vector<int>& vis){
        vis[node]=1;
        maxP= max(maxP,cnt);
        for(auto it : adj[node]){
            if(vis[it]==0){
                dfs(it,adj,cnt+1,maxP,vis);
            }
        }
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int mod = 1e9 +7 ;
        int count=0;
        int n = edges.size();
        vector<vector<int>>adj(n+2);
        vector<int>vis(n+2,0);

        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v= edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int maxP=0;

        dfs(1,adj,0,maxP,vis);
        
        int a = maxP-1;
        int ans =1;
        while(a>0){
            ans=(ans*2)%mod;
            a--;
        }
        return ans;
        
    }
};