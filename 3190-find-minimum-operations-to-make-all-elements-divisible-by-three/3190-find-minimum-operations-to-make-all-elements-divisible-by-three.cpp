class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int op=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%3!=0){
                int num= nums[i]%3;
                if(num+1==3){
                    op++;
                }
                if(num-1==0){
                    op++;
                }
            }
        }
        return op;
    }
};