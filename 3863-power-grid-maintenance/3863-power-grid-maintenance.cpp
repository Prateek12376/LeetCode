class Solution {
public:
    int find_computer(int node,set<int>& set1){
        if(set1.count(node)){
            return node;
        }
        else if(!set1.empty()){
            auto smallest= * set1.begin();
            return smallest;
        }
        else{
            return -1;
        }
    }
    void remove_node(int node,set<int>& set1){
        if(set1.count(node)){
            set1.erase(node);
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int>adj[c + 1];
        for(int i=0;i<connections.size();i++){
            int v= connections[i][0];
            int u= connections[i][1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }

        vector<int>vis(c+1,0);
        vector<int>grid(c+1,-1);  // stores connections , means node in same connection have same grid_id
        int grid_id=0;

        for(int i=1;i<=c;i++){
            if(!vis[i]){
                queue<int>q;
                q.push(i);
                vis[i]=1;
                grid[i]=grid_id;

                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(auto it : adj[node]){
                        if(!vis[it]){
                            vis[it]=1;
                            grid[it]=grid_id;
                            q.push(it);
                        }
                    }
                }
                grid_id++;
            }
        }
        vector<set<int>>set1(grid_id);
        for(int i=1;i<=c;i++){
            set1[grid[i]].insert(i);
        }

        vector<int>ans;

        for(auto q: queries){
            int grid_value=grid[q[1]];
            if(q[0]==1){
                int node=find_computer(q[1],set1[grid_value]);
                ans.push_back(node);
            }
            if(q[0]==2){
                remove_node(q[1],set1[grid_value]);
            }
        }
        return ans;
    }
};