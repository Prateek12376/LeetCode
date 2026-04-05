class Solution {
public:
    bool judgeCircle(string moves) {
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='U'){
                cnt1--;
            }
            if(moves[i]=='D'){
                cnt1++;
            }
            if(moves[i]=='L'){
                cnt2--;
            }
            if(moves[i]=='R'){
                cnt2++;
            }
        }
        if(cnt1==0 && cnt2==0){
            return true;
        }
        else{
            return false;
        }
    }
};