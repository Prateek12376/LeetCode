class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int mini=INT_MAX;
        for(auto it : mp){
            vector<int>a = it.second;
            if(a.size()>=3){
                sort(a.begin(),a.end());
                int dist=0;
                for(int j=0;j<a.size()-2;j++){
                    dist= abs(a[j]-a[j+1])+ abs(a[j+1]-a[j+2]) + abs(a[j+2]-a[j]);
                    mini=min(mini,dist);
                }
            }
        }
        if(mini==INT_MAX){
            return -1;
        }
        return mini;
    }
};