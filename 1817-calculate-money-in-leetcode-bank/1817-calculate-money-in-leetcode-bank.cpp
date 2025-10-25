class Solution {
public:
    int totalMoney(int n) {
        int j=1;
        int sum=0;
        while(n>0){
            for(int i=j;i<=j+6;i++){
                sum+=i;
                n--;
                if(n==0){
                    break;
                }
            }
            j++;
            
        }
        return sum;
    }
};