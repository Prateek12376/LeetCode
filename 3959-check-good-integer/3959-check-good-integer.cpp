class Solution {
public:
    bool checkGoodInteger(int n) {
        int sum=0;
        int sqsum=0;
        while(n>0){
            int n1= n%10;
            sum+=n1;
            int sq = n1*n1;
            sqsum+=sq;
            n=n/10;
        }
        if(sqsum-sum>=50){
            return true;
        }
        else{
            return false;
        }
    }
};