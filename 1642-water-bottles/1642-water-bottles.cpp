class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int count=numBottles;
        int empty=numBottles;
        while(empty>=numExchange){
            int newB= empty/numExchange;
            count+=newB;
            empty = newB+(empty % numExchange);
            
        }
        
        return count;
    }
};