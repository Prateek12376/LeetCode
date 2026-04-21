class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0;
        int ind=0;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if((i+1)-ind>k){
                sum-=nums[ind];
                ind++;
            }
            if((i+1)-ind==k){
                ans=max(ans,sum);
            }
        }
        double result = (double)ans/k;
        return result;
        
    }
};