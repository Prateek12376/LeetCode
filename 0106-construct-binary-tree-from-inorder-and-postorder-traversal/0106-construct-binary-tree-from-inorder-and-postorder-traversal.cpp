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
    TreeNode* build(vector<int>& inorder,int iS,int iE, vector<int>& postorder,int pS,int pE,map<int,int>& inMap){
        if(iS>iE || pS>pE){
            return NULL;
        }
        TreeNode* root= new TreeNode(postorder[pE]);
        int inRoot= inMap[root->val];
        int numsLeft= inRoot-iS;
        root->left= build(inorder,iS,inRoot-1,postorder,pS,pS+numsLeft-1,inMap);
        root->right=build(inorder,inRoot+1,iE,postorder,pS+numsLeft,pE-1,inMap);
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> inMap; // Store value -> index mapping for inorder
        for(int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        return build(inorder, 0, inorder.size() - 1,postorder, 0, postorder.size() - 1, inMap);
    }
};