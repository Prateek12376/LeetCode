class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()<2){
            return false;
        }
        int last=nums[0];
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]!=i+1){
                return false;
            }
            last=nums[i];
        }
        if(nums[nums.size()-1]!=last){
            return false;
        }
        return true;
    }
};