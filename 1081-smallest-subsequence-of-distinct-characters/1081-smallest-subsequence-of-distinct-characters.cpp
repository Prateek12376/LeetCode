class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>freq(26,0);
        vector<int>vis(26,0);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        stack<char>st;
        string ans="";
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']--;
            if(vis[s[i]-'a']==1){
                continue;
            }
            while(!st.empty() && st.top()>s[i] && freq[st.top()-'a']>0){
                vis[st.top()-'a']=0;
                st.pop();
            }   
            st.push(s[i]);
            vis[s[i]-'a']=1;
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};