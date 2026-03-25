class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m=grid[0].size();
        bool f1=false;
        bool f2=false;
        vector<vector<int>>hori(n,vector<int>(m,0));
        vector<vector<int>>verti(n,vector<int>(m,0));
        long long total=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                total+=grid[i][j];
            }
        }
        long long sumR=0;
        for(int i=0;i<n;i++){
            long long sum1=0;
            for(int j=0;j<m;j++){
                sum1+=grid[i][j];
                hori[i][j]=sum1;
            }
            sumR+=sum1;
            if(total-sumR==sumR){
                f1=true;
                break;
            }
        }
        long long sumC=0;
        for(int j=0;j<m;j++){
            long long sum2=0;
            for(int i=0;i<n;i++){
                sum2+=grid[i][j];
                verti[i][j]=sum2;
            }
            sumC+=sum2;
            if(total-sumC==sumC){
                f2=true;
                break;
            }
        }
        return f1||f2;

    }
};