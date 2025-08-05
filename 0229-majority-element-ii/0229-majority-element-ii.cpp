class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // map<int,int>map1;
        // vector<int>ls;
        // int mini = (nums.size()/3) +1;
        // for(int i=0;i<nums.size();i++){
        //     map1[nums[i]]+=1;
        //     if(map1[nums[i]]>=mini){
        //         ls.push_back(nums[i]);
        //     }
        //     if(ls.size()==2){
        //         break;
        //     }
        // }
        // sort(ls.begin(),ls.end());
        // return ls;
        int n=nums.size();
        int count1=0;
        int elm1=INT_MIN;
        int count2=0;
        int elm2=INT_MIN;
        for(int i=0;i<n;i++){
            if(count1==0 && nums[i]!=elm2){
                count1++;
                elm1=nums[i];
            }
            else if(count2==0 && nums[i]!=elm1){
                count2++;
                elm2=nums[i];
            }
            else if(nums[i]==elm1){
                count1++;
            }
            else if(nums[i]==elm2){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        vector<int>ls;
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<n;i++){
            if(elm1==nums[i]){
                cnt1++;
            }
            if(elm2==nums[i]){
                cnt2++;
            }
        }
        int mini= (n/3) +1;
        if(cnt1>=mini){
            ls.push_back(elm1);
        }
        if(cnt2>=mini){
            ls.push_back(elm2);
        }
        sort(ls.begin(),ls.end());
        return ls;
    }
};