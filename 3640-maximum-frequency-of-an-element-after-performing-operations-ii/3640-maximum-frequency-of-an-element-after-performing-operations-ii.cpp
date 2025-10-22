class Solution {
public:
    int find_lower(vector<int>& nums, int target){
        int low=0;
        int high=nums.size();
        while(low<high){
            int mid = low+(high-low)/2;
            if(nums[mid]>=target){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
    int find_upper(vector<int>& nums, int target){
        int low=0;
        int high=nums.size();
        while(low<high){
            int mid = low+(high-low)/2;
            if(nums[mid]>target){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        if(nums.size()==1){
            return 1;
        }
        sort(nums.begin(),nums.end());
        int n= nums.size();
        unordered_map<long long,int>map1;
        set<long long>candi;
        for(int i=0;i<n;i++){
            map1[1LL*nums[i]]++;
            candi.insert(1LL*nums[i]);
            candi.insert(1LL*nums[i]+1LL*k);
            candi.insert(1LL*nums[i]-1LL*k);
        }
        int ans=0;
        for(auto target : candi){
            int left= find_lower(nums,target-k);
            int right=find_upper(nums,target+k);
            int total= right-left;
            int op= total-map1[target];
            int achived= min(op,numOperations)+ map1[target];
            ans=max(ans,achived);
        }
        return ans;
    }
};