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
    TreeNode* solve(TreeNode* root1, TreeNode* root2){
        TreeNode* root = new TreeNode();
        if(root1) root->val += root1->val;
        if(root2) root->val += root2->val;
        if(root1 && root2){
            if(root1->left || root2->left){
                root->left = solve(root1->left,root2->left);
            }
            if(root1->right || root2->right){
                root->right = solve(root1->right,root2->right);
            }
        }
        else if(root1){
            if(root1->left){
                root->left = solve(root1->left,NULL);
            }
            if(root1->right){
                root->right = solve(root1->right,NULL);
            }
        }
        else if(root2){
            if(root2->left){
                root->left = solve(NULL,root2->left);
            }
            if(root2->right){
                root->right = solve(NULL,root2->right);
            }
        }
        
        return root;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL) return root1;
        return solve(root1,root2);
    }
};