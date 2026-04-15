class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int cnt1=0;
        int cnt2=0;
        int n=words.size();
        for(int i=0;i<n;i++){
            //l->R
            if(words[(i+startIndex)%n]==target){
                break;
            }
            cnt1++;
        }
        for(int i=0;i<n;i++){
            if(words[(startIndex-i+n)%n]==target){
                break;
            }
            cnt2++;
        }
        if(cnt1==n && cnt2==n){
            return -1;
        }
        return min(cnt1,cnt2);
        
    }
};