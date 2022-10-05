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
    TreeNode* addNodes(TreeNode* root,int val){
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        
        TreeNode* newNodeLeft = new TreeNode(val);
        TreeNode* newNoderight = new TreeNode(val);
        newNodeLeft->left = root->left;
        newNoderight->right = root->right;
        root->left = newNodeLeft;
        root->right = newNoderight;
        return root;
    }
    void dfs(TreeNode* root,int val,int depth,int curr_depth){
        if(root==NULL) return ;
        if(curr_depth + 1 == depth){
            addNodes(root,val);
        }
        dfs(root->left,val,depth,curr_depth+1);
        dfs(root->right,val,depth,curr_depth+1);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        int curr_depth = 1;
        dfs(root,val,depth,curr_depth);
        return root;
    }
};