class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>preSumMap;
        int sum=0;
        int count=0;
        preSumMap[0]=1;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            int rem=sum-k;
            if(preSumMap.find(rem)!=preSumMap.end()){
                count=count+preSumMap[rem];
            }   
            preSumMap[sum]++;  
        }
        return count;
    }
};