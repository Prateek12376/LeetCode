class Solution {
public:
    bool find_isM(int i, int j, string& s, string& p, vector<vector<int>>& dpp){
        if(i==0 && j==0){
            return true;
        }
        if(i>0 && j==0){
            return false;
        }
        if(i==0 && j>0){
            bool flg=true;
            for(int i=j;i>=1;i--){
                if(p[i-1]!='*'){
                    flg=false;
                }
            }
            return flg;
        }
        if(dpp[i][j]!=-1){
            return dpp[i][j];
        }
        if(s[i-1]==p[j-1] || p[j-1]=='?'){
            return dpp[i][j]=find_isM(i-1,j-1,s,p,dpp);
        }
        if(p[j-1]=='*'){
            return dpp[i][j]= find_isM(i-1,j,s,p,dpp) || find_isM(i,j-1,s,p,dpp);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dpp(n+1,vector<int>(m+1,-1));
        return find_isM(n,m,s,p,dpp);
    }
};