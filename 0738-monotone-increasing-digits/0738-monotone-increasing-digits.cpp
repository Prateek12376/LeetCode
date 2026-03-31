class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string nums= to_string(n);
        int n1=nums.size();
        int lastChange=n1;
        for(int i=n1-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                int temp=(nums[i]-'0')-1;
                nums[i]=temp+'0';
                lastChange=i;
            }
        }
        for(int i=lastChange+1;i<n1;i++){
            nums[i]='9';
        }
        int ans=0;
        for(int i=0;i<n1;i++){
            ans=ans*10+ (nums[i]-'0');
        }
        return ans;

    }
};