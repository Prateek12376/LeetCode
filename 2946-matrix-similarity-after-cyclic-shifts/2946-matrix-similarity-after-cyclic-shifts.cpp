class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>>nums(mat.begin(),mat.end());
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i%2==0){
                    nums[i][j]=mat[i][(j+k)%m];
                }
                else{
                    nums[i][j]=mat[i][((j-k)%m +m )%m];
                }
            }
        }
        if(nums==mat){
            return true;
        }
        else{
            return false;
        }
    }
};