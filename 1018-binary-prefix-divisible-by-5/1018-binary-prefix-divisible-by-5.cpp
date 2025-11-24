class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool>ans(nums.size());
        int val=0;
        for(int i=0;i<nums.size();i++){
            val=((val<<1)+nums[i])%5;
            if(val==0){
                ans[i]=true;
            }
            else{
                ans[i]=false;
            }
        }
        return ans;
    }
};