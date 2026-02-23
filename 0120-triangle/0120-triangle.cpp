class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<int>>dpp=triangle;

        for(int i=0;i<n;i++){
            int size = triangle[i].size();
            for(int j=0;j<size;j++){
                if(i==0&&j==0){
                    dpp[i][j]=triangle[i][j];
                }
                else{
                    int up=INT_MAX;
                    int upL=INT_MAX;

                    if(i>0 && j-1>=0){
                        upL= dpp[i-1][j-1];
                    }
                    if(i>0 && j<triangle[i-1].size()){
                        up=dpp[i-1][j];
                    }
                    if(up==INT_MAX && upL==INT_MAX){
                        dpp[i][j]=INT_MAX;
                    }
                    else{
                        dpp[i][j]=triangle[i][j]+ min(up,upL);
                    }
                }
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<dpp[n-1].size();i++){
            mini=min(mini,dpp[n-1][i]);
        }
        return mini;
    }
};