class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans = abs(double(30*hour - 11/2.0*minutes));
        if(ans>180){
            ans= 360.0-ans;
        }
        return ans;
    }
};