class Solution {
public:
    bool detect(int node, vector<int>& vis, vector<int>& visPath,vector<int>& check,vector<vector<int>>& graph){
        vis[node]=1;
        visPath[node]=1;

        for(auto it : graph[node]){
            if(!vis[it]){
                if(detect(it,vis,visPath,check,graph)==true){
                    return true;
                }
            }
            else{
                if(visPath[it]){
                    return true;
                }
            }
        }
        visPath[node]=0;
        check[node]=1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V= graph.size();
        vector<int>vis(V,0);
        vector<int>visPath(V,0);
        vector<int>check(V,0);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                detect(i,vis,visPath,check,graph);
            }
        }

        vector<int>ans;
        for(int i=0;i<V;i++){
            if(check[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};