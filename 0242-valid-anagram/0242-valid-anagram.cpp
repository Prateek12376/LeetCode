class Solution {
public:
    bool isFreqSame(int freq_s[], int freq_t[]){
        for(int i=0;i<26;i++){
            if(freq_s[i]!=freq_t[i]){
                return false;
            }
        }
        return true;
    }
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        int freq_s[26]={0};
        int freq_t[26]={0};
        for(int i=0;i<s.size();i++){
            freq_s[s[i]-'a']++;
            freq_t[t[i]-'a']++;
        }
        if(isFreqSame(freq_s,freq_t)){
            return true;
        }
        else{ 
            return false;
        }
    }
};