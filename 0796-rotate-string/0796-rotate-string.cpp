class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()){
            return false;
        }
        string comb="";
        comb+=s;
        comb+=s;
        for(int i=0;i<comb.size();i++){
            int j=i;
            int k=0;
            while(j<comb.size() && k<goal.size() && comb[j]==goal[k]){
                j++;
                k++;
            }
            if(k==goal.size()){
                return true;
            }
        }
        return false;

    }
};