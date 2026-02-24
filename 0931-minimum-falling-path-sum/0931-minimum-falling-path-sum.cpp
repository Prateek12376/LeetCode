class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dpp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0){
                    dpp[i][j]=matrix[i][j];
                }
                else{
                    int up=INT_MAX;
                    int upL=INT_MAX;
                    int upR=INT_MAX;
                    if(i>0){
                        up=dpp[i-1][j];
                    }
                    if(i>0 && j>0){
                        upL=dpp[i-1][j-1];
                    }
                    if(i>0 && j<n-1){
                        upR=dpp[i-1][j+1];
                    }
                    dpp[i][j]=matrix[i][j]+min(up,min(upR,upL));
                }
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(mini,dpp[n-1][i]);
        }
        return mini;
    }
};