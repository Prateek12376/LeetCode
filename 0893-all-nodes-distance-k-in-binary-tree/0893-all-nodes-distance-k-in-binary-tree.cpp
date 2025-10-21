/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void link_parent(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& parent_tracker){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current= q.front();
            q.pop();
            if(current->left!=NULL){
                parent_tracker[current->left]=current;
                q.push(current->left);
            }
            if(current->right!=NULL){
                parent_tracker[current->right]=current;
                q.push(current->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent_tracker;
        link_parent(root,parent_tracker);
        unordered_map<TreeNode*,bool>visit;
        queue<TreeNode*>q;
        q.push(target);
        visit[target]=true;
        int counter=0;
        while(!q.empty()){
            int size=q.size();
            if(counter==k){
                break;
            }
            counter++;
            for(int i=0;i<size;i++){
                TreeNode* current = q.front();
                q.pop();
                //for left
                if(current->left!=NULL && !visit[current->left]){
                    q.push(current->left);
                    visit[current->left]=true;
                }
                //for right
                if(current->right!=NULL && !visit[current->right]){
                    q.push(current->right);
                    visit[current->right]=true;
                }
                //for up
                if(parent_tracker[current] && !visit[parent_tracker[current]]){
                    q.push(parent_tracker[current]);
                    visit[parent_tracker[current]]=true;
                }
            }
        }
        vector<int>result;
        while(!q.empty()){
            TreeNode* node= q.front();
            q.pop();
            result.push_back(node->val);
        }
        return result;
        
    }
};