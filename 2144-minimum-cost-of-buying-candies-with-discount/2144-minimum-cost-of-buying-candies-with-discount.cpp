class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int price=0;

        for(int i=cost.size()-1;i>=0;i-=3){
            price+=cost[i];
            if(i>0){
                price+=cost[i-1];
            }
        }
        return price;
    }
};