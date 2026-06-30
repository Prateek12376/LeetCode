class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>freq(26,0);
        int l=0;
        int r=0;
        int cnt=0;
        int n=s.size();
        while(r<s.size()){
            freq[s[r]-'a']++;
            if(freq[0]>=1 && freq[1]>=1 && freq[2]>=1){
                cnt+=(n-r);
                freq[s[l]-'a']--;
                l++;
                while(l<r && freq[0]>=1 && freq[1]>=1 && freq[2]>=1){
                    cnt+=(n-r);
                    freq[s[l]-'a']--;
                    l++;
                }

            }
            r++;
        }
        return cnt;
    }
};