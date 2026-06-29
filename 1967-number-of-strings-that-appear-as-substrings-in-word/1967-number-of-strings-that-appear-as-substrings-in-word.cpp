class Solution {
public:
    void compute(vector<int>& lps , string& word){
        int len=0;
        int i=1;
        lps[0]=0;
        while(i<word.size()){
            if(word[len]==word[i]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    int numOfStrings(vector<string>& patterns, string word) {
        int count=0;
        for(int ind=0;ind<patterns.size();ind++){
            int n= patterns[ind].size();
            vector<int>lps(n);
            compute(lps,patterns[ind]);
            string pat = patterns[ind];

            int i=0;
            int j=0;
            while(i<word.size()){
                if(pat[j]==word[i]){
                    i++;
                    j++;
                }
                if(j==n){
                    count++;
                    break;
                }
                else if(i<word.size() && word[i]!=pat[j]){
                    if(j!=0){
                        j=lps[j-1];
                    }
                    else{
                        i++;
                    }
                }
                    
            }
        }
        return count;
    }
};