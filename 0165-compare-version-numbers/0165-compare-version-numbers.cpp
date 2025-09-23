class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1= version1.size();
        int n2=version2.size();
        int l=0;
        int r=0;
        while(l<n1 || r<n2){
            int num1=0;
            int num2=0;
            while( l<n1 && version1[l]!='.'){
                int no= version1[l]-'0';
                num1=num1*10+ no;
                l++;
            }
            while( r<n2 && version2[r]!='.'){
                int no1= version2[r]-'0';
                num2=num2*10+ no1;
                r++;
            }
            if(num1>num2){
                return 1;
            }
            else if(num1<num2){
                return -1;
            }
            else{
                l++;
                r++;
            }

        }
        return 0;
    }
};