class Solution {
public:
    struct trieNode{
        int ind;
        trieNode* children [26];
        ~trieNode(){
            for(int i=0;i<26;i++){ 
                delete children[i];
            }
        }
    };

    trieNode* getNode(int i){
        trieNode* temp= new trieNode();
        temp->ind=i;
        for(int i=0;i<26;i++){
            temp->children[i]=nullptr;
        }
        return temp;
    }
    void insertTrie(trieNode* root , int WInd , vector<string>& wordsContainer){
        string word = wordsContainer[WInd];
        int n =word.size();
        for(int j=n-1;j>=0;j--){
            char c = word[j];
            int c_ind =  c -'a';
            if(root->children[c_ind]==nullptr){
                root->children[c_ind]=getNode(WInd);
            }
            root = root->children[c_ind];
            if(wordsContainer[root->ind].size()>n){
                root->ind=WInd;
            }
        }
    }

    int searchTrie(trieNode* root , string& word){
        int res_ind=root->ind;
        int n=word.size();
        for(int i=n-1;i>=0;i--){
            int ch_ind = word[i]-'a';

            root= root->children[ch_ind];
            if(root==NULL){
                return res_ind;
            }
            res_ind=root->ind;
        }
        return res_ind;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int m=wordsContainer.size();
        int n=wordsQuery.size();

        vector<int>result(n);

        trieNode* root= getNode(0);
        for(int i=0;i<m;i++){
            int  rootI=root->ind;
            if(wordsContainer[rootI].size()>wordsContainer[i].size()){
                root->ind=i;
            }
            insertTrie(root,i,wordsContainer);
        }

        for(int i=0;i<n;i++){
            result[i]=searchTrie(root,wordsQuery[i]);
        }
        delete root;
        return result;
    }
};