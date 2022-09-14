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
    int solve(TreeNode* root,int & height,int level,int& sum){
        if(root==NULL) return 0;
        if(level == height){
            sum += root->val;
        }
        if(level > height){
            sum = root->val;
            height = level;
        }
        solve(root->left,height,level+1,sum);
        solve(root->right,height,level+1,sum);
        return sum ;
        
    }
    int deepestLeavesSum(TreeNode* root) {
        int height = 0;
        int level  = 0;
        int sum = 0;
        solve(root,height,level,sum);
        return sum;
    }
};