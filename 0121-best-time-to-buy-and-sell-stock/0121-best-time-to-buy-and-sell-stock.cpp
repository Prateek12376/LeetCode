class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int mini=prices[0];
        for(int i=1;i<prices.size();i++){
            int value= prices[i]-mini;
            profit=max(profit,value);
            mini= min(mini,prices[i]);
        }
        return profit;
    }
};