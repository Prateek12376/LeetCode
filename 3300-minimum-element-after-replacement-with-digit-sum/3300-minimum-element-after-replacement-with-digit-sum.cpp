class Solution {
public:
    int find_sum(int n){
        int sum=0;

        while(n>0){
            int n1=n%10;
            sum+=n1;
            n=n/10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int n=nums.size();
        int mini= INT_MAX;
        for(int i=0;i<n;i++){
            int sum_d= find_sum(nums[i]);
            mini=min(mini,sum_d);
        }
        return mini;
    }
};