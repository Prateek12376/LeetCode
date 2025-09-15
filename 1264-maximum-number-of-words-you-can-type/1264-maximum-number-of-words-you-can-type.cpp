class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int count=0;
        map<char,int>broken;
        for(int i=0;i<brokenLetters.size();i++){
            broken[brokenLetters[i]]++;
        }
        for(int i=0;i<text.size();i++){
            bool isposs=  true;
            while(i<text.size() && text[i]!=' '){
                if(broken.find(text[i])!=broken.end()){
                    isposs=false;
                }
                    i++;
            }
            if(isposs==true){
                count++;
            }
        }
        return count;
    }
};