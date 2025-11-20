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
    bool find_path(TreeNode*root,int targetSum,int target){
        if(root->left==NULL && root->right==NULL){
            if(target==targetSum){
                return true;
            }
            else{
                return false;
            }
        }
        if(root->left!=NULL){
            if(find_path(root->left,targetSum,target+root->left->val)==true){
                return true;
            }
        }
        if(root->right!=NULL){
            if(find_path(root->right,targetSum,target+root->right->val)==true){
                return true;
            }
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        return find_path(root,targetSum,root->val);
    }
};