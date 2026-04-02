class Solution {
public:
    int find_maxC(int i, int j, vector<vector<int>>& coins, vector<vector<vector<int>>>& dpp, int count){

        if(i==0 && j==0){
            if(coins[i][j]<0 && count>0){
                return 0;
            }
            return coins[i][j];
        }

        if(dpp[i][j][count]!=INT_MIN){
            return dpp[i][j][count];
        }
        int maxi=INT_MIN;
        int mU=INT_MIN;;
        int mL=INT_MIN;
        if(coins[i][j]>=0){
            if(i>0){
                mU= coins[i][j]+find_maxC(i-1,j,coins,dpp,count);
            }
            if(j>0){
                mL= coins[i][j]+find_maxC(i,j-1,coins,dpp,count);
            }
            
        }
        else{
            // take 
            if(i>0){
                mU= coins[i][j]+find_maxC(i-1,j,coins,dpp,count);
                }
            if(j>0){
                mL= coins[i][j]+find_maxC(i,j-1,coins,dpp,count);
            }
            // skip
            if(count>0){
                if(i>0){
                    mU=max(mU,0+find_maxC(i-1,j,coins,dpp,count-1));
                }
                if(j>0){
                    mL= max(mL,0+find_maxC(i,j-1,coins,dpp,count-1));
                }
            }
        }
        return dpp[i][j][count]= max(mU,mL);
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int n=coins.size();
        int m=coins[0].size();
        vector<vector<vector<int>>>dpp(n,vector<vector<int>>(m,vector<int>(3,INT_MIN)));
        return find_maxC(n-1,m-1,coins,dpp,2);
    }
};