class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        long long ways=1;
        long long mod= 1000000007;
        for(int i=1;i<complexity.size();i++){
            if(complexity[i]<=complexity[0]){
                return 0;
            }
            ways*=1LL*i;
            ways=ways%mod;
        }
        return (int)ways;
    }
};