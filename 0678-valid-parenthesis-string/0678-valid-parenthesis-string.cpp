class Solution {
public:
    bool checkValidString(string s) {
        int mini=0;
        int maxi=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                mini=mini+1;
                maxi=maxi+1;
            }
            else if(s[i]==')'){
                mini=mini-1;
                maxi=maxi-1;
            }
            else{
                mini=mini-1;
                maxi=maxi+1;
            }
            if(mini<0){
                mini=0;
            }
            if(maxi<0){
                return false;
            }
        }
        if(mini==0){
            return true;
        }
        else{
            return false;
        }
    }
};