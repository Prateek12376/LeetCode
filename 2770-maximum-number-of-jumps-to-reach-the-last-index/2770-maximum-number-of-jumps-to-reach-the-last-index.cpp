class Solution {
public:
    int maxJ(int ind, int jump, vector<int>& nums,int target, vector<vector<int>>& dpp){
        if(ind==nums.size()-1){
            return 0;
        }
        if(dpp[ind][jump]!=-2){
            return dpp[ind][jump];
        }
        int maxi=-1;
        for(int i=ind+1;i<nums.size();i++){
            if(abs(nums[ind]-nums[i])<=target){
                int next=maxJ(i,jump+1,nums,target,dpp);
                if(next!=-1){
                    maxi=max(maxi,next+1);
                }
            }

        }
        return dpp[ind][jump]=maxi;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dpp(n,vector<int>(n,-2));
        int ans= maxJ(0,0,nums,target,dpp);
        if(ans==0){
            return -1;
        }
        return ans;
    }
};