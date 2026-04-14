class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        vector<int>neg;
        vector<int>pos;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<0){
                neg.push_back(arr[i]);
            }
            else{
                pos.push_back(arr[i]);
            }
        }
        if(neg.size()%2!=0 || pos.size()%2!=0){
            return false;
        }
        sort(neg.rbegin(),neg.rend());
        sort(pos.begin(),pos.end());
        unordered_map<int,int>mpp1,mpp2;
        for(int i=0;i<neg.size();i++){
            mpp1[neg[i]]++;
        }
        for(int i=0;i<pos.size();i++){
            mpp2[pos[i]]++;
        }
        for(int i=0;i<pos.size();i++){
            if(mpp2[pos[i]]==0){
                continue;
            }
            if(mpp2[2*pos[i]]<=0){
                return false;
            }
            mpp2[2*pos[i]]--;
            mpp2[pos[i]]--;
        }
        for(int i=0;i<neg.size();i++){
            if(mpp1[neg[i]]==0){
                continue;
            }
            if(mpp1[2*neg[i]]<=0){
                return false;
            }
            mpp1[2*neg[i]]--;
            mpp1[neg[i]]--;
        }

        return true;
    }
};