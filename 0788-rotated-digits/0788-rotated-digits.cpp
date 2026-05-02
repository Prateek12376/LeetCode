class Solution {
public:
    int rotatedDigits(int n) {
        unordered_map<int,int>mpp;
        mpp[0]=0;
        mpp[1]=1;
        mpp[8]=8;
        mpp[2]=5;
        mpp[5]=2;
        mpp[6]=9;
        mpp[9]=6;
        int count=0;
        for(int i=1;i<=n;i++){
            int num=i;
            bool f1=true;
            bool f2=false;
            while(num>0){
                int n1=num%10;
                if(mpp.find(n1)==mpp.end()){
                    f1=false;
                }
                if(mpp.find(n1)!=mpp.end() && mpp[n1]!=n1){
                    f2=true;
                }
                num=num/10;
            }
            if(f1==true && f2==true){
                count++;
            }
        }
        return count;
    }
};