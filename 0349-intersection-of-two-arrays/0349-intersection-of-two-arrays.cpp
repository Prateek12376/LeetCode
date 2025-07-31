class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int>vArray(nums2.size());
        set<int>ans;
        vector<int>arr1;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]&& vArray[j]==0){
                    ans.insert(nums1[i]);
                    vArray[j]=1;
                    break;
                }
                if(nums2[j]>nums1[i]){
                    break;
                }
            }
        }
        for(auto it:ans){
            arr1.push_back(it);
        }
        return arr1;
    }
};