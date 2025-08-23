class Solution {
public:
    void Left_Right_AroundCenter(string& s, int left,int right, int& begin, int& end){
        int n=s.size();
        while(left>=0 && right<n && s[left]==s[right]){
            if(right-left+1>end-begin+1){
                begin=left;
                end=right;
            }
            left--;
            right++;
        }
    }
    string longestPalindrome(string s) {
        int n=s.size();
        if(n<=1){
            return s;
        }
        int begin=0;
        int end=0;
        for(int i=0;i<n;i++){
            Left_Right_AroundCenter(s,i,i,begin,end); // for odd=one center
            Left_Right_AroundCenter(s,i,i+1,begin,end); // for even=two center
        }
        return s.substr(begin,end-begin+1);
        
    }
};