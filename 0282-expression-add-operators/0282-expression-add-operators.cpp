class Solution {
public:
    void find_comb(int index, string& num ,int target, string arr, vector<string>& ans,long long curr_sum,long long prev){
        if(index==num.size()){
            if(curr_sum==target){
                ans.push_back(arr);
            }
            return;
        }
        for(int i=index;i<num.size();i++){
            string part= num.substr(index,i-index+1);
            if(part.size()>1 && part[0]=='0'){
                break;
            }
            long long digit = stoll(part);
            if(index==0){
                find_comb(i+1,num,target,part,ans,digit,digit);
            }
            else{
                find_comb(i+1,num,target,arr + "+" + part,ans,curr_sum+digit,digit);
                find_comb(i+1,num,target,arr + "-" + part,ans,curr_sum-digit,-digit);
                find_comb(i+1,num,target,arr + "*" + part,ans,curr_sum-prev+prev*digit,prev*digit);
            }
        }
        

    }
    vector<string> addOperators(string num, int target) {
        string arr;
        vector<string> ans;
        find_comb(0,num,target,arr,ans,0,0);
        return ans;
    }
};