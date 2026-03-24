class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>Lgrid(n,vector<int>(m,1));
        vector<vector<int>>Rgrid(n,vector<int>(m,1));
        long long pro=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pro=(pro*grid[i][j])%12345;
                Lgrid[i][j]=pro;
            }
        }
        long long pro2=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                pro2=(pro2*grid[i][j])%12345;
                Rgrid[i][j]=pro2;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // left portion
                int p1=1;
                if(j==0 && i>0){
                    p1=Lgrid[i-1][m-1];
                }
                else if(j>0){
                    p1=Lgrid[i][j-1];
                }
                int p2=1;
                if(j==m-1 && i<n-1){
                    p2=Rgrid[i+1][0];
                }
                else if(j<m-1){
                    p2=Rgrid[i][j+1];
                }

                grid[i][j]=(p1*p2)%12345;
            }
        }
        return grid;
    }
};