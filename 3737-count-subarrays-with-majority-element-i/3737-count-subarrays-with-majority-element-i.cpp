class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        long long ans=0;
       for(int i=0;i<nums.size();i++){
            int cnt=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]==target){
                    cnt++;
                }
                if(cnt*2>(j-i+1)){
                    ans++;
                }
            }
       }
       return (int)ans;
    }
};