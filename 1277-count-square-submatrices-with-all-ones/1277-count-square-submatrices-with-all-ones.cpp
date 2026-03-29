class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dpp(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            if(matrix[i][0]==1){
                dpp[i][0]=1;
                count+=1;
            }
        }
        
        for(int j=1;j<m;j++){
            if(matrix[0][j]==1){
                dpp[0][j]=1;
                count+=1;
            }
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==1){
                    dpp[i][j]=1+min(dpp[i][j-1],min(dpp[i-1][j-1],dpp[i-1][j]));
                    count+=dpp[i][j];
                }
            }
        }
        return count;
    }
};