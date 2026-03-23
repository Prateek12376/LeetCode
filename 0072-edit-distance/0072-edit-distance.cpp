class Solution {
public:
    int find_word(int i, int j, string& w1, string& w2, vector<vector<int>>& dpp){
        if(i==0 ){
            return j;
        }
        if(j==0){
            return i;
        }
        if(dpp[i][j]!=-1){
            return dpp[i][j];
        }
        if(w1[i-1]!=w2[j-1] ){
            int insert= 1+ find_word(i,j-1,w1,w2,dpp);
            int del = 1+ find_word(i-1,j,w1,w2,dpp);
            int replace = 1+ find_word(i-1,j-1,w1,w2,dpp);
            return dpp[i][j]=min(insert ,min(del,replace));

        }
        else{
            int no_op= find_word(i-1,j-1,w1,w2,dpp);
            return dpp[i][j]=no_op;
        }
    }
    int minDistance(string w1, string w2) {
        int n=w1.size();
        int m=w2.size();
        vector<vector<int>>dpp(n+1,vector<int>(m+1,-1));
        return find_word(n,m,w1,w2,dpp);
    }
};