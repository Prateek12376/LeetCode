class Solution {
public:
    bool isVowel(char s){
        if(s=='a'|| s=='e'||s=='i'||s=='o'||s=='u'){
            return true;
        }
        else{
            return false;
        }
    }
    string sortVowels(string s) {
        int n=s.size();
        vector<char>vowel;
        unordered_map<char,int>freq,fI;

        for(int i=0;i<n;i++){
            if(isVowel(s[i])==true){
                vowel.push_back(s[i]);
                freq[s[i]]++;
                if(fI.find(s[i])==fI.end()){
                    fI[s[i]]=i;
                }
            }
        }
        sort(vowel.begin(),vowel.end(),[&](char a ,char b){
            if(freq[a]!=freq[b]){
            return freq[a]>freq[b];
        }
        return fI[a]<fI[b];
        });
        int ind=0;
        string ans="";
        for(int i=0;i<n;i++){
            if(isVowel(s[i])==true){
                ans+=vowel[ind];
                ind++;
            }
            else{
                ans+=s[i];
            }
        }
        return ans; 
    }
};
