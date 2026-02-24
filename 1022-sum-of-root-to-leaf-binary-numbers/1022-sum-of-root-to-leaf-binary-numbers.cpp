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
    int find_sum(TreeNode* root,int sum){
        if(root==NULL){
            return 0;
        }
        sum=sum*2 + root->val;
        if(root->left==NULL && root->right==NULL){
            return sum;
        }
        int left= find_sum(root->left,sum);
        int right= find_sum(root->right,sum);
        return left+right;
    }
    int sumRootToLeaf(TreeNode* root) {
       return find_sum(root,0);
    }
};