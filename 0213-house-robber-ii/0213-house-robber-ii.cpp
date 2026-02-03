class Solution {
public: 
    int dpp(int ind,vector<int>& dp, vector<int>& temp){
        if(ind<0){
            return 0;
        }
        if(ind==0){
            return temp[0];
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int pick =temp[ind]+dpp(ind-2,dp,temp);
        int not_pick = dpp(ind-1,dp,temp);
        return dp[ind]=max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> dp(n,-1);
        vector<int>temp1,temp2;
        for(int i=0;i<n;i++){
            if(i!=0){
                temp1.push_back(nums[i]);
            }
            if(i!=n-1){
                temp2.push_back(nums[i]);
            }
        }
        int ans1= dpp(n-2,dp,temp1);
        for(int i=0;i<n;i++){
            dp[i]=-1;
        }
        int ans2=dpp(n-2,dp,temp2);
        return max(ans1,ans2);
    }
};