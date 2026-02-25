class Solution {
public:
    bool find_subSetSum(int ind,int target,vector<int>& nums,vector<vector<int>>& dpp){
        if(target==0){
            return true;
        }
        if(ind==0){
            return nums[0]==target;
        }
        if(dpp[ind][target]!=-1){
            return dpp[ind][target];
        }

        bool notPick= find_subSetSum(ind-1,target,nums,dpp);
        bool Pick = false;

        if(target>=nums[ind]){
            Pick= find_subSetSum(ind-1,target-nums[ind],nums,dpp);
        }

        return dpp[ind][target]= notPick || Pick;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        int target=sum/2;
        vector<vector<int>>dpp(n,vector<int>(target+1,-1));
        return find_subSetSum(n-1,target,nums,dpp);
    }
};