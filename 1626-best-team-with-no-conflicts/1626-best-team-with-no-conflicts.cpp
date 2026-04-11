class Solution {
public:
    int find_maxS(int ind, int prev,vector<pair<int,int>>& nums, vector<vector<int>>& dpp){
        if(ind==nums.size()){
            return 0;
        }
        if(dpp[ind][prev+1]!=-1){
            return dpp[ind][prev+1];
        }
        // not take
        int nt = find_maxS(ind+1,prev,nums,dpp);
        // take
        int take=INT_MIN;
        if(prev==-1 || nums[ind].second>=nums[prev].second){
            take= nums[ind].second + find_maxS(ind+1,ind,nums,dpp);
        }
        return dpp[ind][prev+1]=max(take,nt);

    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>>nums;
        int n=scores.size();
        for(int i=0;i<n;i++){
            nums.push_back({ages[i],scores[i]});
        }
        sort(nums.begin(),nums.end());
        vector<vector<int>>dpp(n,vector<int>(n+1,-1));
        return find_maxS(0,-1,nums,dpp);

    }
};