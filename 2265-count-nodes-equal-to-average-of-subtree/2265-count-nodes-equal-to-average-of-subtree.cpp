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
    int ans ;
    pair<int,int> dfs(TreeNode* root){
        if(root==NULL){
             return {0,0};
        }
        pair<int,int> left;
        pair<int,int> right;
        left = dfs(root->left);
        right = dfs(root->right);
       
        int sum = left.first + right.first + root->val;
        int nodes = left.second + right.second + 1;
        int avg = sum/nodes;
        if(avg == root->val) ans++;
        return {sum,nodes};
        
    }
    int averageOfSubtree(TreeNode* root) {
        ans =0;
        dfs(root);
        return ans;
        
    }
};