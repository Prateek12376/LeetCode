class Solution {
public:
    void merge(vector<int>& count, vector<pair<int,int>>& arr_I,int left, int mid, int right){
        int size= right-left+1;
        vector<pair<int,int>>temp_arr(size);
        int i=left;
        int j=mid+1;
        int k=0;
        while(i<=mid && j<=right){
            if(arr_I[i].first<=arr_I[j].first){
                temp_arr[k]=arr_I[j];
                k++;
                j++;
            }
            else{
                count[arr_I[i].second]+=(right-j+1);
                temp_arr[k]=arr_I[i];
                i++;
                k++;

            }
        }
        while(i<=mid){
            temp_arr[k]=arr_I[i];
            i++;
            k++;
        }
        while(j<=right){
            temp_arr[k]=arr_I[j];
            j++;
            k++;
        }
        for(int i=left;i<=right;i++){
            arr_I[i]=temp_arr[i-left];
        }
    }
    void merge_sort(vector<int>& count, vector<pair<int,int>>& arr_I, int left, int right){
        if(left<right){
            int mid=left+ (right-left)/2;
            merge_sort(count,arr_I,left,mid);
            merge_sort(count,arr_I,mid+1,right);
            merge(count,arr_I,left,mid,right);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>arr_I(n);
        for(int i=0;i<n;i++){
            arr_I[i]={nums[i],i};
        }
        vector<int>count(n,0);
        merge_sort(count,arr_I,0,n-1);
        return count;
    }
};