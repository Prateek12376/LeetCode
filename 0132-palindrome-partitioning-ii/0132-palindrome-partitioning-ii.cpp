class Solution {
public:
    bool isPalindrome(int i, int j, string& s){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int minC(int i, int n, string& s, vector<int>& dpp){
        if(i==n){
            return 0;
        }
        if(dpp[i]!=-1){
            return dpp[i];
        }
        int mini=  INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)){
                int mincut =1+minC(j+1,n,s,dpp);
                mini = min(mini,mincut);
            }
        }
        return dpp[i]=mini;
    }
    int minCut(string s){
        int n=s.size();
      vector<int>dpp(n,-1);
      return minC(0,n,s,dpp)-1;
    }

};