class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count=0;
        while(true){
            int n=nums.size();
            if(n<2){
                break;
            }
            bool srt=true;
            for(int i=0;i<n-1;i++){
                if(nums[i]>nums[i+1]){
                    srt=false;
                    break;
                }
            }
            if(srt==true){
                break;
            }
            long long best_sum=1LL*(nums[0]+nums[1]);
            int index=0;
            for(int i=1;i<n-1;i++){
                long long sum=1LL*(nums[i]+nums[i+1]);
                if(sum<best_sum){
                    best_sum=sum;
                    srt=false;
                    index=i;
                }
            }
            nums[index]=(int)best_sum;
            nums.erase(nums.begin()+index+1);
            count++;
        }
        return count;
    }
};