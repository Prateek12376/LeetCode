class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int index=0;
        for(int i=0;i<n;i++){
            char ch= chars[i];
            int count=0;
            while(i<n && chars[i]==ch){
                count++;
                i++;
            }
            if(count==1){
                chars[index]=ch;
                index++;
            }
            else{
                chars[index]=ch;
                index++;
                string numbers = to_string(count);
                for(char dig :numbers){
                    chars[index]=dig;
                    index++;
                }
            }
            i--;
        }
        chars.resize(index);
        return index;
    }
};