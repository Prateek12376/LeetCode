class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n= nums.size();
        k=k%n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        
        // vector<int>newArr(k);
        // k=k%n;
        // for(int i=0;i<k;i++){
        //     newArr[i]=nums[(n-k)+i];
        // }
        // for(int i=n-1;i>=k;i--){
        //     nums[i]=nums[i-k];
        // }
        // for(int i=0;i<k;i++){
        //     nums[i]=newArr[i];
            
        // }
    }
};