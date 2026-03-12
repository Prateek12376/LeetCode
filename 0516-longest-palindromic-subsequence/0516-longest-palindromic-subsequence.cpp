class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string s2=s;
        reverse(s2.begin(),s2.end());
        vector<vector<int>>dpp(n+1,vector<int>(n+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==s2[j-1]){
                    dpp[i][j]=1+dpp[i-1][j-1];
                }
                else{
                    dpp[i][j]=max(dpp[i-1][j],dpp[i][j-1]);
                }
            }
        }
        return dpp[n][n];
    }
};