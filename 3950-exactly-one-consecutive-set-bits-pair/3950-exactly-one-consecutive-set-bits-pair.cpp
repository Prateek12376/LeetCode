class Solution {
public:
    bool consecutiveSetBits(int n) {
        int count=0;
        bool f1=false;
        bool f2=false;
        while(n>0){
            if(n%2==1){
                if(f1==false){
                    f1=true;
                }
                else if(f1==true && f2 == false){
                    f2=true;
                }
                if(f1==true && f2==true){
                    count++;
                    f2=false;
                }
            }
            else{
                f1=false;
                f2=false;
            }
            n=n/2;
        }
        if(count==1){
            return true;
        }
        else{
            return false;
        }
    }
};