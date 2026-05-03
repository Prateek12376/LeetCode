class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n=nums.size();
        vector<int>even(n,0);
        vector<int>odd(n,0);
        if(nums[n-1]%2==0){
            even[n-1]=1;
            odd[n-1]=0;

        }
        else{
            even[n-1]=0;
            odd[n-1]=1;
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i]%2==0){
                even[i]= 1+even[i+1];
                odd[i]=odd[i+1];
            }
            else{
                even[i]=even[i+1];
                odd[i]=1+odd[i+1];
            }
        }
        vector<int>ans(n,0);
        for(int i=0;i<n-1;i++){
            if(nums[i]%2==0){
                ans[i]=odd[i+1];
            }
            else{
                ans[i]=even[i+1];
            }
        }
        return ans;
    }
};