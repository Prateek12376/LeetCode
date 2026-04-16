class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        map<int,vector<int>>mpp;
        int n=nums.size();
        
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]].push_back(i);
        }
        vector<int>ans;
        for(auto it : queries){
            int ind = it;
            vector<int>& arr=mpp[nums[ind]];
            if(arr.size()==1){
                ans.push_back(-1);
            }
            else{
                int low=0;
                int high=arr.size()-1;
                int reqI=-1;
                while(low<=high){
                    int mid = low+(high-low)/2;
                    if(arr[mid]==ind){
                        reqI=mid;
                        break;
                    }
                    else if(arr[mid]>ind){
                        high=mid-1;
                    }
                    else{
                        low=mid+1;
                    }

                }
                int cost=INT_MAX;
                // next (circular)
                int next = arr[(reqI + 1) % arr.size()];
                cost = min(cost, (next - ind + n) % n);

                // previous (circular)
                int prev = arr[(reqI - 1 + arr.size()) % arr.size()];
                cost = min(cost, (ind - prev + n) % n);

                ans.push_back(cost);
                
            }
        }
        return ans;
    }
};