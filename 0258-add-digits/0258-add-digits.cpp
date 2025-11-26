class Solution {
public:
    int addDigits(int num) {
        while(num>9){
            int sum=0;
            while(num>0){
                int n1=num%10;
                sum+=n1;
                num=num/10;
            }
            num=sum;
        }
        return num;
    }
};