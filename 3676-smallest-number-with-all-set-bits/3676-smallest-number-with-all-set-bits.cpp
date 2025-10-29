class Solution {
public:
    int smallestNumber(int n) {
        int q=0;
        while(true){
            int num=1<<q;
            if(num>n){
                return num-1;
                break;
            }
            q++;
        }
    }
};