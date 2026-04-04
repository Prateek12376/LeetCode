class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0"){
            return "0";
        }
        int n=num1.size();
        int m=num2.size();
        vector<int>result(n+m,0);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int val= (num1[i]-'0')*(num2[j]-'0');
                int sum= result[i+j+1]+ val;
                result[i+j+1]=sum%10;
                result[i+j]+=sum/10;
            }
        }

        int i=0;
        while(i<result.size() && result[i]==0){
            i++;
        }
        string ans="";
        for(int k=i;k<result.size();k++){
            ans+= result[k]+'0';
        }
        if(ans.size()==0){
            return "0";
        }
        else{
            return ans;
        }

    }
};