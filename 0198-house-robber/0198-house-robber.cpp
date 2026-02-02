class Solution {
public:
    int max_money(int ind, vector<int>& nums, vector<int>& dp){
        if(ind<0){
            return 0;
        }
        if(ind==0){
            return nums[0];
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int rob= nums[ind]+ max_money(ind-2,nums,dp);
        int not_rob = max_money(ind-1,nums,dp);
        return dp[ind]=max(rob,not_rob);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return max_money(n-1,nums,dp);
    }
};