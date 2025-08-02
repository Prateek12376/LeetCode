class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int>result;
        // for(int i=0;i<nums.size();i++){
        //    for(int j=i+1;j<nums.size();j++){
        //         if(nums[i]+nums[j]==target){
        //             return result = {i,j};
                    
        //         }
        //    }
        // }
        // return result;
        map<int,int>map1;
        for(int i=0;i,nums.size();i++){
            int a=nums[i];
            int more = target-a;
            if(map1.find(more) !=map1.end()){
                return {map1[more],i};
            }
            map1[a]=i;
        }
        return {};
    }
};