class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ans;
        for(int i=left;i<=right;i++){
            int num=i;
            bool fg=true;
            while(num>0){
                int n1=num%10;
                if(n1==0||i%n1!=0){
                    fg=false;
                    break;
                }
                num=num/10;
            }
            if(fg==true){
                ans.push_back(i);
            }
        }
        return ans;
    }
};