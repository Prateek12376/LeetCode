class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& matrix, int maxR, int maxC,string& ans){
        ans+=matrix[r][c];

        if(r+1<maxR && c+1<maxC){
            dfs(r+1,c+1,matrix,maxR,maxC,ans);
        }
    }
    string decodeCiphertext(string encodedText, int rows) {
        int n=encodedText.size();
        int  col =ceil(n/rows);
        int ind=0;
        vector<vector<char>>matrix(rows,vector<char>(col,' '));
        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                char c=encodedText[ind];
                ind++;
                if(c!=' '){
                    matrix[i][j]=c;
                }
            }
        }
        string ans="";
        for(int i=0;i<col;i++){
            dfs(0,i,matrix,rows,col,ans);
        }
        int i= ans.size()-1;
        while(i>=0 && ans[i]==' '){
            i--;
        }
        string s="";
        for(int ind=0;ind<=i;ind++){
            s+=ans[ind];
        }
        return s;
    }
};