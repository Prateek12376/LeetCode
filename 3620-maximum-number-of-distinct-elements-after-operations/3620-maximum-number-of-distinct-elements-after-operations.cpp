class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long prev= LLONG_MIN;
        int count=0;
        for(int i=0;i<nums.size();i++){
            long long lower= (1LL)*nums[i]-k;
            long long upper=1LL*nums[i]+k;
            long long given = max(prev+1,lower);
            if(given<=upper){
                count++;
                prev=given;
            }
        }
        return count;
    }
};