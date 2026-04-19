class Solution {
public:
    int minimumSwap(string s1, string s2) {
        if(s1==s2){
            return 0;
        }
        int xy=0;
        int yx=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]=='x' && s2[i]=='y'){
                xy++;
            }
            if(s1[i]=='y' && s2[i]=='x'){
                yx++;
            }
        }
        if((xy+yx)%2!=0){
            return -1;
        }
        int ans= xy/2+ yx/2 + (yx%2)*2;
        return ans;
        
    }
};