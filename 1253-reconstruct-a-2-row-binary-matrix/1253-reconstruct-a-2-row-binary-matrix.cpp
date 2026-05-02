class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n=colsum.size();
        vector<vector<int>>ans(2,vector<int>(n,0));
        for(int i=0;i<n;i++){
            if(colsum[i]==2){
                ans[0][i]=1;
                upper--;
                colsum[i]--;
                ans[1][i]=1;
                lower--;
                colsum[i]--;
            }
            else if(colsum[i]==1){
                if(lower>upper){
                    ans[1][i]=1;
                    lower--;
                    colsum[i]--;
                }
                else{
                    ans[0][i]=1;
                    upper--;
                    colsum[i]--;
                }
            }
        }
        if(lower!=0 || upper!=0){
            return {};
        }
        for(int i=0;i<n;i++){
            if(colsum[i]>0){
                return {};
            }
        }
        return ans;
    }
};