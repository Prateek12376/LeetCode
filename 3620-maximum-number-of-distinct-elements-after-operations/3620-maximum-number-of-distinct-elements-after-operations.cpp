class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long prev= LLONG_MIN;
        int count=0;
        for(int i=0;i<nums.size();i++){
            long long low= (1LL)*nums[i]-k;
            long long high=1LL*nums[i]+k;
            long long assigned = max(prev+1,low);
            if(assigned<=high){
                count++;
                prev=assigned;
            }
        }
        return count;
    }
};