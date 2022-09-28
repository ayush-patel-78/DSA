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
    int sum(TreeNode* root,int & ans){
        if(root==NULL){
            return INT_MIN;
        }
        int left = 0;
        if(root->left) left = sum(root->left,ans);
        int right=0;
        if(root->right) right= sum(root->right,ans);
        int curr_sum = root->val;
        if(left > 0 && right > 0) curr_sum += left + right;
        else if(left > 0) curr_sum += left;
        else if(right > 0) curr_sum += right;
        
        if(curr_sum > ans) ans = curr_sum;
        
        if(left > right && left>0) return root->val + left;
        else if(right > left && right > 0) return root->val + right;
        return root->val;
       
    }
    int maxPathSum(TreeNode* root) {
       int ans = INT_MIN;
        sum(root,ans);
        return ans;
    }
};