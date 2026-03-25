class Solution {
public:
    int find_length(int ind, vector<int>& nums, int prevI,vector<vector<int>>& dpp){
        if(ind==nums.size()){
            return 0;
        }
        if(dpp[ind][prevI+1]!=-1){
            return dpp[ind][prevI+1];
        }
        int pick=0;
        int n_pick=0;
        if(prevI==-1){
            // pick
            pick=1+find_length(ind+1,nums,ind,dpp);
            //not pick
            n_pick=find_length(ind+1,nums,prevI,dpp);

        }
        else{
            // pick
            if(nums[prevI]<nums[ind]){
                pick=1+find_length(ind+1,nums,ind,dpp);
            }
            //not pick
            n_pick=0+find_length(ind+1,nums,prevI,dpp);
        }
        return dpp[ind][prevI+1]=max(pick,n_pick);
        
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dpp(n,vector<int>(n+1,-1));
        return find_length(0,nums,-1,dpp);
    }
};