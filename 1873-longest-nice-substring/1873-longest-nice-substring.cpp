class Solution {
public:
    string longestNiceSubstring(string s) {
        string res=s;
        if(res.size()<2){
            return "";
        }
        unordered_set<char>st(res.begin(),res.end());
        for(int i=0;i<res.size();i++){
            char c = res[i];
            if(st.count(tolower(c))==0 || st.count(toupper(c))==0){
                string left = longestNiceSubstring(res.substr(0,i));
                string right=longestNiceSubstring(res.substr(i+1));

                if(left.size()>=right.size()){
                    return left;
                }
                else{
                    return right;
                }
            }
        }
        return res;
    }
};