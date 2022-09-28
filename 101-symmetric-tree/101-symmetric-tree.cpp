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
    void postorder(TreeNode* root,vector<int>& postorder_right){
        if(root==NULL){
            postorder_right.push_back(0);
            return;
        } 
          
        postorder_right.push_back(root->val);
        postorder(root->right,postorder_right);
        postorder(root->left,postorder_right);
     
    }
    void preorder(TreeNode* root,vector<int>& preorder_left){
       if(root==NULL){
            preorder_left.push_back(0);
            return;
        } 
        preorder_left.push_back(root->val);
        preorder(root->left,preorder_left);
        preorder(root->right,preorder_left);
    }
    bool isSymmetric(TreeNode* root) {
        vector<int> preorder_left;
        vector<int> postorder_right;
        preorder(root->left,preorder_left);
        postorder(root->right,postorder_right);
        if(preorder_left.size() != postorder_right.size()) return false;
        for(int i=0;i<postorder_right.size();i++){
            if(preorder_left[i] != postorder_right[i]) return false;
        }
        return true;
        
    }
};