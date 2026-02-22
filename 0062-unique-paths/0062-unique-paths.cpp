class Solution {
public:
    int find_unique(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dpp){
        int n=grid.size();
        int m=grid[0].size();
        if(row==n-1 && col==m-1){
            return 1;
        }
        if(row >= n || col >= m){
            return 0;
        }
        if(dpp[row][col]!=-1){
            return dpp[row][col];
        }
        int down = find_unique(row+1,col,grid,dpp);
        int right= find_unique(row,col+1,grid,dpp);
        return dpp[row][col]=right+down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>grid(m,vector<int>(n));
        vector<vector<int>>dpp(m,vector<int>(n,-1));
        return find_unique(0,0,grid,dpp);

    }
};