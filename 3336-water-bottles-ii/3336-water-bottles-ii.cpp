class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drinkB=numBottles;
        int empty= numBottles;
        int fullB=0;
        while(empty>=numExchange){
            fullB++;
            empty=empty-numExchange;
            numExchange++;
            if(empty<numExchange){
                empty+=fullB;
                drinkB+=fullB;
                fullB=0;
            }
        }
        return drinkB;
    }
};