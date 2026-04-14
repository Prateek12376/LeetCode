class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0;
        int oB=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                oB++;
            }
            else{
                if(oB>0){
                    oB--;
                }
                else{
                    count++;
                }
            }
        }
        count+=oB;
        return count;
    }
};