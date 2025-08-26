class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int start=0;
        long long sum=0;
        int minLen=INT_MAX;
        for(int end=0;end<n;end++){
            sum+=nums[end];

            while(sum>=target){
                minLen=min(minLen,end-start+1);
                sum-=nums[start];
                start++;
            }
        }
        if(minLen==INT_MAX){
            return 0;
        }
        else{
            return minLen;
        }
    }
};