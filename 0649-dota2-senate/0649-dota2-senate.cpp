class Solution {
public:
    string predictPartyVictory(string senate) {
        int R=0,D=0, mR=0,mD=0;
        int n=senate.size();
        queue<char>q;
        for(int i=0;i<n;i++){
            q.push(senate[i]);
            if(senate[i]=='R'){
                R++;
            }
            else{
                D++;
            }
        }

        while(!q.empty()){
            if(R==0){
                return "Dire";
            }
            if(D==0){
                return "Radiant";
            }
            char ch = q.front();
            q.pop();
            if(ch=='R'){
                if(mR>0){
                    R--;
                    mR--;
                }
                else{
                    mD++;
                    q.push(ch);
                }
            }
            else{
                if(mD>0){
                    mD--;
                    D--;
                }
                else{
                    mR++;
                    q.push(ch);
                }
            }
        }
        return "";
    }
};