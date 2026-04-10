class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        vector<pair<int,int>>arr;
        int n=nums.size();
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end());
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            int j=i;
            int dist=0;
            vector<int>ind;
            while(j<n && arr[i].first == arr[j].first){
                ind.push_back(arr[j].second);
                j++;
            }
            if(ind.size()>=3){
                sort(ind.begin(),ind.end());
                for(int k=0;k<ind.size()-2;k++){
                    dist= abs(ind[k]-ind[k+1]) + abs(ind[k+1]-ind[k+2])+ abs(ind[k+2]-ind[k]);
                    mini=min(mini,dist);
                }
            }
            i=j-1;
        }
        if(mini==INT_MAX){
            return -1;
        }
        return mini;
    }
};