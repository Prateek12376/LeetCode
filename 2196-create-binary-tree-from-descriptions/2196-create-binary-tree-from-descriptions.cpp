/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void buildTree(TreeNode* root , unordered_map<int,vector<pair<int,int>>>& mp){
        vector<pair<int,int>>& ans = mp[root->val];
        if(ans.size()==0){
            root->left=NULL;
            root->right=NULL;
            return;
        }
        bool l=true;
        bool r=true;
        for(auto it : ans){
            if (it.first==0){
                TreeNode* rightN = new TreeNode(it.second);
                root->right=rightN;
                r=false;
                buildTree(root->right,mp);
            }
            if(it.first==1){
                TreeNode* leftN = new TreeNode(it.second);
                root->left=leftN;
                l=false;
                buildTree(root->left,mp);

            }
        }
        if(l==true){
                root->left=NULL;
            }
        if(r==true){
                root->right=NULL;
        }
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int>st;
        for(int i=0;i<descriptions.size();i++){
            st.insert(descriptions[i][0]);
        }
        unordered_map<int,vector<pair<int,int>>>mp;
        for(int i=0;i<descriptions.size();i++){
            if(st.count(descriptions[i][1])){
                st.erase(descriptions[i][1]);
            }
            mp[descriptions[i][0]].push_back({descriptions[i][2],descriptions[i][1]});
        }
        int base;

        for(auto it : st){
            base=it;
        }
        TreeNode* root=  new TreeNode (base);
        TreeNode* temp = root;

        buildTree(temp,mp);

        return root;
    }
};