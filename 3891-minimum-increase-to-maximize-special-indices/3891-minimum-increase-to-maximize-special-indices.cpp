class Solution {
public:
    pair<int,long long> find_minC(int ind, vector<int>& nums, vector<pair<int, long long>>& dpp){
        if(ind<=0){
            return {0,0};
        }
        if(dpp[ind].first!=-1){
            return dpp[ind];
        }

        // not take
        auto nTake = find_minC(ind-1,nums,dpp);
        // take
        pair<int,long long> take ={0,LLONG_MAX };
        if(ind-1>=0 && ind+1<nums.size()){
            long long cost = 1LL*max(0,(max(nums[ind-1],nums[ind+1])+1-nums[ind])); 
            auto prev = find_minC(ind-2,nums,dpp);
            take.first = prev.first+1;
            take.second = prev.second+ cost;
        }

        if(take.first>nTake.first){
            return dpp[ind]=take;
        }
        else if(take.first<nTake.first){
            return dpp[ind]=nTake;
        }
        else{
            return dpp[ind] = {take.first, min(take.second, nTake.second)};
        }
    }
    long long minIncrease(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,long long>>dpp(n,{-1,-1});
        pair<int,long long> ans = find_minC(n-2,nums,dpp);
        return ans.second;
    }
};