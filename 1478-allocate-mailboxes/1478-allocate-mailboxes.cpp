class Solution {
public:
    int minC(int i, int n, vector<int>& houses, vector<vector<int>>& dpp,int k,vector<vector<int>>& cost){
        if(i==n && k==0){
            return 0;
        }
        if(i==n || k==0){
            return INT_MAX;
        }
        if(dpp[i][k]!=-1){
            return dpp[i][k];
        }
        int minCost = INT_MAX;
        for(int j=i;j<n;j++){
            int next=minC(j+1,n,houses,dpp,k-1,cost);
            if(next!=INT_MAX){
                int dist = cost[i][j] + next;
                minCost= min(minCost,dist);
            }
        }
        return dpp[i][k]=minCost;
    }
    int minDistance(vector<int>& houses, int k) {

        sort(houses.begin(),houses.end());
        int n=houses.size();
        vector<vector<int>>dpp(n,vector<int>(k+1,-1));
        vector<vector<int>>cost(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int mid = (i+j)/2;
                for(int s=i;s<=j;s++){
                    cost[i][j]+= abs(houses[s] - houses[mid]);
                }
            }
        }
        return minC(0,n,houses,dpp,k,cost);
    }
};