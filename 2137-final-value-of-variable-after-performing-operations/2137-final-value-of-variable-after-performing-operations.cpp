class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int n=operations.size();
        int X=0;
        for(int i=0;i<n;i++){
            string s= operations[i];
            for(int j=0;j<s.size();j++){
                char c=s[j];
                if(c=='+'){
                    X+=1;
                    break;
                }
                if(c=='-'){
                    X-=1;
                    break;
                }
            }
        }
        return X;
    }
};