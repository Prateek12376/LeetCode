class Solution {
public:
    bool hasSameDigits(string s) {
        
        while(s.size()>2){
            string str;
            for(int i=0;i<s.size()-1;i++){
                int a=s[i]-'0';
                int b=s[i+1]-'0';
                int c= (a+b)%10;
                str+=to_string(c);
            }
            s=str;
        }
        if(s[0]==s[1]){
            return true;
        }
        else{
            return false;
        }
    }
};