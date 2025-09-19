class Spreadsheet {
    vector<vector<int>>sheet;
public:
    Spreadsheet(int rows) {
        sheet= vector<vector<int>>(rows,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        int column= cell[0]-'A';
        int row = stoi(cell.substr(1))-1;
        sheet[row][column]=value;
    }
    
    void resetCell(string cell) {
        int column= cell[0]-'A';
        int row = stoi(cell.substr(1))-1;
        sheet[row][column]=0;
    }
    int convert_int(string& s){
        if(isdigit(s[0])){
            return stoi(s);
        }
        else{
            int column = s[0]-'A';
            int row= stoi(s.substr(1))-1;
            return sheet[row][column];
        }
    }
    int getValue(string formula) {
        string s= formula.substr(1);
        int plus_index= s.find('+');
        string left = s.substr(0,plus_index);
        string right= s.substr(plus_index+1);
        int ans= convert_int(left) + convert_int(right);
        return ans;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */