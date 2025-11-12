struct box{
    int Box;
    int unitPerBox;
    box(int i,int j){
        Box=i;
        unitPerBox=j;
    }
};
static bool compare(box a, box b){
    return a.unitPerBox>b.unitPerBox;
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<box>boxes;
        for(int i=0;i<boxTypes.size();i++){
            boxes.push_back({boxTypes[i][0],boxTypes[i][1]});
        }
        sort(boxes.begin(),boxes.end(),compare);
        int tUnits=0;
        for(auto it: boxes){
            if(truckSize==0){
                break;
            }
            int nBox=it.Box;
            int units=it.unitPerBox;
            
            int boxTaken=min(nBox,truckSize);
            tUnits+=boxTaken*units;
            truckSize-=boxTaken;
        }
        return tUnits;
    }
};