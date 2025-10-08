class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        
        int p=potions.size()-1;
        int n=spells.size();
        vector<int>ans(n,0);
        for(int i=0;i<spells.size();i++){
            int low=0;
            int count=0;
            int index=-1;
            int high=potions.size()-1;
            while(low<=high){
                int mid= low+ (high-low)/2;
                if(1LL*potions[mid]*spells[i]>=success){
                    index=mid;
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            if(index!=-1){
                ans[i]= p-low+1;
            }
        }
        return ans;
    }
};