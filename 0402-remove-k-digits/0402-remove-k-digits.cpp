class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && (num[i]-'0'<st.top()-'0')&& k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        if(st.empty()){
            return "0";
        }
        string  result="";
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
        while(result.size()!=0 && result.back()=='0'){
            result.pop_back();
        }
        reverse(result.begin(),result.end());
        if(result.size()==0){
            return "0";
        }
        else{
            return result;
        }
    }
};