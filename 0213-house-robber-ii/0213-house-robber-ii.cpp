class Solution {
public: 
    int dpp1(int ind,vector<int>& dp, vector<int>& nums){
        if(ind<1){
            return 0;
        }
        if(ind==1){
            return nums[1];
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int pick =nums[ind]+dpp1(ind-2,dp,nums);
        int not_pick = dpp1(ind-1,dp,nums);
        return dp[ind]=max(pick,not_pick);
    }
    int dpp(int ind,vector<int>& dp, vector<int>& nums){
        if(ind<0){
            return 0;
        }
        if(ind==0){
            return nums[0];
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int pick =nums[ind]+dpp(ind-2,dp,nums);
        int not_pick = dpp(ind-1,dp,nums);
        return dp[ind]=max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> dp(n,-1);
        int ans1= dpp(n-2,dp,nums);
        for(int i=0;i<n;i++){
            dp[i]=-1;
        }
        int ans2=dpp1(n-1,dp,nums);
        return max(ans1,ans2);
    }
};