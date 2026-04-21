class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>mpp;
        vector<int>nums;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        for(auto it: mpp){
            nums.push_back(it.second);
        }
        sort(nums.rbegin(),nums.rend());
        int sum=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            count++;
            if(sum>=(arr.size()/2)){
                return count;
            }

        }
        return count;
    }
};