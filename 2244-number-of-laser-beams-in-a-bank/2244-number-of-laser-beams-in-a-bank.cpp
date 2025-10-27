class Solution {
public:
    int count_device(string s){
        int countdevice=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                countdevice++;
            }
        }
        return countdevice;
    }
    int numberOfBeams(vector<string>& bank) {
        if(bank.size()==0){
            return 0;
        }
        int Tbeam=0;
        int prev_row_devices=count_device(bank[0]);
        for(int i=1;i<bank.size();i++){
            int curr_row_devices= count_device(bank[i]);
            if(curr_row_devices==0){
                continue;
            }
            Tbeam+=prev_row_devices*curr_row_devices;
            prev_row_devices=curr_row_devices;
        }
        return Tbeam;
    }
};