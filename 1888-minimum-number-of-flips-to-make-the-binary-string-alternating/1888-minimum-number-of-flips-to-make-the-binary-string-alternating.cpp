class Solution {
public:
    int minFlips(string s) {
        int op1=0;
        int op2=0;
        string s2= s+s;
        int ans= INT_MAX;
        int n= s.size();
        for(int i=0;i<s2.size();i++){
            if(i%2==0 && s2[i]!='1'){
                op1++;
            }
            if(i%2!=0 && s2[i]!='0'){
                op1++;
            }
            if(i%2==0 && s2[i]!='0'){
                op2++;
            }
            if(i%2!=0 && s2[i]!='1'){
                op2++;
            }
            if(i>=n){
                if((i-n)%2==0 && s2[i-n]!='1'){
                    op1--;
                }
                if((i-n)%2!=0 && s2[i-n]!='0'){
                    op1--;
                }
                if((i-n)%2==0 && s2[i-n]!='0'){
                    op2--;
                }
                if((i-n)%2!=0 && s2[i-n]!='1'){
                    op2--;
                }
            }
            if(i>=n-1){
                ans=min(ans,min(op1,op2));
            }
        }
        return ans;
    }
};