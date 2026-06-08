class Solution {
public:
    int find_day(vector<int>& weights, int maxW){
        int day=1;
        int w=0;

        for(int i=0;i<weights.size();i++){
            if(w+weights[i]>maxW){
                day++;
                w=weights[i];
            }
            else{
                w+=weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {

        int n= weights.size();
        int maxi=INT_MIN;
        int sum=0;

        for(int i=0;i<n;i++){
            sum+=weights[i];
            maxi=max(maxi,weights[i]);
        }

        int low=maxi;
        int high=sum;
        int ans=-1;
        while(low<=high){
            int mid= low+ (high-low)/2;

            int noD = find_day(weights,mid);

            if(noD<=days){
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