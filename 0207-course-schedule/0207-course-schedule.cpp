class Solution {
public:
    bool detect(int node, vector<int>& vis, vector<int>& path, vector<int>adj[]){
        vis[node]=1;
        path[node]=1;

        for(auto it: adj[node]){
            if(!vis[it]){
                if(detect(it,vis,path,adj)==true){
                    return true;
                }
            }
            else{
                if(path[it]){
                    return true;
                }
            }
        }
        path[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V= numCourses;
        vector<int>adj[V];
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[u].push_back(v);
        }
        vector<int>vis(V,0);
        vector<int>path(V,0);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i,vis,path,adj)==true){
                    return false;
                }
            }
        }
        return true;
    }
};