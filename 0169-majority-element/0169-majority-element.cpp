class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // for(int i=0;i<nums.size();i++){
    //     int count=0;
    //     for(int j=0;j<nums.size();j++){
    //         if(nums[i]==nums[j]){
    //             count++;
    //         }
    //         if(count>nums.size()/2){
    //             return nums[i];
    //         }
    //     }
    // }  
    // return -1;


    // map<int,int>map1;
    // for(int i=0;i<nums.size();i++){
    //     map1[nums[i]]+=1;
    // }
    // for(auto it:map1){
    //     if(it.second>nums.size()/2){
    //         return it.first;
    //     }
    // }
    // return -1;

        int count=0;
        int elm;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                count=1;
                elm=nums[i];
            }
            else if(nums[i]==elm){
                count++;
            }
            else{
                count--;
            }
        }
        int count1=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==elm){
                count1++;
            }
        }
        if(count1>(nums.size())/2){
            return elm;
        }
        else{
            return -1;
        }
    }
};