class Solution {
public:
    int Is_Possible(vector<int>& bloomDay, int mid, int m, int k){
        int count=0;
        int No_of_Day=0;
        int n=bloomDay.size();
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid){
                count++;
            }
            else{
                No_of_Day += count/k;
                count=0;
            }
        }
        No_of_Day += count/k;
        if(No_of_Day>=m){
            return 1;
        }
        else{
            return 0;
        }
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long value = (long long)m * (long long)k;
        int n = bloomDay.size();
        if(value>n){
            return -1;
        }
        int maxi=INT_MIN;
        int mini= INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(mini,bloomDay[i]);
            maxi=max(maxi,bloomDay[i]);
        }
        int low=mini;
        int high=maxi;
        int ans=0;
        while(low<=high){
            int mid = low +(high-low)/2;
            int possible= Is_Possible(bloomDay,mid,m,k); 
            if(possible==1){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;

    }
};