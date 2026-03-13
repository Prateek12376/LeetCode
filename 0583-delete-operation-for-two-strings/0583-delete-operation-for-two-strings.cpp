class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dpp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dpp[i][j]=1+dpp[i-1][j-1];
                }
                else{
                    dpp[i][j]=max(dpp[i-1][j],dpp[i][j-1]);
                }
            }
        }
        return (n+m)-2*dpp[n][m];

    }
};