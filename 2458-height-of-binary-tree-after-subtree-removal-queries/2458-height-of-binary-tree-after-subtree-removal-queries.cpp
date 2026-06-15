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
    unordered_map<int,int>depth;
    unordered_map<int,int>height;
    unordered_map<int,pair<int,int>>lmax;

    int find_d_h(TreeNode* root, int level){
        if(root==NULL){
            return 0;
        }
        depth[root->val]=level;
        int left = find_d_h(root->left,level+1);
        int right= find_d_h(root->right,level+1);
        height[root->val]=1+max(left,right);

        int h= height[root->val];

        if(h>lmax[level].first){
            lmax[level].second= lmax[level].first;
            lmax[level].first = h;
        }
        else if(h>lmax[level].second){
            lmax[level].second=h;
        }

        return height[root->val];


    }
    
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {

        int  temp = find_d_h(root,0);
        vector<int>ans;

        for(auto it : queries){
            int h= height[it];
            int l= depth[it];
            if(h==lmax[l].first){
                int bH = lmax[l].second;
                ans.push_back(bH+l-1);
            }
            else{
                int bH= lmax[l].first;
                ans.push_back(bH+l-1);
            }
        }
        return ans;

    }
};