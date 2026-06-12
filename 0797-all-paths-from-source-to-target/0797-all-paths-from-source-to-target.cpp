class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                int v=graph[i][j];

                adj[i].push_back(v);
            }
        }

        queue<pair<int,vector<int>>>q;
        q.push({0,{0}});
        vector<vector<int>>ans;
        while(!q.empty()){
            int node=q.front().first;
            vector<int> path = q.front().second;
            q.pop();
            if(node==n-1){
                ans.push_back(path);
            }
            for(auto it : adj[node]){
                path.push_back(it);
                q.push({it,path});
                path.pop_back();
            }
        } 
        return ans;

    }
};