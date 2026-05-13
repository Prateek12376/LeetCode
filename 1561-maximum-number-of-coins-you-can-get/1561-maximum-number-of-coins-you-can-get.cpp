class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int cnt=0;
        int n=piles.size();
        int j=0;
        for(int i=n-2;i>j;i-=2){
            cnt+=piles[i];
            j++;
        }
        return cnt;
    }
};