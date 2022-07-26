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
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q,bool check){
        if(root ==NULL) return NULL;
        if(root==p || root==q){
            return root;
        }
        TreeNode* left = LCA(root->left,p,q,check);
        TreeNode* right = LCA(root->right,p,q,check);
        if(left!=NULL && right!=NULL)      
        {
          return root;
        }
        else if(left!=NULL) return left;
        else if(right!=NULL) return right;
        else return NULL;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool check = false;
        return LCA(root,p,q,check);
    }
};