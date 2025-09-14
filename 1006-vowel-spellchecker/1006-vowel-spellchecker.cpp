class Solution {
public:
    string toLower(string& s){
        string result=s;
        for(auto& ch: result){
            ch= tolower(ch);
        }
        return result;
    }
    string Replace_vowel(string& s){
        string result=s;
        for(auto& ch:result){
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                ch='$';
            }
        }
        return result;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string>exact_set;
        unordered_map<string,string>case_map;
        unordered_map<string,string>vowel_map;

        for(auto word: wordlist){
            exact_set.insert(word);
            string lower_val = toLower(word);
            if(case_map.find(lower_val)==case_map.end()){
                case_map[lower_val]=word;
            }
            string vowel_val= Replace_vowel(lower_val);
            if(vowel_map.find(vowel_val)== vowel_map.end()){
                vowel_map[vowel_val]=word;
            }
        }
        vector<string>ans;
        for(auto query : queries){
            if(exact_set.find(query)!=exact_set.end()){
                ans.push_back(query);
            }
            else{
                string lower_key= toLower(query);
                if(case_map.find(lower_key)!=case_map.end()){
                    ans.push_back(case_map[lower_key]);
                }
                else{
                    string vowel_key= Replace_vowel(lower_key);
                    if(vowel_map.find(vowel_key)!=vowel_map.end()){
                        ans.push_back(vowel_map[vowel_key]);
                    }
                    else{
                        ans.push_back("");
                    }
                }
            }
        }
        return ans;
    }
};