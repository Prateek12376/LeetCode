class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=part.size();
        while(s.length()>0 && s.find(part)<s.length()){
            s.erase(s.find(part),n);
        }
        return s;
    }
};