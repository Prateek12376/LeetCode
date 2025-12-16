class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n=num.size();
        vector<int>ans(n);

        int i=n-1;
        while(i>=0 || k>0){
            if(i>=0){
                k+=num[i];
                ans[i]=k%10;

                k=k/10;
                i--;
            }
            else{
                ans.insert(ans.begin(),k%10);
                k=k/10;
            }
        }
        return ans;
    }
};