class Solution {
public:
    bool static compare (string a , string b){
        return a+b > b+a;
    }
    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        vector<string>arr(n);
        for(int i=0;i<n;i++){
            arr[i]=to_string(nums[i]);
        }
        sort(arr.begin(),arr.end(),compare);
        if(arr[0]=="0"){
            return "0";
        }
        string ans="";
        for(auto it : arr){
            ans+=it;
        }
        return ans ;
    }
};