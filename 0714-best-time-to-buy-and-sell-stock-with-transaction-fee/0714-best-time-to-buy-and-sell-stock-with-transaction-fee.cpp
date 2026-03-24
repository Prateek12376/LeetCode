class Solution {
public:
    int find_maxP(int ind, int buy , vector<vector<int>>& dpp, vector<int>& prices,int fee){
        if(ind>=prices.size()){
            return 0;
        }
        if(dpp[ind][buy]!=-1){
            return dpp[ind][buy];
        }
        int profit=0;
        if(buy==1){
            int b=-prices[ind]+ find_maxP(ind+1,0,dpp,prices,fee);
            int nb= 0+ find_maxP(ind+1,1,dpp,prices,fee);
            profit = max(b,nb);
        }
        else{
            int s= (prices[ind]-fee)+ find_maxP(ind+1,1,dpp,prices,fee);
            int ns= 0+ find_maxP(ind+1,0,dpp,prices,fee);
            profit=max(s,ns);
        }
        return dpp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dpp(n,vector<int>(2,-1));
        return find_maxP(0,1,dpp,prices,fee);
    }
};