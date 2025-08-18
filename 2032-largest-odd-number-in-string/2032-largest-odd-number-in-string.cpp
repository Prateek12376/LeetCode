class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        int pos=n-1;
        while(pos>=0){
            if((num[pos]-'0')%2!=0){
                return num.substr(0,pos+1);
            }
            pos--;
        }
        return "";
    }
};