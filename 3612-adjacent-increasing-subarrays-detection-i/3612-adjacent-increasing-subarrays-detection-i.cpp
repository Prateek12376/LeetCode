class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        for(int i=0;i+2*k<=nums.size();i++){
            bool one_sub=true;
            for(int j=i;j-i<k-1;j++){
                if(nums[j]>=nums[j+1]){
                    one_sub=false;
                    break;
                }
            }
            bool second_sub=true;
            for(int j=i+k;j-i<2*k-1;j++){
                if(nums[j]>=nums[j+1]){
                    second_sub=false;
                    break;
                }
            }
            if(one_sub && second_sub){
                return true;
            }
        }
        return false;
    }
};