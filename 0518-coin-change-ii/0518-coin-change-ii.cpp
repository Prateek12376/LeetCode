class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n= coins.size();
        vector<unsigned long long>prev(amount+1,0);

        for(int i=coins[0];i<=amount;i++){
            if(i%coins[0]==0){
                prev[i]=1;
            }
        }
        prev[0]=1;
        for(int i=1;i<n;i++){
            vector<unsigned long long>curr(amount+1,0);
            curr[0]=1;
            for(int lim=0;lim<=amount;lim++){
                unsigned long long not_pick = prev[lim];
                unsigned long long pick=0;
                if(coins[i]<=lim){
                    pick = curr[lim-coins[i]];
                }
                curr[lim]=pick+not_pick;
            }
            prev=curr;
        }
        return (int)prev[amount];
    }
};