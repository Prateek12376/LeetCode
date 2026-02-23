class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>dpp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    dpp[i][j]=grid[i][j];
                }
                else{
                    int left=INT_MAX;
                    int up=INT_MAX;
                    if(i>0){
                        up= dpp[i-1][j]+grid[i][j];
                    }
                    if(j>0){
                        left=dpp[i][j-1]+grid[i][j];
                    }
                    dpp[i][j]=min(left,up);
                }
            }
        }
        return dpp[n-1][m-1];
    }
};