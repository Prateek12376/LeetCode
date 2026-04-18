class Solution {
public:
    int find_R(int n){
        int num=0;
        while(n>0){
            int n1=n%10;
            num=num*10+n1;
            n=n/10;
        }
        return num;
    }
    int mirrorDistance(int n) {
        int rNum=find_R(n);
        return abs(rNum-n);
    }
};