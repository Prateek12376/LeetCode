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
    unordered_map<TreeNode*,int>dpp;

    int find_ways(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        if(dpp.find(root)!=dpp.end()){
            return dpp[root];
        }
        int take = root->val;

        if(root->left){
            take+=find_ways(root->left->left);
            take+=find_ways(root->left->right);
        }
        if(root->right){
            take+=find_ways(root->right->left);
            take+=find_ways(root->right->right);
        }

        int n_take = find_ways(root->left) + find_ways(root->right);

        return  dpp[root]=max(take,n_take);
    }
    int rob(TreeNode* root) {
        return find_ways(root);
    }
};