class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=1LL*nums[i];
        }
        long long count=0;
        long long need= goal-sum;
        long long val=abs(need);
        long long extra=val%limit;
        count+=val/limit;
        if(extra>0){
            count++;
        }
        return (int)count;
        

    }
};