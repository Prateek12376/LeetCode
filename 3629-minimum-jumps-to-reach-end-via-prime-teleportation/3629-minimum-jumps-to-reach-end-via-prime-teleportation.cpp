class Solution {
public:
    static vector<bool> isPrime;
    static bool sieveDone;
    static void buildSieve() {
        if (sieveDone) return;
        int MAX = 1000001;
        isPrime.assign(MAX, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (long long i = 2; i * i < MAX; i++) {
            if (isPrime[i]) {
                for (long long j = i * i; j < MAX; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        sieveDone = true;
    }
    int minJumps(vector<int>& nums) {
        buildSieve();
        int n=nums.size();
        unordered_map<int, vector<int>> mp;
        for(int i=0;i<n;i++){
            int temp=nums[i];
            for(int p=2;p*p<=temp;p++){
                if(temp%p==0){
                    mp[p].push_back(i);
                    while(temp%p==0){
                        temp=temp/p;
                    }
                }
            }
            if(temp>1){
                mp[temp].push_back(i);
            }

        }
        vector<int>vis(n,0);
        unordered_set<int> usedP;
        vis[0]=1;
        queue<int>q; //{steps,index}
        q.push(0);
        int step=0;
        while(!q.empty()){
           int size=q.size();
           while(size>0){
            int index=q.front();
            q.pop();
            if(index==n-1){
                return step;
            }
            if(index>0 && vis[index-1]==0){
                q.push(index-1);
                vis[index-1]=1;
            }
            if(index<n-1 && vis[index+1]==0){
                q.push(index+1);
                vis[index+1]=1;
            }
            if(isPrime[nums[index]]==true && !usedP.count(nums[index])){
                int p=nums[index];
                usedP.insert(nums[index]);
                for(auto next : mp[p]){

                    if(vis[next]==0){

                        vis[next]=1;
                        q.push(next);
                    }
                }
            }
            size--;
           }
           step++;
        }
        return -1;
    }
};

vector<bool> Solution::isPrime;
bool Solution::sieveDone = false;