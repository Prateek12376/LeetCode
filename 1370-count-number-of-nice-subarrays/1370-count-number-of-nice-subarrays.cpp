class Solution {
public:
    long long atmost_sum(vector<int>& nums, int max_sum){
        if(max_sum<0){
            return 0;
        }
        int l=0;
        int n=nums.size();
        int r=0;
        long long count=0;
        long long sum=0;
        while(r<n){
            sum+= (nums[r])%2;
            while(sum>max_sum){
                sum-= (nums[l])%2;
                l++;
            }
            count+= (r-l+1);
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        long long count= atmost_sum(nums,k)-atmost_sum(nums,k-1);
        return (int)count;
    }
};