class Solution {
public:
    int find_minC(int i, int j, vector<int>& cuts,vector<vector<int>>& dpp){
        if(i>j){
            return 0;
        }
        if(dpp[i][j]!=-1){
            return dpp[i][j];
        }
        int mini=INT_MAX;

        for(int k=i;k<=j;k++){
            int cost = (cuts[j+1]-cuts[i-1]) + find_minC(i,k-1,cuts,dpp) + find_minC(k+1,j,cuts,dpp);

            mini=min(mini,cost);
        }
        return dpp[i][j]= mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int n1=cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        vector<vector<int>>dpp(cuts.size(),vector<int>(cuts.size(),-1));
        sort(cuts.begin(),cuts.end());
        return find_minC(1,n1,cuts,dpp);

    }
};