class Solution {
public:
    int candy(vector<int>& ratings) {
        int n= ratings.size();
        int i=1;
        int sum=1;
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                sum+=1;
                i++;
                continue;
            }
            // inc slope
            int peak=1;
            while(i<n && ratings[i]>ratings[i-1]){
                peak++;
                sum+=peak;
                i++;
            }
            // dec slopw
            int down =1;
            while(i<n && ratings[i]<ratings[i-1]){
                sum+=down;
                down++;
                i++;
            }
            if(down>1 && down>peak){
                sum+= (down-peak);
            }
        }
    return sum;
    }
};