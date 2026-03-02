class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0){
            return true;
        }
        if(flowerbed.size()==1){
            if(flowerbed[0]!=1 && n==1){
                return true;
            }
            else{
                return false;
            }
        
        }
        int cnt=0;
        if(flowerbed[0]!=1 && flowerbed[1]!=1){
            cnt++;
            flowerbed[0]=1;
        }
        for(int i=1;i<flowerbed.size()-1;i++){
            if(flowerbed[i]!=1){
                if(flowerbed[i-1]!=1 && flowerbed[i+1]!=1){
                    flowerbed[i]=1;
                    cnt++;
                }
            }
        }
        if(flowerbed[flowerbed.size()-2]!=1){
            if(flowerbed[flowerbed.size()-1]!=1){
                cnt++;
            }
        }
        if(cnt>=n){
            return true;
        }
        else{
            return false;
        }
    }
};