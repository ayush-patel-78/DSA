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
    void help(TreeNode* root,vector<int>& ans,int level){
        
        if(level==ans.size()) ans.push_back(root->val);
        
        if(root->right!=NULL){
          
          help(root->right,ans,level+1);   
        }
        if(root->left!=NULL){
            help(root->left,ans,level+1);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans;
        if(root==NULL) return ans;
        int level=0;
        help(root,ans,level);
        return ans;
    }
};