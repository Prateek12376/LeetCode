class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int>mpp;
        set<long long>st;
        bool f1=false;
        for(int i=0;i<nums.size();i++){
            st.insert(1LL*nums[i]);
            mpp[1LL*nums[i]]++;
        }
        int maxi=1;

        if(mpp.find(1)!=mpp.end()){\
            int cnt=mpp[1];
            if(mpp[1]%2==0){
                cnt--;
            }
            maxi=max(maxi,cnt);
        }
        for(auto it : st){
            if(it==1){
                continue;
            }
            int cnt=0;
            long long num=it;
            while(mpp.find(num)!=mpp.end() && mpp[num]>=2){
                cnt+=2;
                if(mpp.find(num*num)==mpp.end()){
                    break;
                }

                num=num*num;
            }
            if(mpp[num]==1){
                cnt++;
            }
            else{
                cnt--;
            }
            maxi=max(cnt,maxi);
        }

        return maxi;
    }
};