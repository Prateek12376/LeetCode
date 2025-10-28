class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int selection=0;
        int sum=0;
        for(auto it: nums){
            sum+=it;
        }
        int sum_up_to_zero=0;
        for(int i=0;i<nums.size();i++){
            sum_up_to_zero+=nums[i];
            if(nums[i]==0){
                if(sum- 2*sum_up_to_zero==0){
                    selection+=2;
                }
                if(abs(sum-2*sum_up_to_zero)==1){
                    selection+=1;
                }
            }
        }
        return selection;
    }
};