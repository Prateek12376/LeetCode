class Solution {
public:
    bool isFreqSame(int freq[], int window_freq[]){
        for(int i=0;i<26;i++){
            if(freq[i]!=window_freq[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int freq[26]={0};
        for(int i=0;i<s1.size();i++){
            freq[s1[i]-'a']++;
        }
        int windowSize  = s1.size();

        for(int i=0;i<s2.size();i++){
            int window_index=0;
            int index=i;
            int window_freq[26]={0};
            while(window_index < windowSize && index<s2.size()){
                window_freq[s2[index]-'a']++;
                window_index++;
                index++;
            }
            if(isFreqSame(freq,window_freq)){
                return true;
            }
        }
        return false;
    }
};