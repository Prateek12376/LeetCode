class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0){
            return "0";
        }
        string ans;
        if((numerator<0 && denominator>0) ||(numerator>0 && denominator<0)){
            ans+='-';
        }
        long long num = labs(numerator);
        long long den= labs(denominator);

        ans+=  to_string(num/den);
        long long rem;
        rem= num%den;
        if(rem==0){
            return ans;
        }
        ans+='.';
        unordered_map<long long, int>rem_index;

        while(rem!=0){
            if(rem_index.find(rem)!=rem_index.end()){
                int index= rem_index[rem];
                ans.insert(index,"(");
                ans+=')';
                break;
            }
            rem_index[rem]= ans.size();

            rem*=10;
            ans+= to_string(rem/den);
            rem=rem%den;
        }
        return ans;

    }
};