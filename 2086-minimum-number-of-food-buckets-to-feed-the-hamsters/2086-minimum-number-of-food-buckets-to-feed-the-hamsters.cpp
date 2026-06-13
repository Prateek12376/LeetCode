class Solution {
public:
    int minimumBuckets(string hamsters) {
        int n=hamsters.size();
        if(n==1){
            if(hamsters[0]=='H'){
                return -1;
            }
            else{
                return 0;
            }
        }
        int count=0;
        int i=0;

        while(i<n){
            while(i<n && hamsters[i]!='H'){
                i++;
            }
            if(i==n){
                break;
            }
            if((i+1<n && hamsters[i+1]=='c')||( i>0 &&  hamsters[i-1]=='c')){
                i++;
                continue;
            }
            else if( i<n-1 && hamsters[i]=='H' && hamsters[i+1]=='.'){
                hamsters[i+1]='c';
                count++;
            }
            else if( i>0 && hamsters[i]=='H' &&  hamsters[i-1]=='.'){
                hamsters[i-1]='c';
                count++;
            }
            else if(hamsters[i]=='H'){
                return -1;
            }
            
            i++;
        }
        return count;

    }
};