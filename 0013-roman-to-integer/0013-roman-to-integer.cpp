class Solution {
public:
    int romanToInt(string s) {
        map<char,int> map1;
        map1.insert({'I',1});
        map1.insert({'V',5});
        map1.insert({'X',10});
        map1.insert({'L',50});
        map1.insert({'C',100});
        map1.insert({'D',500});
        map1.insert({'M',1000});
        
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(i==s.size()){
                ans+=map1[s[i]];
            }
            else if(map1[s[i]]>=map1[s[i+1]]){
                ans+=map1[s[i]];
            }
            else{
                ans-=map1[s[i]];
            }
        }
        return ans;

    }
};