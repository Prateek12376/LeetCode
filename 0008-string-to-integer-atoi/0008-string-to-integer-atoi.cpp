class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.size();
        while(i<n && s[i]==' '){
            i++;
        }
        int sign=1;
        if(i<n && (s[i]=='-'||s[i]=='+')){
            if(s[i]=='-'){
                sign=-1;
            }
            i++;
        }
        long long num=0;
        while(i<n && isdigit(s[i])){
            num=num*10 + (s[i]-'0');
            i++;
            if(num*sign<INT_MIN){
            return INT_MIN;
            }
            if(num*sign>INT_MAX){
                return INT_MAX;
            }
            
        }

        num=sign*num;
        return (int)(num);
    }
};