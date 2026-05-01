class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int mul=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            mul+=i*nums[i];
        }
        int maxi=mul;
        for(int i=1;i<n;i++){
            mul=mul+ sum-(n*nums[n-i]);
            maxi=max(maxi,mul);
        }
        return maxi;
    }
};