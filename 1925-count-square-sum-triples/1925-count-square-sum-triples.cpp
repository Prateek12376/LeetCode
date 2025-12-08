class Solution {
public:
    int countTriples(int n) {
        int count=0;
        int a,b,c;
        for(int i=1;i<=n;i++){
            a=i;
            for(int j=a+1;j<=n;j++){
                b=j;
                c=a*a + b*b;
                int c2= sqrt(c);

                if(c2<=n && c2*c2==c){
                    count+=2;
                }
            }
        }
        return count;
    }
};