class Solution {
public:
    int getMinSwaps(string num, int k) {
        string  perm =  num;
        while(k--){
            next_permutation(perm.begin(),perm.end());

        }
        int ans=0;
        for(int i=0;i<perm.size();i++){
            if(perm[i]==num[i]){
                continue;
            }
            int j=i+1;
            while(num[j]!=perm[i]){
                j++;
            }
            while(j>i){
                swap(num[j],num[j-1]);
                ans++;
                j--;
            }
        }
        return ans;
       
    }
};