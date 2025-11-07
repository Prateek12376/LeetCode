class Solution {
public:
    bool canAchieve( long long target, vector<long long>& cities,int r, long long k){
        int n= cities.size();
        vector<long long>range(n,0);
        long long add=0;
        for(int i=0;i<n;i++){
            add+=range[i];
            long long curr= cities[i]+add;
            if(curr<target){
                long long need= target-curr;
                k-=need;
                if(k<0){
                    return false;
                }
                add+=need;
                if(i+2*r+1<n){
                    range[i+2*r+1]-=need;
                }
            }
        }
        return true;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        int n=stations.size();
        vector<long long>cities(n,0);
        vector<long long>prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]= prefix[i]+ 1LL*stations[i];
        }
        for(int i=0;i<n;i++){
            int left= max(0,i-r);
            int right=min(n-1,i+r);
            cities[i]=prefix[right+1]-prefix[left];
        }

        long long mini=LLONG_MAX;
        for(int i=0;i<n;i++){
            mini=min(mini,cities[i]);
        }
        long long maxi=LLONG_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,cities[i]);
        }
        long long high= maxi+1LL*k;
        long long low= mini;
        long long ans=0;
        while(low<=high){
            long long mid= low+ (high-low)/2;

            if(canAchieve(mid,cities,r,1LL*k)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
         
    }
};