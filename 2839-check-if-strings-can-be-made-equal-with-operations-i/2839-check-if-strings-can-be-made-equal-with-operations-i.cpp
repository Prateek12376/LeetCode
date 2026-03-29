class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1==s2){
            return true;
        }
        int n=s1.size();
        for(int i=n-1;i>=2;i--){
            if(s1[i]!=s2[i]){
                if( s1[i-2]!=s2[i]){
                    return false;
                }
                else{
                    swap(s1[i],s1[i-2]);
                }
            }
        }
        for(int i=0;i<=1;i++){
            if(s1[i]!=s2[i]){
                return false;
            }
        }
        return true;
    }
};