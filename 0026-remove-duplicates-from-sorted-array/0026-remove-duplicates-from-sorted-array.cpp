class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>set1;
        for(int i=0;i<nums.size();i++){
            set1.insert(nums[i]);
        }
        int index=0;
        for(auto it:set1){
            nums[index]= it;
            index++;
        }
        return index;
    }
};