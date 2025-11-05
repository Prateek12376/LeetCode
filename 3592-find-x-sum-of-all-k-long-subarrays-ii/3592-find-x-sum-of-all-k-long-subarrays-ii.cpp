class Solution {
public:
    void removeFromSet(const pair<int,int>& p,set<pair<int,int>>& sec, set<pair<int,int>>& main, long long& sum, int x){
        if(main.find(p)!=main.end()){
            sum-=1LL*p.first*p.second;
            main.erase(p);
            if(!sec.empty()){
                auto largest= *sec.rbegin();
                sec.erase(largest);
                main.insert(largest);
                sum+=1LL*largest.first*largest.second;
            }
        }
        else{
            sec.erase(p);
        }
    }
    void insertInSet(const pair<int,int>& p,set<pair<int,int>>& sec, set<pair<int,int>>& main, long long& sum, int x){
        if(main.size()<x || p> *main.begin()){
            sum+=1LL*p.first*p.second;
            main.insert(p);
            if(main.size()>x){
                auto smallest= *main.begin();
                sum-=1LL* smallest.first*smallest.second;
                main.erase(smallest);
                sec.insert(smallest);
            }
        }
        else{
            sec.insert(p);
        }
    }
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        vector<long long>res;
        long long sum=0;
        set<pair<int,int>>main;  // top elm
        set<pair<int,int>>sec;    // rem elm
        unordered_map<int,int>freq;

        int i=0;
        int j=0;
        while(j<nums.size()){
            if(freq[nums[j]]>0){
                removeFromSet({freq[nums[j]],nums[j]},sec,main,sum,x);
            }
            freq[nums[j]]++;
            insertInSet({freq[nums[j]],nums[j]},sec,main,sum,x);

            if(j-i+1==k){
                res.push_back(sum);
                removeFromSet({freq[nums[i]],nums[i]},sec,main,sum,x);
                freq[nums[i]]--;
                if(freq[nums[i]]==0){
                    freq.erase(nums[i]);
                }
                else{
                    insertInSet({freq[nums[i]],nums[i]},sec,main,sum,x);
                }
                i++;
            }
            j++;
        }
        return res;
    }
};