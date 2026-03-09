class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if(amount==0){
            return 0;
        }
        
        vector<vector<int>>dpp(n,vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0){
                dpp[0][i]=i/coins[0];
            }
            else{
                dpp[0][i]=1e9;
            }
        }
        for(int i=1;i<n;i++){
            for(int lim=0;lim<=amount;lim++){
                int not_pick = dpp[i-1][lim];
                int pick=1e9;
                if(coins[i]<=lim){
                    pick = 1+ dpp[i][lim-coins[i]];
                    
                }
                dpp[i][lim]=min(pick,not_pick);
            }
        }
        if(dpp[n-1][amount]>=1e9){
            return -1;
        }
        return dpp[n-1][amount];

    }
};