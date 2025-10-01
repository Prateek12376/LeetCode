class Solution {
public:
    void find_comb(int oBracket, int cBracket, int count_bracket, string& s, vector<string>& ans){
        if(s.size()==2*count_bracket){
            ans.push_back(s);
            return;
        }
        if(oBracket<count_bracket){
            s.push_back('(');
            find_comb(oBracket+1,cBracket,count_bracket,s,ans);
            s.pop_back();
        }
        if(cBracket<oBracket){
            s.push_back(')');
            find_comb(oBracket,cBracket+1,count_bracket,s,ans);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s;
        find_comb(0,0,n,s,ans);
        return ans;
    }
};