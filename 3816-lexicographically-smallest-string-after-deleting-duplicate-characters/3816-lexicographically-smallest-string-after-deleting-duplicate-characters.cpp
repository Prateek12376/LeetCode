class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        vector<int>freq(26,0);
        // vector<int>rem(26,0);
        // for(int i=0;i<s.size();i++){
        //     rem[s[i]-'a']++;
        // }
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        stack<char>st;
        for(int i=0;i<s.size();i++){
            // freq[s[i]-'a']++;
            // rem[s[i]-'a']--;
            while(!st.empty() && st.top()>s[i] && (freq[st.top()-'a'])>1){
                freq[st.top()-'a']--;
                st.pop();
            }
            st.push(s[i]);
        }
        string ans ="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int j=ans.size()-1;
        while(j>0 && freq[ans[j]-'a']>1){
            freq[ans[j]-'a']--;
            j--;
        }
        string ans1="";
        for(int i=0;i<=j;i++){
            ans1+=ans[i];
        }
        return ans1;
    }
};