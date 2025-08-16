class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n= nums.size();
        long long largest=nums[0];
        long long slargest=LLONG_MIN;
        long long tlargest=LLONG_MIN;
        for(int i=0;i<n;i++){
            if (nums[i] == largest || nums[i] == slargest || nums[i] == tlargest) {
                continue;
            }
            if(nums[i]>largest){
                tlargest=slargest;
                slargest=largest;
                largest=nums[i];
            }
            else if(nums[i]>slargest && nums[i]!=largest){
                tlargest=slargest;
                slargest=nums[i];
            }
            else if(nums[i]>tlargest && nums[i]!=slargest && nums[i]!=largest){
                tlargest = nums[i];
            }
        }
        if(tlargest == LLONG_MIN){
            return largest;
        }
        else{
            return tlargest;
        }
    }
};