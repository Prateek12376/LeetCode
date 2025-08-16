class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        int longestL=1;
        unordered_set<int>set1;
        for(int i=0;i<n;i++){
            set1.insert(nums[i]);
        }
        for(auto it: set1){
            if(set1.find(it-1)==set1.end()){
                int count =1;
                int x=it;
            
                while(set1.find(x+1)!=set1.end()){
                    x=x+1;
                    count+=1;
                    
                }
                longestL=max(longestL,count);
            }
        }
        return longestL;
    }
};