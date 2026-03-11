class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0){
            return 1;
        }
        string s="";
        while(n>=1){
            if(n%2==1){
                s+='1';
            }
            else{
                s+='0';
            }
            n=n/2;
        }
        reverse(s.begin(),s.end());
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='1'){
                s[i]='0';
            }
            else{
                s[i]='1';
            }
        }
        int num=0;
        int p2=1;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='1'){
                num+=p2;
            }
            p2=p2*2;
        }
        return num;
    }
};