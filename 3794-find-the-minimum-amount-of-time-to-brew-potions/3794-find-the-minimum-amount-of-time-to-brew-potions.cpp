class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int m=mana.size();
        int n=skill.size();
        vector<long long >finished(n,0);
        for(int j=0;j<m;j++){   //j=potion
            for(int i=0;i<n;i++){  //i=wizard
                if(i==0){
                    finished[i]= finished[i]+ 1LL*skill[i]*mana[j];
                }
                else{
                    finished[i]= max(finished[i],finished[i-1]) + 1LL*skill[i]*mana[j];
                }
            }
            for(int i=n-2;i>=0;i--){
                finished[i]= finished[i+1] - 1LL*skill[i+1]*mana[j];
            }
        }
        return finished[n-1];
    }
};