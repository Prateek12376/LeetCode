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
    void find_node(TreeNode* root,int target_,TreeNode*& target){
        if(root==NULL){
            return ;
        }
        if(root->val==target_){
            target=root;
            return;
        }
        find_node(root->left,target_,target);
        find_node(root->right,target_,target);
    }
    void link_parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent_track ){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current= q.front();
            q.pop();
            if(current->left!=NULL){
                parent_track[current->left]=current;
                q.push(current->left);
            }
            if(current->right!=NULL){
                parent_track[current->right]=current;
                q.push(current->right);
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* target=NULL;
        find_node(root,start,target);
        
        unordered_map<TreeNode*,TreeNode*>parent_track;
        link_parent(root,parent_track);
        
        
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        int count=0;
        while(!q.empty()){
            int f=0; 
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* current= q.front();
                q.pop();
                // left child
                if(current->left!=NULL && !visited[current->left]){
                q.push(current->left);
                visited[current->left]=true;
                f=1;
                }
                // for right
                if(current->right!=NULL && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right]=true;
                    f=1;
                }
                // for up
                if(parent_track.find(current)!=parent_track.end() && !visited[parent_track[current]]){
                    q.push(parent_track[current]);
                    visited[parent_track[current]]=true;
                    f=1;
                }
            }
            // If infection spread this second, increment time
            if(f==1){
                count++;
            }
        }
        return count;
        
    }
};