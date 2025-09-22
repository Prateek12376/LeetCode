class Solution {
public:
    bool isPerfectSquare(int num) {
        int low=1;
        int high=num;
        int ans;
        while(low<=high){
            long long mid= 1LL*(low+(high-low)/2);
            if(mid*mid<=num){
                ans=(int)mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        if(ans*ans==num){
            return true;
        }
        else{
            return false;
        }
    }
};