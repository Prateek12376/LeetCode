class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]].push_back(i);
        }
        vector<int>vis(arr.size(),0);
        vis[0]=1;
        queue<int>q;
        q.push(0);
        int step=0;
        while(!q.empty()){
            int size= q.size();
            for(int i=0;i<size;i++){
                int ind = q.front();
                q.pop();
                if(ind==arr.size()-1){
                    return step;
                }
                if(ind>0 && vis[ind-1]==0){
                    vis[ind-1]=1;
                    q.push(ind-1);

                }
                if(ind<arr.size()-1 && vis[ind+1]==0){
                    vis[ind+1]=1;
                    q.push(ind+1);
                }
                if(mpp.find(arr[ind])!=mpp.end()){
                    vector<int>& nums= mpp[arr[ind]];
                    int j=0;
                    while(j<nums.size()){
                        int index=nums[j];
                        if(vis[index]==0){
                            q.push(index);
                            vis[index]=1;
                        }
                        j++;
                    }
                    mpp.erase(arr[ind]);
                }
                
            }
            step++;
        }
        return -1;
    }
};