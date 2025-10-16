class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n=nums.size();
        unordered_map<int,int>count;
        for(int i=0;i<n;i++){
            int rem = ((nums[i]%value)+value)%value;
            count[rem]++;
        }
        int mex=0;
        while(count[(mex%value)]>0){
            count[(mex%value)]--;
            mex++;
        }
        return mex;
    }
};