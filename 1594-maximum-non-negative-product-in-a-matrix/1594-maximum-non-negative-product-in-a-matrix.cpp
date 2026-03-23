class Solution {
public:
    pair<long long ,long long> find_maxP(int i,int j,vector<vector<int>>& grid,vector<vector<pair<long long,long long>>>& dpp){
        int mod=1e9+7;
        if(i==0 && j==0){
            return {grid[i][j],grid[i][j]};
        }
        if(dpp[i][j].first!=LLONG_MIN){
            return dpp[i][j];
        }
        // left
        long long maxV  = LLONG_MIN;
        long long minV= LLONG_MAX;
        if(i>0){
            auto it=find_maxP(i-1,j,grid,dpp);
            maxV= max(maxV,max(grid[i][j]*it.first,grid[i][j]*it.second));
            minV= min(minV,min(grid[i][j]*it.first,grid[i][j]*it.second));
        }

        // up
        if(j>0){
            auto it = find_maxP(i,j-1,grid,dpp);
            maxV=max(maxV,max(grid[i][j]*it.first,grid[i][j]*it.second));
            minV=min(minV,min(grid[i][j]*it.first,grid[i][j]*it.second));

        }
        return dpp[i][j]={maxV,minV};

    }
    int maxProductPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<pair<long long ,long long>>>dpp(n,vector<pair<long long,long long>>(m,{LLONG_MIN,LLONG_MAX}));
        pair<long long,long long> result=  find_maxP(n-1,m-1,grid,dpp);
        if(result.first<0){
            return -1;
        }
        long long mod=(1e9+7);
        return  (int)(result.first%mod);
        
    }
};