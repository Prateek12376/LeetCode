class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char,int>mp;
        unordered_set<char>st;
        int count=0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            st.insert(s[i]);
        }
        for(auto it : mp){
            char v= it.first;
            int fq1=it.second;
            int fq2;
            char c;
            if(isdigit(v)){
                c= '0'+'9'-v;
                if(st.count(c)){
                    st.erase(c);
                }
            }
            else{
                c= 'a'+'z'-v;
                if(st.count(c)){
                    st.erase(c);
                }
            }
            if(mp.find(c)!=mp.end()){
                fq2=mp[c];
            }
            else{
                fq2=0;
            }
            if(st.count(v)){
                count+=abs(fq1-fq2);
            }
        }
        return count;
    }
};