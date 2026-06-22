class Solution {
public:
    int find_maxCost(int i, int j, vector<int>& nums , vector<vector<int>>& dpp){
        if(i>j){
            return 0;
        }
        if(dpp[i][j]!=-1){
            return dpp[i][j];
        }
        int maxC= INT_MIN;

        for(int k=i;k<=j;k++){
            int cost  = nums[i-1]*nums[k]*nums[j+1] + find_maxCost(i,k-1,nums,dpp)+ find_maxCost(k+1,j,nums,dpp);
            maxC =max(maxC,cost);
        }
        return dpp[i][j]=maxC;
    }
    int maxCoins(vector<int>& nums) {
        int n= nums.size();

        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>>dpp(n+2,vector<int>(n+2,-1));

        return find_maxCost(1,n,nums,dpp);
    }
};