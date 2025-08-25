class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>map1;
        vector<int>result;
        for(int i=0;i<nums1.size();i++){
            map1[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            if(map1[nums2[i]]>0){
                result.push_back(nums2[i]);
                map1[nums2[i]]--;
            }
        }
        return result;
    }
};