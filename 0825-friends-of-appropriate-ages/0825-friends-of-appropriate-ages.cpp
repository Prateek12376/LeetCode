class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int count=0;
        int n=ages.size();
        sort(ages.begin(),ages.end());
        for(int i=0;i<ages.size();i++){
            if(ages[i]<=14){
                continue;
            }
            int low = 0;
            int high=n-1;
            int left=0;
            while(low<=high){
                int mid= low+(high-low)/2;
                if(ages[mid]>0.5*ages[i]+7){
                    left=mid;
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            low=0;
            high=n-1;
            int right=0;
            while(low<=high){
                int mid = low+(high-low)/2;
                if(ages[mid]<=ages[i]){
                    right=mid;
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            
            if(right>left){
                count+=(right-left);
            }
        }
        return count;
    }
};