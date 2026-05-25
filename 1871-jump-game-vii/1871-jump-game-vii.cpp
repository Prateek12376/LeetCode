class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int>q;
        int n=s.size();
        vector<int>vis(n,0);
        vis[0]=1;
        q.push(0);
        int farthest =0;
        while(!q.empty()){
            int ind=q.front();
            q.pop();
            if(ind==n-1){
                return true;
            }
            int start= max(ind+ minJump, farthest+1);
            int end = min(ind+maxJump, n-1);
            for(int i=start ;i<=end;i++){
                if(i<n  && s[i]=='0'&& vis[i]==0){
                    q.push(i);
                    vis[i]=1;
                }
            }
            farthest=end;
        }
        return false;
    }
};