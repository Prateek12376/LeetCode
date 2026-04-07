class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if(startValue==target){
            return 0;
        }
        else if(startValue>target){
            return startValue-target;
        }
        else{
            long long count=0;
            while(target>startValue){
                if(target%2==0){
                    target/=2;
                }
                else{
                    target+=1;
                }
                count++;
            }
            return (int)count+(startValue-target);
        }

    }
};