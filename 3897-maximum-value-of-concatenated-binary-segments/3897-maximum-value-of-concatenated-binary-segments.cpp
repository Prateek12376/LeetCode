class Solution {
public:
    static bool comp( string& a, string& b){
        return a+b>b+a;
    }
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int mod = 1e9+7;
        vector<string>arr;
        for(int i=0;i<nums1.size();i++){
            string s="";
            s+=string(nums1[i],'1');
            s+=string(nums0[i],'0');
            arr.push_back(s);
        }
        sort(arr.begin(),arr.end(),comp);
        vector<long long>arrP(200001);
        arrP[0]=1;
        for(int i=1;i<200001;i++){
            arrP[i]=(arrP[i-1]*2)%mod;
        }
        int temp=0;
        long long num=0;
        for(int i=arr.size()-1;i>=0;i--){
            string s = arr[i];
            for(int j=s.size()-1;j>=0;j--){
                if(s[j]=='1'){
                    num=(num+arrP[temp])%mod;

                }
                temp++;
            }
        }
        return (int)num;

    }
};