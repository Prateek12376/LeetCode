class Solution {
public:
    int mySqrt(int x) {
        int low=1;
        int high=x;
        int sqrt=1;
        if(x==0){
            return 0;
        }
        while(low<=high){
            long long mid=low+(high-low)/2;
            if((mid*mid)<=x){
                sqrt=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return sqrt;
    }
};