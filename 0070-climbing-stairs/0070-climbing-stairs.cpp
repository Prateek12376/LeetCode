class Solution {
private:
    int dpp(int n, vector<int>& dp){
        if(n<=2){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]= dpp(n-1,dp)+ dpp(n-2,dp);
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return dpp(n,dp);
    }
};