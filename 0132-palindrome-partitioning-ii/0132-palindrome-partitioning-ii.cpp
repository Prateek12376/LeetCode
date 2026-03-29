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
    int minCut(string s){
        int n=s.size();
        vector<int> dpp(n+1,0);
        dpp[n]=0; // base case

        for(int i=n-1;i>=0;i--){
            int minC = INT_MAX;
            for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)){
                int cuts =1+ dpp[j+1];
                minC = min(minC,cuts);
            }
            }
            dpp[i]=minC;
        }
        return dpp[0]-1;
    }

};