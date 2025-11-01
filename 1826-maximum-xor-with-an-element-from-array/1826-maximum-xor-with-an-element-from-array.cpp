struct TrieNode{
    TrieNode* links[2];

    bool containKey(int bit){
        return (links[bit]!=NULL);
    }

    void put(int bit, TrieNode* node){
        links[bit]=node;
    }
    TrieNode* get(int bit){
        return links[bit];
    }
};

class Trie{
private:
    TrieNode* root;
public:
    Trie(){
        root=new TrieNode();
    }

    void insert(int num){
        TrieNode* node=root;
        for(int i=31;i>=0;i--){
            int bit= (num>>i)&1;
            if(!node->containKey(bit)){
                node->put(bit, new TrieNode());
            }
            node=node->get(bit);
        }
    }
    int getMax(int num){
        int numMax=0;
        TrieNode* node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)& 1;
            if(node->containKey(1-bit)){
                numMax= numMax | (1<<i);
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }
        }
        return numMax;
    }
};

struct query{
    int limit;
    int num;
    int index;
    query(int l, int n, int i){
        limit=l;
        num=n;
        index=i;
    }

};
static bool compare(query a, query b){
    return a.limit<b.limit;
}

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;
        sort(nums.begin(),nums.end());
        int q=queries.size();
        vector<query>qSorted;

        for(int i=0;i<q;i++){
            qSorted.push_back({queries[i][1],queries[i][0],i});
        }
        sort(qSorted.begin(),qSorted.end(),compare);

        vector<int>ans(q,0);
        int index=0;
        for(int i=0;i<q;i++){
            int qIndex= qSorted[i].index;
            int num= qSorted[i].num;
            int limit= qSorted[i].limit;

            while(index<nums.size() && nums[index]<=limit){
                trie.insert(nums[index]);
                index++;
            }
            if(index==0){
                ans[qIndex]=-1;
            }
            else{
                ans[qIndex]=trie.getMax(num);
            }
        }
        return ans;
    }
};