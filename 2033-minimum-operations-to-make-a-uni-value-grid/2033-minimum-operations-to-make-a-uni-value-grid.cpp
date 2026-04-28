class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>ans;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                ans.push_back(grid[i][j]);
            }
        }
        sort(ans.begin(),ans.end());

        int n= ans.size()/2;
        int val=ans[n];
        int cnt=0;
        bool f1=true;
        for(int i=0;i<ans.size();i++){
            if(abs(ans[i]-val)%x==0){
                cnt+=abs(ans[i]-val)/x;
            }
            else{
                f1=false;
            }
        }
        if(f1==false){
            return -1;
        }
        else{
            return cnt;
        }
    }
};