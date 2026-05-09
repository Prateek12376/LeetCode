class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& vis, vector<vector<int>>& ans,vector<int>& arr,int k){
        int size= arr.size();
        int n=ans.size();
        int m=ans[0].size();
        int rot= k%size;
        reverse(arr.begin(),arr.end());
        reverse(arr.begin(), arr.begin()+rot);
        reverse(arr.begin()+rot,arr.end());
        int ind=0;
        for(int row=i;row<n-i;row++){
            ans[row][i]=arr[ind];
            ind++;
        }
        for(int col=i+1;col<m-i;col++){
            ans[n-i-1][col]=arr[ind];
            ind++;
        }
        for(int row=n-i-2;row>=0+i;row--){
            ans[row][m-i-1]=arr[ind];
            ind++;
        }
        for(int col=m-i-2;col>=1+i;col--){
            ans[i][col]=arr[ind];
            ind++;
        }

    }
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>ans=grid;
        for(int i=0;i<min(n,m)/2;i++){
            if(vis[i][i]==0){
                vis[i][i]=1;
                vector<int>arr;
                for(int row=i;row<n-i;row++){
                    arr.push_back(grid[row][i]);
                    vis[row][i]=1;
                }
                for(int col=i+1;col<m-i;col++){
                    arr.push_back(grid[n-i-1][col]);
                    vis[n-i-1][col]=1;
                }
                for(int row=n-i-2;row>=0+i;row--){
                    arr.push_back(grid[row][m-i-1]);
                    vis[row][m-i-1]=1;
                }
                for(int col=m-i-2;col>=1+i;col--){
                    arr.push_back(grid[i][col]);
                    vis[i][col]=1;
                }
                dfs(i,i,vis,ans,arr,k);
            }
        }
        return ans;
    }
};