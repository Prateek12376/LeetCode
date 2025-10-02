class Solution {
public:
    void find_letter_comb(string& digits, int index,string& str,vector<string>& ans, map<int,string>& map1){
        if(index==digits.size()){
            ans.push_back(str);
            return;
        }
        int digit = digits[index]-'0';
        string letters = map1[digit];
        for(char c: letters){
            str.push_back(c);
            find_letter_comb(digits,index+1,str,ans,map1);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.empty()){
            return ans;
        }
        string str="";
        map<int,string>map1{
            {2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}
        };
        find_letter_comb(digits,0,str,ans,map1);
        return ans;
        
    }
};