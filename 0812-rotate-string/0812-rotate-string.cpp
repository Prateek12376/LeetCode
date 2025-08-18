class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        int m=goal.size();
        if(n!=m){
            return false;
        }
        string S=s+s;  // contains string s two times
        if(S.find(goal)!=string::npos){
            return true;          // string::npos special method that tells not found
        }
        return false;
    }
};