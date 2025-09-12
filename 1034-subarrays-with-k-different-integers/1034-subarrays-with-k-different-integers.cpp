class Solution {
public:
    long long atmost_k_elm(vector<int>& nums, int max_elm){
        if(max_elm<0){
            return 0;
        }
        int n=nums.size();
        int l=0;
        int r=0;
        int count=0;
        map<int,int>mpp;
        while(r<n){
            mpp[nums[r]]++;
            while(mpp.size()>max_elm){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0){
                    mpp.erase(nums[l]);
                }
                l++;
            }
            if(mpp.size()<=max_elm){
                count+=(r-l+1);
            }
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        long long count = atmost_k_elm(nums,k)- atmost_k_elm(nums,k-1);
        return (int)count;
    }
};