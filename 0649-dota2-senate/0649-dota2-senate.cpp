class Solution {
public:
    string predictPartyVictory(string senate) {
        int cntR=0,cntD=0, minR=0,minD=0;
        int n=senate.size();
        queue<char>q;
        for(int i=0;i<n;i++){
            q.push(senate[i]);
            if(senate[i]=='R'){
                cntR++;
            }
            else{
                cntD++;
            }
        }

        while(true){
            if(cntR==0){
                return "Dire";
            }
            if(cntD==0){
                return "Radiant";
            }
            char ch = q.front();
            q.pop();
            if(ch=='R'){
                if(minR>0){
                    cntR--;
                    minR--;
                }
                else{
                    minD++;
                    q.push(ch);
                }
            }
            else{
                if(minD>0){
                    minD--;
                    cntD--;
                }
                else{
                    minR++;
                    q.push(ch);
                }
            }
        }
    }
};