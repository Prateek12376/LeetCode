class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
       int eI=0;
       int oI=0;
       int n=nums.size();
       for(int i=0;i<n;i++){
        int need=0;
        int left=INT_MIN;
        int right=INT_MIN;
           if(i>0){
                left=1+nums[i]-nums[i-1];
           }
           if(i<n-1){
            right=1+nums[i]-nums[i+1];
           }
           need+= max(0,max(left,right));
           if(i%2==0){
            eI+=need;
           }
           else{
            oI+=need;
           }
       }
       return min(eI,oI);
    }
};