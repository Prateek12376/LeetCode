class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && num[i]<st.top()){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        if(st.empty()){
            return "0";
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int ind3=0;
        while(ind3<ans.size() && ans[ind3]=='0'){
            ind3++;
        }
        ans= ans.substr(ind3);
        if(ans.size()==0){
            return "0";
        }

        return ans;
    }
};