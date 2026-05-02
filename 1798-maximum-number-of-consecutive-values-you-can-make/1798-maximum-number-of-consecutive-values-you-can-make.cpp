class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(),coins.end());
        int n=coins.size();
        int hSum=0;
        for(int i=0;i<n;i++){
            if(hSum+1<coins[i]){
                break;
            }
            hSum+=coins[i];
        }
        return hSum+1;
       
    }
};