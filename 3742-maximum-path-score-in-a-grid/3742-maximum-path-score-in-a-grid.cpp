class Solution {
public:
    int find_max(int i, int j, vector<vector<int>>& grid,int cost,int maxC,vector<vector<vector<int>>>&dpp){
        if(i==grid.size()-1 && j==grid[0].size()-1 ){
            if(grid[i][j]==0){
                return grid[i][j];
            }
            else if(cost+1<=maxC){
                return grid[i][j];
            }
            else{
                return INT_MIN;
            }
        }
        if(i>=grid.size() || j>=grid[0].size()){
            return INT_MIN;
        }
        if(dpp[i][j][cost]!=-1){
            return dpp[i][j][cost];
        }
        int down=INT_MIN;
        int right=INT_MIN;
        if(j<grid[0].size()-1){
            if(grid[i][j]==0){
                right=0+find_max(i,j+1,grid,cost,maxC,dpp);
            }
            else{
                if(cost+1<=maxC){
                    right=grid[i][j]+find_max(i,j+1,grid,cost+1,maxC,dpp);
                }
            }
        }
        if(i<grid.size()-1){
            if(grid[i][j]==0){
                down=0+find_max(i+1,j,grid,cost,maxC,dpp);
            }
            else{
                if(cost+1<=maxC){
                    down=grid[i][j]+find_max(i+1,j,grid,cost+1,maxC,dpp);
                }
            }
        }
        return dpp[i][j][cost]=max(right,down);
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dpp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        int result= find_max(0,0,grid,0,k,dpp);
        if(result<0){
            return -1;
        }
        return result;
    }
};