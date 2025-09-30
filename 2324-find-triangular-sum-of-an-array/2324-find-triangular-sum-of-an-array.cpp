class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int result;
        if(nums.size()==1){
            result=nums[0];
            return result;
        }
        int n=nums.size();
        while(n>1){
            int index=0;
            for(int i=1;i<n;i++){
                nums[index]=(nums[i]+nums[i-1])%10;
                
                index++;
            }
            n=index;
        }
        result=nums[0];
        return result;
        
    }
};