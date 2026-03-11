class Solution {
public:
    int find_longSb(int ind1, int ind2, string& text1, string& text2,vector<vector<int>>& dpp){
        if(ind1==0 || ind2==0){
            return 0;
        }
        if(dpp[ind1][ind2]!=-1){
            return dpp[ind1][ind2];
        }
        if(text1[ind1-1]==text2[ind2-1]){
            return dpp[ind1][ind2]= 1+ find_longSb(ind1-1,ind2-1,text1, text2,dpp);
        }
        else{
            return dpp[ind1][ind2]=0 + max(find_longSb(ind1-1,ind2,text1,text2,dpp),find_longSb(ind1,ind2-1,text1,text2,dpp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m= text2.size();
        vector<vector<int>>dpp(n+1,vector<int>(m+1,-1));
        return find_longSb(n,m,text1,text2,dpp);
    }
};