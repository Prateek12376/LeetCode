class Solution {
public:
    void insertInSet(const pair<int,int>& p, long long& sum, set<pair<int,int>>& main,set<pair<int,int>>& sec,int x){
    if(main.size()<x || p> *main.begin()){
        sum+=1LL*p.first* p.second ;
        main.insert(p);
        if(main.size()>x){
        auto smallest= *main.begin();
        sum-= 1LL* smallest.first* smallest.second;
        main.erase(smallest);
        sec.insert(smallest);
        }
    }
    else{
        sec.insert(p);
    }
    }
    void removeFromSet(const pair<int,int>& p, long long& sum, set<pair<int,int>>& main,set<pair<int,int>>& sec,int x){
    if(main.find(p)!=main.end()){
        sum-=1LL*p.first*p.second;
        main.erase(p);
        if(!sec.empty()){
        auto largest = * sec.rbegin();
        sec.erase(largest);
        main.insert(largest);
        sum+=1LL*largest.first*largest.second;
        }
    }
    else{
        sec.erase(p);
    }
    }

    vector<long long> findXSum(vector<int>& nums, int k, int x){
    int n=nums.size();
    long long sum=0;
    vector<long long> res;
    set<pair<int,int>>main;
    set<pair<int,int>>sec;

    unordered_map<int,int>mp;  // {freq->nums}

    int i=0;
    int j=0;
    while(j<n){
        if(mp[nums[j]]>0){
        removeFromSet({mp[nums[j]],nums[j]},sum,main,sec,x);
        }
        mp[nums[j]]++;

        insertInSet({mp[nums[j]],nums[j]},sum,main,sec,x);

        if(j-i+1==k){
        res.push_back(sum);

        removeFromSet({mp[nums[i]],nums[i]},sum,main,sec,x);
        mp[nums[i]]--;
        if(mp[nums[i]]==0){
            mp.erase(nums[i]);
        }
        else{
            insertInSet({mp[nums[i]],nums[i]},sum,main,sec,x);
        }
        i++;
        }
        j++;
    }
    return res;
    }
};