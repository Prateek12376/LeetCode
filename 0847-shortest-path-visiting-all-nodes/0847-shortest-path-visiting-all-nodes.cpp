class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();

        int finalM = (1<<n)-1;
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(finalM+1,0));

        for(int i=0;i<n;i++) {
            int mask =(1<<i);
            q.push({i, mask});
            vis[i][mask]=1;
        }
        int steps=0;
        while(!q.empty()){
            int size=q.size();

            for(int i=0;i<size;i++){
                auto it =q.front();
                q.pop();
                int node=it.first;
                int mask = it.second;
                if(mask==finalM){
                    return steps;
                }
                for(auto it : graph[node]){
                    int newMask = mask | 1<<it;
                    if(vis[it][newMask]!=1){
                        q.push({it,newMask});
                        vis[it][newMask]=1;
                    }
                }
            }
            steps++;
        }
        return -1;

    }
};