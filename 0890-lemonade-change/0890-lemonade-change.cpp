class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f_5=0;
        int t_10=0;
        int n=bills.size();
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                f_5++;
            }
            else if(bills[i]==10){
                if(f_5>0){
                    f_5--;
                    t_10++;
                }
                else{
                    return false;
                }
            }
            else{
                if(f_5>0&& t_10>0){
                    f_5--;
                    t_10--;
                }
                else if(f_5>=3){
                    f_5=f_5-3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};