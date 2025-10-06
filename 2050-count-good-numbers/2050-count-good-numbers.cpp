class Solution {
public:
    const int Mod= 1e9 +7;
    long long find_count(long long a, long long b){
        if(b==0){
            return 1;
        }
        long long half=find_count(a,b/2);
        long long result= (half*half)%Mod;
        if(b%2==1){
            result=(result*a)%Mod;
        }
        return result;
    }
    int countGoodNumbers(long long n){
        long long even_count= (n+1)/2;
        long long odd_count=n/2;
        long long evenPow= find_count(5,even_count);
        long long oddPow= find_count(4,odd_count);
        return (evenPow*oddPow)%Mod;
    }
};