class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<pair<int,int>>q;
        int n=arr.size();
        q.push({start,arr[start]});
        vector<int>vis(n,0);
        vis[start]=1;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int ind=it.first;
            int val= it.second;
            vis[ind]=1;
            if(val==0){
                return true;
            }
            if(ind-val>=0 && vis[ind-val]==0){
                vis[ind-val]=1;
                q.push({ind-val,arr[ind-val]});
            }
            if(ind+val<n && vis[ind+val]==0){
                vis[ind+val]=1;
                q.push({ind+val,arr[ind+val]});
            } 
        }
        return false;
    }
};