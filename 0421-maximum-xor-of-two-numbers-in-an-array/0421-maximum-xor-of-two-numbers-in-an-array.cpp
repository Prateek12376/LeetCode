class TrieNode{
public:
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
        TrieNode* node=root;
        int maxNum=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->containKey(1-bit)){
                maxNum= maxNum | (1<<i);
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }
        }
        return maxNum;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto it: nums){
            trie.insert(it);
        }
        int maxi=0;
        for(auto it: nums){
            int xorN=trie.getMax(it);
            maxi=max(maxi,xorN);
        }
        return maxi;
    }
};