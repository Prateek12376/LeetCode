class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        vector<int>pos;
        vector<int>neg;
        int sub=0;
        int miniA=INT_MAX;
        int miniS=INT_MAX;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]>=0){
                    sum+=1LL*matrix[i][j];
                    miniA=min(miniA,matrix[i][j]);
                }
                else{
                    sum+=1LL*abs(matrix[i][j]);
                    miniS=min(miniS,abs(matrix[i][j]));
                    sub++;
                }
            }
        }
        if(sub%2==0){
            return sum;
        }
        int mini=1LL*min(miniS,miniA);
        sum-=2*mini;
        return sum;
    }
};