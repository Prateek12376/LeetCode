class Solution {
public:
    void dfs(int start,vector<vector<int>>& ans,vector<int>& arr,int k){
        int size= arr.size();
        int n=ans.size();
        int m=ans[0].size();
        int rot= k%size;
        reverse(arr.begin(),arr.end());
        reverse(arr.begin(), arr.begin()+rot);
        reverse(arr.begin()+rot,arr.end());
        int ind=0;
        for(int row=start;row<n-start;row++){
            ans[row][start]=arr[ind];
            ind++;
        }
        for(int col=start+1;col<m-start;col++){
            ans[n-start-1][col]=arr[ind];
            ind++;
        }
        for(int row=n-start-2;row>=0+start;row--){
            ans[row][m-start-1]=arr[ind];
            ind++;
        }
        for(int col=m-start-2;col>=1+start;col--){
            ans[start][col]=arr[ind];
            ind++;
        }

    }
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>ans=grid;
        for(int i=0;i<min(n,m)/2;i++){
            vector<int>arr;
            for(int row=i;row<n-i;row++){
                arr.push_back(grid[row][i]);
            }
            for(int col=i+1;col<m-i;col++){
                arr.push_back(grid[n-i-1][col]);
            }
            for(int row=n-i-2;row>=0+i;row--){
                arr.push_back(grid[row][m-i-1]);
            }
            for(int col=m-i-2;col>=1+i;col--){
                arr.push_back(grid[i][col]);
            }
            dfs(i,ans,arr,k);
        }
        return ans;
    }
};