class Solution {
public:
    int find_days(vector<int>& weights, int mid){ // mid=capacity of boat in one time
        int n=weights.size();
        int days=1;
        int load=0;
        for(int i=0;i<n;i++){
            if(load + weights[i]>mid){
                days=days+1;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            sum += weights[i];
            maxi=max(maxi,weights[i]);
        }
        int low=maxi;
        int high=sum;
        int ans=0;
        while(low<=high){
            int mid = low+ (high-low)/2;
            int possible_days = find_days(weights,mid);
            if(possible_days<=days){
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