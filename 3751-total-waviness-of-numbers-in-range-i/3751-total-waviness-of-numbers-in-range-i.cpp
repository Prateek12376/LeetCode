class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int cnt=0;
        for(int i=num1;i<=num2;i++){
            int f_prev=-1;
            int s_prev=-1;
            int num=i;
            while(num>0){
                int n1=num%10;
                if(s_prev==-1){
                    s_prev=n1;
                }
                else if(f_prev==-1){
                    f_prev=n1;
                }
                else{
                    if(f_prev>s_prev && f_prev>n1){
                        cnt++;
                    }
                    if(f_prev<s_prev && f_prev<n1){
                        cnt++;
                    }
                    s_prev=f_prev;
                    f_prev=n1;
                }

                num=num/10;
            }
        }
        return cnt;
    }
};