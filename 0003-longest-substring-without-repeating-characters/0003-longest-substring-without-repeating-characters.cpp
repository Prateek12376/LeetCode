class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int left=0;
        int right=0;
        int maxLen=0;
        vector<int>hash(256,-1);
        while(right<n){
            if(hash[s[right]]!=-1){
                if(hash[s[right]]>=left){
                    left=hash[s[right]]+1;
                }
            }
            int len= right-left+1;
            maxLen=max(maxLen,len);
            hash[s[right]]=right;
            right++;
        }
        return maxLen;
    }
};