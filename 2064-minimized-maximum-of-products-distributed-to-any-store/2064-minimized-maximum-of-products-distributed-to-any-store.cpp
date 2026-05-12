class Solution {
public:
    int find_n(int quant, vector<int>& quantities){
        int cnt=0;
        for(int i=0;i<quantities.size();i++){
            cnt+=quantities[i]/quant;
            if(quantities[i]%quant>0){
                cnt++;
            }
        }
        return cnt;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int high=INT_MIN;
        int low=1;
        for(int i=0;i<quantities.size();i++){
            high=max(high,quantities[i]);
        }
        int ans=-1;
        while(low<=high){
            int mid= low + (high-low)/2;

            int number = find_n(mid,quantities);
            if(number<=n){
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