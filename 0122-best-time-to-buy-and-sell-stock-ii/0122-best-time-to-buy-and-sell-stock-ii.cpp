class Solution {
public:
    int find_max(int ind, int buy,vector<int>& prices,vector<vector<int>>& dpp){
        if(ind==prices.size()){
            return 0;
        }
        if(dpp[ind][buy]!=-1){
            return dpp[ind][buy];
        }
        int profit =0;
        if(buy==1){
            int buy = -prices[ind]+ find_max(ind+1,0,prices,dpp);
            int nbuy= 0+ find_max(ind+1,1,prices,dpp);
            profit= max(buy,nbuy);
        }
        else{
            int sell = prices[ind]+ find_max(ind+1,1,prices,dpp);
            int nsell= 0+ find_max(ind+1,0,prices,dpp);
            profit = max(sell,nsell);
        }
        return dpp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dpp(n+1,vector<int>(2,-1));
        return find_max(0,1,prices,dpp);
    }
};