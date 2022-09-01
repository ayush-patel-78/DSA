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
    int solve(TreeNode* root,int x){
        if(root==NULL) return 0;
        if(root->val >=x){
            return 1 + solve(root->left,root->val)+solve(root->right,root->val);
        }
        return solve(root->left,x)+solve(root->right,x);
    }
    int goodNodes(TreeNode* root) {
        int x = root->val;
        return solve(root,x);
    }
};