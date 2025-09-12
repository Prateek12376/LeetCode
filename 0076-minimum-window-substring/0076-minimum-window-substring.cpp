class Solution {
public:
    string minWindow(string s, string t) {
        int l=0;
        int r=0;
        int minLen=INT_MAX;
        int sIndex=-1;
        int count=0;
        int hash[256]={0};
        for(int i=0;i<t.size();i++){
            hash[t[i]]++;
        }
        while(r<s.size()){
            if(hash[s[r]]>0){
                count+=1;
            }
            hash[s[r]]--;
            while(count==t.size()){
                if((r-l+1)<minLen){
                    sIndex=l;
                    minLen=(r-l+1);
                }
                hash[s[l]]++;
                if(hash[s[l]]>0){
                    count-=1;
                }
                l++;
            }
            r++;
        }
        if(sIndex==-1){
            return "";
        }
        else{
            string res = s.substr(sIndex,minLen);
            return res;
        }
    }
};