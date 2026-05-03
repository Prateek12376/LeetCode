class Solution {
public:
    int reverseN(int num){
        int n=0;
        while(num>0){
            int n1=num%10;
            n=n*10+n1;
            num=num/10;
        }
        return n;
    }
    int sumOfPrimesInRange(int n) {
        int rNum= reverseN(n);
        int maxi=max(rNum,n);
        int mini=min(rNum,n);
        vector<bool>isPrime(maxi+1,true);
        isPrime[0]=false;
        isPrime[1]=false;
        for(int i=1;i<=maxi;i++){
            if(isPrime[i]==true){
                for(int j=i*i;j<=maxi;j+=i){
                    isPrime[j]=false;
                }
            }
        }
        if(n<10){
            if(isPrime[n]==true){
                return n;
            }
            else{
                return 0;
            }
        }
        int sum=0;
        for(int i=mini;i<=maxi;i++){
            if(isPrime[i]==true){
                sum+=i;
            }
        }
        return sum;
    }
};