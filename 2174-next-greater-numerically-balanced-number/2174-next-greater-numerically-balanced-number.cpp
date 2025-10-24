class Solution {
public:
    bool isBalanced(int num){
        int arr[10]={0};
        while(num>0){
            int x=num%10;
            if(x==0){
                return false;
            }
            arr[x]++;
            num=num/10;
        }
        for(int i=1;i<10;i++){
            if(arr[i]!=0 && arr[i]!=i){
                return false;
            }
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        while(true){
            n++;
            if(isBalanced(n)){
                return n;
                break;
            }
        }
        return{};
    }
};