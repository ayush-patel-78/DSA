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
    int check (TreeNode* root,bool& bal){
        if(root==NULL) return 0;
        int left = check(root->left,bal);
        int right = check(root->right,bal);
        if(abs(right-left)>1) bal = false;
        if(left > right) return left+1;
        return right+1;
    }
    bool isBalanced(TreeNode* root) {
        bool bal=true;
        check(root,bal);
        return bal;
    }
};