class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        int parameter;
        for(int i=n-1;i>=2;i--){
            if(nums[i-1]+nums[i-2]>nums[i]){
                parameter= nums[i]+ nums[i-1]+nums[i-2];
                return parameter;
                
            }
        }
        return 0;
    }
};