class Solution {
public:
    int removeP(string& s, char fir , char sec , int score){
        stack<char>st;
        int totalP=0;

        for(char ch : s){
            if(!st.empty() && st.top()==fir && ch==sec){
                st.pop();
                totalP+=score;
            }
            else{
                st.push(ch);
            }
        }
        string leftS="";

        while(!st.empty()){
            leftS+=st.top();
            st.pop();
        }
        reverse(leftS.begin(),leftS.end());

        s=leftS;

        return totalP;

    }

    int maximumGain(string s, int x, int y) {
       int ans=0;
       if(x>y){
        ans+= removeP(s,'a','b',x);
        ans+= removeP(s,'b','a',y);
       }
       else{
        ans+= removeP(s,'b','a',y);
        ans+= removeP(s,'a','b',x);
       }
       return ans;
    }
};