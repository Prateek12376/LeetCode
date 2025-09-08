class Solution {
public:
    bool check(int x){
        while(x>0){
            if(x%10==0){
                return false;
            }
            x=x/10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int>arr(2);
        if(n==2){
            arr[0]=1;
            arr[1]=1;
        }
        for(int i=1;i<=n;i++){
            arr[0]=i;
            arr[1]=n-i;
            if(check(i)&& check(n-i)){
                break;
            }
        }
        return arr;
    }
};