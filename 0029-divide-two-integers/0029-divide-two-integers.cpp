class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor){
            return 1;
        }
        int sign=1;
        if(dividend>=0 && divisor<0){  
        sign=-1;
        }
        if(dividend<0 && divisor>0){
            sign=-1;
        }
        long long n= abs((long long)dividend);
        long long d= abs((long long)divisor);
        long long ans=0;
        while(n>=d){
            int cnt=0;
            while(n>=(d<<(cnt+1))){
                cnt++;
            }
            ans+=(1LL<<cnt);
            n=n-(d*(1LL<<cnt));
        }
        if(ans>INT_MAX && sign== 1){
        return INT_MAX;
        }
        else if(ans>INT_MAX && sign== -1){
            return INT_MIN;
        }
        else{
            return sign*(int)ans;
        }
    }
};