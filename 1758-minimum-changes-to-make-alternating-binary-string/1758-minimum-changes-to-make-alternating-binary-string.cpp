class Solution {
public:
    int minOperations(string s) {
        int op1=0;
        int op2=0;
        for(int i=0;i<s.size();i++){
            if(i%2!=0 && s[i]!='1'){
                op1++;
            }
            else if(i%2==0 && s[i]!='0'){
                op1++;
            }
        }
        for(int i=0;i<s.size();i++){
            if(i%2==0 && s[i]!='1'){
                op2++;
            }
            else if(i%2!=0 && s[i]!='0'){
                op2++;
            }
        }
        return min(op1,op2);

    }
};