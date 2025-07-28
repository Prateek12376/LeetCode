class Solution {
public:
    int reverse(int x,int sign=1) {
        long long num = x;
        if(num<0){
            sign=-1;
            num=-num;
        }
        long long  revN=0;
        while(num>0){
            int lastDigit = num%10;
            revN = revN*10 + lastDigit;
            num=num/10;
        }
        revN= sign*revN;
          if (revN > INT_MAX || revN < INT_MIN)
                return 0;
            else{
                return revN;
            }
    }
};