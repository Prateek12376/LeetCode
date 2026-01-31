class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        for(auto c : letters){
            if(c-'a'>target-'a'){
               return c;
            }
        }
        return letters[0];
    }
};