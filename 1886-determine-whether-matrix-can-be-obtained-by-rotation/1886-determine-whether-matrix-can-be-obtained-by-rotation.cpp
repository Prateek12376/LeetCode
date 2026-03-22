class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat==target){
            return true;
        }
        bool flg1=true;
        bool flg2=true;
        bool flg3=true;
        int n=mat.size()-1;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat.size();j++){
                if(mat[i][j]!=target[j][n-i]){
                    flg1=false;
                }
                if(mat[i][j]!=target[n-i][n-j]){
                    flg2=false;
                }
                if(mat[i][j]!=target[n-j][i]){
                    flg3=false;
                }
            }
        }
        if(flg1==true || flg2==true || flg3==true){
            return true;
        }
        else{
            return false;
        }
    }
};