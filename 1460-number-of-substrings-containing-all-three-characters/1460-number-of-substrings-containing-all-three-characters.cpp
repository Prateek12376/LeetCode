class Solution {
public:
    long long atmost_sub_string(string& s, int k){
        int n=s.size();
        int l=0;
        int r=0;
        long long count=0;
        map<char,int>mpp;
        while(r<n){
            mpp[s[r]]++;
            while(mpp.size()>k){
                mpp[s[l]]--;
                if(mpp[s[l]]==0){
                    mpp.erase(s[l]);
                }
                l++;
            }
            if(mpp.size()<=k){
                count+=(r-l+1);
            }
            r++;
        }
        return count;
    }
    int numberOfSubstrings(string s) {
        long long count = atmost_sub_string(s,3)- atmost_sub_string(s,2);
        return (int)count;
    }
};