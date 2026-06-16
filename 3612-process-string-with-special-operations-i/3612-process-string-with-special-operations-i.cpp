class Solution {
public:
    string processStr(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                if(!st.empty()){
                    st.pop();
                }
            }
            else if(s[i]=='#'){
                string ans="";
                while(!st.empty()){
                    ans+=st.top();
                    st.pop();
                }
                reverse(ans.begin(),ans.end());
                ans+=ans;
                for(auto it : ans){
                    st.push(it);
                }
            }
            else if(s[i]=='%'){
                string ans="";
                while(!st.empty()){
                    ans+=st.top();
                    st.pop();
                }
                for(auto it: ans){
                    st.push(it);
                }
            }
            else{
                st.push(s[i]);
            }
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());

        return res;
    }
};