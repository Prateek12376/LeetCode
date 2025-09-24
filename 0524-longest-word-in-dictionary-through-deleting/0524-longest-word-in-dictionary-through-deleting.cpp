class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int n= dictionary.size();
        string ans="";
        for(int i=0;i<n;i++){
            string word= dictionary[i];
            int j=0;
            int k=0;
            string res="";
            while(j<s.size() && k<word.size()){
                if(s[j]==word[k]){
                    res+=s[j];
                    j++;
                    k++;
                }
                else{
                    j++;
                }
            }
            if(k==word.size()){
                if(res.size()>ans.size()){
                ans=res;
                }
                else if( res.size()== ans.size()){
                    ans=min(res,ans);
                }
            }
        }
        return ans;
    }
};