class Solution {
public:
    int reverseNum(int num) {
        int rev = 0;
        while (num > 0) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int num= nums[i];
            int newN=reverseNum(num);
            if(mpp.find(num)!=mpp.end()){
                ans=min(ans,abs(mpp[num]-i));
            }
            mpp[newN]=i;
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};