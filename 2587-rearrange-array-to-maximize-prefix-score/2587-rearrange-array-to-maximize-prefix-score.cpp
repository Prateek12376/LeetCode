class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());

        long long sum=0;
        int cnt=0;

        for(int i=0;i<nums.size();i++){
            if((1LL*nums[i]+sum)>0){
                cnt++;
                sum+=1LL*nums[i];
            }
            else{
                break;
            }
        }
        return cnt;
    }
};