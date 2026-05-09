class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score=0;
        int cnt=0;
        for(int i=0;i<events.size();i++){
            if(events[i]=="W"){
                cnt++;
            }
            else if(events[i]=="NB" || events[i]=="WD"){
                score+=1;
            }
            else{
                score+=stoi(events[i]);
            }
            if(cnt==10){
                break;
            }   
        }
        return {score,cnt};
    }
};