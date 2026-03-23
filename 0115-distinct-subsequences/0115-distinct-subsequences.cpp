class Solution {
public:
    int find_ways(int i,int j, string& s, string& t, vector<vector<int>>& dpp){
        if(j==0){
            return 1;
        }
        if(i==0){
            return 0;
        }
        if(dpp[i][j]!=-1){
            return dpp[i][j];
        }
        if(s[i-1]==t[j-1]){
            int pick = find_ways(i-1,j-1,s,t,dpp);
            int not_pick = find_ways(i-1,j,s,t,dpp);
            return dpp[i][j]= pick +not_pick;
        }
        else{
            return dpp[i][j]=find_ways(i-1,j,s,t,dpp);
        }
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dpp(n+1,vector<int>(m+1,-1));
        int result = find_ways(n,m,s,t,dpp);
        return result;
    }
};