class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int r=startPos[0];
        int c=startPos[1];

        int tr=homePos[0];
        int tc=homePos[1];

        int cost=0;
        if(r>tr){
            for(int i=r-1;i>=tr;i--){
                cost+=rowCosts[i];
            }
        }
        else{
            for(int i=r+1;i<=tr;i++){
                cost+=rowCosts[i];
            }
        }

        if(c>tc){
            for(int i= c-1;i>=tc;i--){
                cost+=colCosts[i];
            }
        }
        else{
            for(int i=c+1;i<=tc;i++){
                cost+=colCosts[i];
            }
        } 
        return cost;  

    }
};