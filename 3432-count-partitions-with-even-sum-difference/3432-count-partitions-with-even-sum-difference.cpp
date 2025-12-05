class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n-1;i++){
            int sum1=0;
            int sum2=0;
            for(int k=0;k<=i;k++){
                sum1+=nums[k];
            }
            for(int j=i+1;j<n;j++){
                sum2+=nums[j];
            }
            if(abs(sum1-sum2)%2==0){
                count++;
            }

        }
        return count;
    }
};