class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }
        if(j==-1){
            return;
        }
        for(int i=j+1;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }

        // vector<int>temp;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i] != 0){
        //         temp.push_back(nums[i]);
        //     }
        // }
        // int t= temp.size();
        // for(int i=0;i<temp.size();i++){
        //     nums[i]=temp[i];
        // }
        // for(int i=t;i<nums.size();i++){
        //     nums[i]=0;
        // }
    }
};

