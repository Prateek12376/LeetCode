class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int count=0;
        int maxdepth =0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                count++;
                maxdepth=max(maxdepth,count);
            }
            if(s[i]==')'){
                count--;
            }
        }
        return maxdepth;
    }
};