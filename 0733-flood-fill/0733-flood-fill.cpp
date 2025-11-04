class Solution {
public:
    void bfs(int row, int col,vector<vector<int>>& ans,vector<vector<int>>& image,int color, int newColor ){
        int n=image.size();
        int m=image[0].size();
        vector<pair<int,int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
        queue<pair<int ,int>>q;
        q.push({row,col});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            ans[row][col]=newColor;
            for(auto d : dir){
                int n_row=row+d.first;
                int n_col=col+d.second;
                if(n_row>=0 && n_row<n && n_col>=0 && n_col<m && image[n_row][n_col]==color && ans[n_row][n_col]!=newColor){
                    q.push({n_row,n_col});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        int iniColor=image[sr][sc];
        if(iniColor==color){
            return ans;
        }
        bfs(sr,sc,ans,image,iniColor,color);
        return ans;
    }
};