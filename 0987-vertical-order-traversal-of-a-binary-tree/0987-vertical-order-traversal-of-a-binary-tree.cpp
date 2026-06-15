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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>nodes;
        queue<pair<TreeNode*,pair<int,int>>>q; //node->col,row
        q.push({root,{0,0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            TreeNode* root= it.first;
            int ver =  it.second.first;
            int level = it.second.second;
            nodes[ver][level].insert(root->val);

            if(root->left!=NULL){
                q.push({root->left,{ver-1,level+1}});
            }
            if(root->right!=NULL){
                q.push({root->right,{ver+1,level+1}});
            }
        }
        vector<vector<int>>ans;

        for(auto col : nodes){
            vector<int>vertical;
            for(auto level : col.second){
                for(auto val : level.second){
                    vertical.push_back(val);
                }
            }
            ans.push_back(vertical);
        }
        return ans;
    }
};