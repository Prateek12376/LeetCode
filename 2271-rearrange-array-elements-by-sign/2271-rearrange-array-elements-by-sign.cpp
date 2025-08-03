class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>nums2(n);
        int posIndex=0;
        int negIndex=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                nums2[posIndex]=nums[i];
                posIndex+=2;
            }
            else{
                nums2[negIndex]=nums[i];
                negIndex+=2;
            }
        }
        return nums2;
    }
};