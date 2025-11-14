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
    void find_depth(TreeNode* root, int& depth, int count){
        if(root==NULL){
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            depth = min(depth, count + 1);
            return;
        }
        find_depth(root->left,depth,count+1);
        find_depth(root->right,depth,count+1);
    }
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int depth=INT_MAX;
        find_depth(root,depth,0);
        return depth;
    }
};