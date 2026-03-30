class Solution {
public:
    bool checkStrings(string s1, string s2) {
        if(s1==s2){
            return true;
        }
        int n=s1.size();
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                for(int j=i+2;j<n;j+=2){
                    if(s1[i]==s2[j]){
                        swap(s2[i],s2[j]);
                        break;
                    }
                }
            }
            if(s1[i]!=s2[i]){
                return false;
            }
        }
        return true;
    }
};