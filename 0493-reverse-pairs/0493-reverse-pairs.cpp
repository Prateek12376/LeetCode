class Solution {
public:
    void merge(vector<int>& nums,int low, int mid, int high){
        vector<int>temp;
        int left=low;
        int right=mid+1;
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;    
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }
    int count_pairs(vector<int>& nums,int low , int mid, int high){
        int right=mid+1;
        int count=0;
        for(int i=low;i<=mid;i++){
            while(right<=high && (long long)nums[i]>2*(long long)nums[right]){
                right++;
            }
            count=count+(right-(mid+1));
        }
        return count;
    }
    int m_s(vector<int>& nums,int low,int high){
        int count=0;
        if(low==high){
            return count ;
        }
        int mid=(low+high)/2;
        count+=m_s(nums,low,mid);
        count+=m_s(nums,mid+1,high);
        count+=count_pairs(nums,low,mid,high);
        merge(nums,low,mid,high);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return m_s(nums,0,n-1);
    }
};