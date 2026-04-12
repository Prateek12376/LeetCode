class Solution {
public:
    long long find_num(int len){
        long long temp=1;
        for(int i=1;i<=len;i++){
            temp=temp*10;
        }
        return temp;
    }
    string nearestPalindromic(string s) {
        long long num= stoll(s);
        int n= s.size();

        vector<long long>arr;

        // edge case
        long long num1= find_num(n-1)-1;
        long long num2=find_num(n)+1;
        arr.push_back(num1);
        arr.push_back(num2);

        long long firstH = stoll(s.substr(0,(n+1)/2));
        for(long long i=-1;i<=1;i++){
            string p= to_string(firstH+i);
            string revP=p;
            reverse(revP.begin(),revP.end());
            if(n%2==1){
                revP= revP.substr(1);
            }
            arr.push_back(stoll(p+revP));
        }
        long long ans=-1;
        for(auto it : arr){
            if(it==num){
                continue;
            }
            if(ans==-1 || abs(num-it) <abs(num-ans) || (abs(num-it)==abs(num-ans) && it<ans)){
                ans=it;
            }
        }
        string pNum = to_string(ans);
        return pNum;

    }
};