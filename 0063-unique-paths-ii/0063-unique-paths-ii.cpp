class Solution {
public:
    int find_path(int row,int col,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dpp){
        if(row<0 || col<0){
            return 0;
        }
        if(obstacleGrid[row][col]==1){
            return 0;
        }
        if(row==0 && col==0){
            return 1;
        }
        
        if(dpp[row][col]!=-1){
            return dpp[row][col];
        }
        int left= find_path(row-1,col,obstacleGrid,dpp);
        int up=find_path(row,col-1,obstacleGrid,dpp);
        return dpp[row][col]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();

        vector<vector<int>>dpp(n,vector<int>(m,-1));
        return find_path(n-1,m-1,obstacleGrid,dpp);
    }
};