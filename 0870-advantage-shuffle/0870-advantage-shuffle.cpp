class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int>ans(n);
        vector<pair<int,int>>arr;
        sort(nums1.begin(),nums1.end());
        for(int i=0;i<n;i++){
            arr.push_back({nums2[i],i});
        }
        sort(arr.begin(),arr.end());
        int l=0;
        int r=n-1;
        for(int i=n-1;i>=0;i--){
            int val=arr[i].first;
            int ind=arr[i].second;

            if(nums1[r]>val && r>=0){
                ans[ind]=nums1[r];
                r--;
            }
            else{
                if(l<n){
                ans[ind]=nums1[l];
                l++;
                }
            }
        }
        return ans;

    }
};