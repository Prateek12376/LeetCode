class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int mini=nums[0];
        int cnt=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]-mini>k){
                cnt++;
                mini=nums[i];
            }
        }
        return cnt;
    }
};