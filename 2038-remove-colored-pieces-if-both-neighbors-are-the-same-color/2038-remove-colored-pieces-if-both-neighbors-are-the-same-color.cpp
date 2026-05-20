class Solution {
public:
    bool winnerOfGame(string colors) {
        int n= colors.size();
        int countA=0;
        int countB=0;
        for(int i=1;i<n-1;i++){
            if(colors[i]=='A'){
                if(colors[i]==colors[i+1] && colors[i]==colors[i-1]){
                    countA++;
                }
            }
            else{
                if(colors[i]==colors[i+1] && colors[i]==colors[i-1]){
                    countB++;
                }
            }
        }
        if(countA>countB){
            return true;
        }
        else{
            return false;
        }
        
    }
};