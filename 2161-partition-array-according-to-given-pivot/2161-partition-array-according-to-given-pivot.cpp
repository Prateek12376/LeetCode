class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        int cnt=0;
        vector<int>a1;
        vector<int>a2;
        vector<int>ans(n);

        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                a1.push_back(nums[i]);
            }
            else if( nums[i]>pivot){
                a2.push_back(nums[i]);
            }
            else{
                cnt++;
            }
        }

        int ind=0;
        for(int i=0;i<a1.size();i++){
            ans[ind]=a1[i];
            ind++;
        }
        while(cnt>0){
            ans[ind]=pivot;
            ind++;
            cnt--;
        }
        for(int i=0;i<a2.size();i++){
            ans[ind]=a2[i];
            ind++;
        }
        return ans;
        
    }
};