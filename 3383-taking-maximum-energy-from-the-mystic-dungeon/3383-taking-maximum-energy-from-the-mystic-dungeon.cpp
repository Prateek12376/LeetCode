class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        long long ans=LLONG_MIN;
        for(int i=max(0,n-k);i<n;i++){
            long long sum=0;
            for(int j=i;j>=0;j-=k){
                sum+=energy[j];
                ans=max(ans,sum);
            }
            
        }
        return (int)ans;
    }
};