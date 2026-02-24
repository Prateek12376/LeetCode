class Solution {
private:
    int find_pathSum(int r,int c1, int c2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dpp){
        if(c1<0 || c1>=grid[0].size() || c2<0 || c2>=grid[0].size()){
            return -1e8;
        }
        if(r==grid.size()-1){
            if(c1==c2){
                return grid[r][c1];
            }
            else{
                return grid[r][c1] + grid[r][c2];
            }
        }
        if(dpp[r][c1][c2]!=-1){
            return dpp[r][c1][c2];
        }
        int maxi=-1e8;
        for(int i=-1;i<2;i++){
            for(int j=-1;j<2;j++){
                if(c1==c2){
                    maxi=max(maxi,grid[r][c1]+find_pathSum(r+1,c1+i,c2+j,grid,dpp));
                }
                else{
                    maxi=max(maxi,grid[r][c1]+grid[r][c2]+find_pathSum(r+1,c1+i,c2+j,grid,dpp));
                }
            }
        }
        return dpp[r][c1][c2]=maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dpp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return find_pathSum(0,0,m-1,grid,dpp);
    }
};