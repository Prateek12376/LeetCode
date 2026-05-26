class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char>lower;
        unordered_set<char>upper;
        for(int i=0;i<word.size();i++){
            if(islower(word[i])){
                lower.insert(word[i]);
            }
            else{
                upper.insert(word[i]);
            }
        }
        int count=0;
        for(char i='a';i<='z';i++){
            if(lower.count(i) && upper.count(toupper(i))){
                count++;
            }
        }
        return count;
        
    }
};