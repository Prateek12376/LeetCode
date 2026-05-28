class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int one=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                one++;
            }
        }
        vector<int>arr;
        int pos=0;
        int neg=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                while(i<s.size() && s[i]=='1'){
                    pos++;
                    i++;
                }
                arr.push_back(pos);
                pos=0;
                i--;
            }
            else{
                while(i<s.size() && s[i]=='0'){
                    neg--;
                    i++;
                }
                arr.push_back(neg);
                neg=0;
                i--;
            }
        }
        int maxi=0;
        for(int i=1;i<arr.size()-1;i++){
            if(arr[i]>0){
                if(arr[i-1]<0 && arr[i+1]<0){
                    int total=abs(arr[i-1])+abs(arr[i+1]);
                    if(maxi<total){
                        maxi=total;
                    }
                }
            }
        }
        int ans= one+maxi;
        return ans;
    }
};