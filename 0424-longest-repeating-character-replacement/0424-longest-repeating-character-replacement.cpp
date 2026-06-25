class Solution {
public:
    int characterReplacement(string s, int k) {
       vector<int>freq(26,0);
       int maxFreq=INT_MIN;
       int maxL=INT_MIN;
       int j=0;

        for(int i=0;i<s.size();i++){
            freq[s[i]-'A']++;
            maxFreq= max(maxFreq,freq[s[i]-'A']);

            if((i-j+1)-maxFreq>k){
                freq[s[j]-'A']--;
                j++;
            }

            maxL=max(maxL,i-j+1);
        }
        return maxL;
    }
};