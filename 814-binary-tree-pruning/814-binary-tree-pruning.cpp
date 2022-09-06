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
    bool solve(TreeNode* root){
        if(root==NULL) return false;
        bool l = solve(root->left);
        bool r = solve(root->right);
        if(l==false){
            root->left = NULL;
        }
        if(r==false){
            root->right = NULL;
        }
        if(l || r || root->val==1){
            return true;
        }
        else{
            // delete (root);
            return false;
        }
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool check =  solve(root);
        if(check) return root;
        return NULL;
    }
};