class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n= nums.size();
        int xorA=0;
        for(int i=0;i<n;i++){
            xorA=xorA^nums[i];
        }
        long long r_most_set= (long long)xorA &(-(long long)xorA);
        int b1=0;
        int b2=0;
        for(int i=0;i<n;i++){
            if((nums[i]& r_most_set)!=0){
                b1=b1^nums[i];
            }
            else{
                b2=b2^nums[i];
            }
        }
        return {b1,b2};
    }
};