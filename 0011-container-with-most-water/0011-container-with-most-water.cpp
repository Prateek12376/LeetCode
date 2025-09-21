class Solution {
public:
    int maxArea(vector<int>& height) {
        int n= height.size();
        int l=0;
        int r=n-1;
        int maxiH=0;
        long long area=0;
        while(l<=r){
            if(height[l]<=height[r]){
                int maxiH=height[l];
                long long curr_area= 1LL*maxiH*(r-l);
                area= max(area,curr_area);
                l++;
            }
            else{
                int maxiH=height[r];
                long long curr_area=  1LL*maxiH*(r-l);
                area=max(area,curr_area);
                r--;
            }
        }
        return (int)area;
    }
};