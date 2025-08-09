class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int preffix=1;
        int suffix=1;
        int max_product = INT_MIN;
        for(int i=0;i<n;i++){
            if(preffix==0){
                preffix=1;
            }
            if(suffix==0){
                suffix=1;
            }
            preffix = preffix*nums[i];
            suffix = suffix*nums[n-i-1];
            max_product = max(max_product,max(preffix,suffix));
        }
        return max_product;
    }

};