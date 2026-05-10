class Solution {
public:
    int maxJ(int ind,vector<int>& nums,int target, vector<int>& dpp){
        if(ind==nums.size()-1){
            return 0;
        }
        if(dpp[ind]!=-1){
            return dpp[ind];
        }
        int maxi=-1e5;
        for(int i=ind+1;i<nums.size();i++){
            if(abs(nums[ind]-nums[i])<=target){
                int next=maxJ(i,nums,target,dpp);
                if(next!=-1e5){
                    maxi=max(maxi,next+1);
                }
            }

        }
        return dpp[ind]=maxi;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>dpp(n,-1);
        int ans= maxJ(0,nums,target,dpp);
        if(ans<=0){
            return -1;
        }
        return ans;
    }
};