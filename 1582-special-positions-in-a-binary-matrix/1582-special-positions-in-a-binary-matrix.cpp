class Solution {
public:
    bool find_routes(int row,int col,vector<vector<int>>& mat){
        for(int i=0;i<mat.size();i++){
            if(mat[i][col]==1 && i!=row){
                return false;
            }
        }
        for(int j=0;j<mat[row].size();j++){
            if(mat[row][j]==1 && j!=col){
                return false;
            }
        }
        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int count=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1){
                    if(find_routes(i,j,mat)==true){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};