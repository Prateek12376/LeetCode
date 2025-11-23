class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum=0;
        vector<int>one,two;

        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(nums[i]%3==1){
                one.push_back(nums[i]);
            }
            if(nums[i]%3==2){
                two.push_back(nums[i]);
            }
        }
        if(sum%3==0){
            return sum;
        }
        int n_s=0;
        int sum1=0;
        int sum2=0;
        if(sum%3==1){
            if(one.size()>=1){
                sum1=sum-one[0];
            }
            if(two.size()>=2){
                sum2=sum-two[0]-two[1];
            }
            n_s=max(sum1,sum2);
        }
        if(sum%3==2){
            if(two.size()>=1){
                sum1=sum-two[0];
            }
            if(one.size()>=2){
                sum2=sum-one[0]-one[1];
            }
            n_s=max(sum1,sum2);
        }
        return n_s;
        
    }
};