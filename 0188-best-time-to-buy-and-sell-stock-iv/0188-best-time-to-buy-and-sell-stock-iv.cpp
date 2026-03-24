class Solution {
public:
    int find_maxP(int ind,int buy, vector<vector<vector<int>>>& dpp, vector<int>& prices,int lim){
        if(lim==0){
            return 0;
        }
        if(ind== prices.size()){
            return 0;
        }
        if(dpp[ind][buy][lim]!=-1){
            return dpp[ind][buy][lim];
        }
        int profit=0;
        if(buy==1){
            int b= -prices[ind] + find_maxP(ind+1,0,dpp,prices,lim);
            int nb= 0 + find_maxP(ind+1,1,dpp,prices,lim);
            profit= max(b,nb);
        }
        else{
            int s=  prices[ind]+ find_maxP(ind+1,1,dpp,prices,lim-1);
            int ns= 0+ find_maxP(ind+1,0,dpp,prices,lim);
            profit= max(s,ns);
        }
        return dpp[ind][buy][lim]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n= prices.size();
        vector<vector<vector<int>>>dpp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return find_maxP(0,1,dpp,prices,k);
    }
};