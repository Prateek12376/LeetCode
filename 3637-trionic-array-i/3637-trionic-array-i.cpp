class Solution {
public:
    bool isTrionic(vector<int>& nums) {
       int n=nums.size();
       int i=0;
       bool f1=false,f2=false,f3=false;
       while(i<n-1 && nums[i]<nums[i+1]){
            i++;
            f1=true;
       }
       int p=i;
       while(i<n-1 && nums[i]>nums[i+1]){
            i++;
            f2=true;
       }
       int q=i;
       while(i<n-1 && nums[i]<nums[i+1]){
        i++;
        f3=true;
       }
       if(i==n-1 && p!=q && f1 && f2 && f3 && q!=n-1){
        return true;
       }
       else{
        return false;
       }
    }
};