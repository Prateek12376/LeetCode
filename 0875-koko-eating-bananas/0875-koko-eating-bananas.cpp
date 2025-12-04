class Solution {
public:
    int find_max(vector<int>& piles){
        int maxi=INT_MIN;
        int n=piles.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,piles[i]);
        }
        return maxi;
    }
    long long find_Total_hours(vector<int>& piles,int mid){
        long long hours = 0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            hours+= ceil((double)piles[i]/(double)mid);
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int ans=1;
        int high= find_max(piles);
        while(low<=high){
            int mid= low + (high-low)/2;
            long long total_hours= find_Total_hours(piles,mid);
            if(total_hours<=h){
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