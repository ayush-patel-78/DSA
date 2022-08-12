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
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return NULL;
        if(root == p || root == q) return root;
        TreeNode* left_subtree = solve(root->left,p,q);
        TreeNode* right_subtree = solve(root->right,p,q);
        if(left_subtree != NULL && right_subtree != NULL) return root;
        else if(left_subtree != NULL) return left_subtree;
        else if(right_subtree != NULL) return right_subtree;
        else return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
    }
};