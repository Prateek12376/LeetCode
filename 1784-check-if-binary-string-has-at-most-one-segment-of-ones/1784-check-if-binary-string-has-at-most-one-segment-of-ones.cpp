class Solution {
public:
    bool checkOnesSegment(string s) {
        if(s[0]=='0'){
            return false;
        }
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                count++;
                while(s[i]=='1'){
                    i++;
                }
            }
        }
        if(count>1){
            return false;
        }
        else{
            return true;
        }
    }
};