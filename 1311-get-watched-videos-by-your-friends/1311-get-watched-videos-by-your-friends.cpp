class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        vector<string>ans;
        int n=watchedVideos.size();
        vector<int>vis(n,0);
        queue<int>q;
        q.push(id);
        int k=0;
        vis[id]=1;
        while(!q.empty()){
            int s= q.size();
            unordered_map<string,int>mpp;
            for(int i=0;i<s;i++){
                int node= q.front();
                q.pop();
                for(auto it : watchedVideos[node]){
                    mpp[it]++;
                }
                for(auto it : friends[node]){
                    if(vis[it]==0){
                        vis[it]=1;
                        q.push(it);
                    }
                }
            }
            if(k==level){
                vector<pair<int,string>>freq;
                for(auto it : mpp){
                    freq.push_back({it.second,it.first});
                }
                sort(freq.begin(),freq.end());
                for(auto it : freq){
                    ans.push_back(it.second);
                }
                break;
            }
            k++;
        }
        return ans;
        
    }
};