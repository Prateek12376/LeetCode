class Solution {
public:
    int find_ways(int index,vector<int>& nums, int target, int curr_sum){
        if(index==nums.size()){
            if(curr_sum==target){
                return 1;
            }
            else{
                return 0;
            }
        }
        int add_one = find_ways(index+1,nums,target,curr_sum+nums[index]);
        int sub_one=  find_ways(index+1,nums,target,curr_sum-nums[index]);

        return add_one + sub_one;
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int total=0;
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        if(target>total){
            return 0;
        }
        if((total-target)%2!=0){
            return 0;
        }
        int nT= (total-target)/2;

        vector<vector<int>>dpp(n,vector<int>(nT+1,0));

        if(nums[0]==0){
            dpp[0][0]=2;
        }
        else{
            dpp[0][0]=1;
        }
        if(nums[0]<=nT && nums[0]!=0){
            dpp[0][nums[0]]=1;
        }

        for(int i=1;i<n;i++){
            for(int sum=0;sum<=nT;sum++){
                int not_pick = dpp[i-1][sum];
                int pick =0;
                if(nums[i]<=sum){
                    pick = dpp[i-1][sum-nums[i]];
                }
                dpp[i][sum]=pick+not_pick;
            }
        }
        return dpp[n-1][nT];

    }
};