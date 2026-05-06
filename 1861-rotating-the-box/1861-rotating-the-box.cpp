class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n=boxGrid.size();
        int m=boxGrid[0].size();
        vector<vector<char>>rgrid(m,vector<char>(n,'.'));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                rgrid[j][n-i-1]=boxGrid[i][j];
            }
        }
        for(int col=0;col<n;col++){
           int bottom=m-1;
            for(int row=m-1;row>=0;row--){
                if(rgrid[row][col]=='*'){
                    bottom=row-1;
                }
                else if(rgrid[row][col]=='#'){
                    swap(rgrid[row][col],rgrid[bottom][col]);
                    bottom--;
                }
            }
        }
        return rgrid;

    }
};