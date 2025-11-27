class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long n=nums.size();
        vector<long long>prefix(n+1,0);
        for(long long i=0;i<nums.size();i++){
            prefix[i+1]= prefix[i]+ 1LL*nums[i];
        }
        vector<long long>maxi(k,LLONG_MAX);
        maxi[0]=0;

        long long sum=LLONG_MIN;
        long long currSum;
        int j=1;

        while(j<prefix.size()){
            int r=j%k;
            if(maxi[r]!=LLONG_MAX){
                currSum=prefix[j]-maxi[r];
                if(currSum>sum){
                    sum=currSum;
                }
            }
            if(prefix[j]<maxi[r]){
                maxi[r]=prefix[j];
            }
            j++;
        }
        if(sum==LLONG_MIN){
            return 0;
        }
        return sum;
    }
};