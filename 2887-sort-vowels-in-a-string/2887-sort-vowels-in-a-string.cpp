class Solution {
public:
    bool isvowel(char s){
        if(s=='A'|| s=='a'|| s=='E'||s=='e'||s=='I'||s=='i'||s=='O'||s=='o'||s=='U'||s=='u'){
            return true;
        }
        else{
            return false;
        }
    }
    string sortVowels(string s) {
        vector<char>vowels;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(isvowel(s[i])){
                vowels.push_back(s[i]);
            }
        }
        sort(vowels.begin(),vowels.end());
        int index=0;
        for(int i=0;i<n;i++){
            if(isvowel(s[i])){
                s[i]= vowels[index];
                index++;
            }
        }
        return s;
    }
};