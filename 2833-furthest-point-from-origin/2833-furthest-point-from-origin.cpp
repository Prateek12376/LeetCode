class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cnt=0;
        int cnt1=0;
        int cnt2=0;
        unordered_map<char,int>mpp;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='_'){
                cnt++;
            }
            else{
                if(moves[i]=='L'){
                    cnt1++;
                }
                else{
                    cnt2++;
                }
            }
        }
        int maxi=max(cnt2,cnt1);
        int mini=min(cnt1,cnt2);
        int ans = cnt+maxi-mini;
        return ans;
        
    }
};