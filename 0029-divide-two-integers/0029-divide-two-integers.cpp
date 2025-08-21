class Solution {
public:
    int divide(int dividend, int divisor) {
        int sn1=1;
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long long a=dividend;
        long long b=divisor;

        if (dividend<0){
            a=-a;
            sn1*=-1;
        }
        else if(divisor<0){
            b=-b;
            sn1*=-1;
        }
        long long ans=0;
        ans=a/b;

        ans=sn1*ans;
        if(ans<INT_MIN){
            return INT_MIN;
        }
        else if(ans>INT_MAX){
            return INT_MAX;
        }
        else{
            return (int)ans;
        }
    }
};