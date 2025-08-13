class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid= low+ (high-low)/2;
            int missing = arr[mid]-(mid+1);
            if(missing<k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high+k +1;    
        // ans= arr[high]+more  , more=k-missing, missing=arr[high]-(high+1)

        // ans=arr[high]+k-arr[high]+high+1
        // ans=high+k+1
    }
};