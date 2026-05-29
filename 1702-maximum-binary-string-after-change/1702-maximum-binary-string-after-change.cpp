class Solution {
public:
    string maximumBinaryString(string binary) {
        int n=binary.size();
        int zero=0;
        int zeroI=-1;
        for(int i=0;i<n;i++){
            if(binary[i]=='0'){
                zero++;
                if(zeroI==-1){
                    zeroI=i;
                }
            }
        }

        string res="";
        for(int i=0;i<binary.size();i++){
            if(zero<=1){
                res=binary;
                break;
            }
            if(i==zeroI+zero-1){
                res+='0';
            }
            else{
                res+='1';
            }


        }
        return res;
    }
};