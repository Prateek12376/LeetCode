class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<4){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int sum1= nums[n-1]-nums[3];
        int sum2= nums[n-4]-nums[0];
        int sum3=nums[n-3]-nums[1];
        int sum4=nums[n-2]-nums[2];

        return min(sum1,min(sum2,min(sum3,sum4)));
    }
};