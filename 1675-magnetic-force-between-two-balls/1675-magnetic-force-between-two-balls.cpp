class Solution {
public:
    int can_we_Place(vector<int>& position, int min_distance, int balls){
        int n = position.size();
        int last_ball=position[0];
        int ball_count=1;
        for(int i=0;i<n;i++){
            if(position[i]-last_ball >= min_distance){
                ball_count++;
                last_ball=position[i];
            }
        }
        if(ball_count>=balls){
            return true;
        }
        else{
            return false;
        }
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int low=1;
        int high= position[n-1] - position[0];
        int ans=0;
        while(low<=high){
            int mid= low+ (high-low)/2;
            int possible_distance = can_we_Place(position,mid,m);
            if(possible_distance==true){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};