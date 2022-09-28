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
    int calculate_sum(TreeNode* root){
        int ans = 0;
        if(root->left && root->left->left){
            ans += root->left->left->val;
        }
        if(root->left && root->left->right){
            ans += root->left->right->val;
        }
        if(root->right && root->right->left){
            ans += root->right->left->val;
        }
        if(root->right && root->right->right){
            ans += root->right->right->val;
        }
        return ans;
    }
    int dfs(TreeNode* root){
        if(root==NULL) return 0;
        int sum = 0;
        if(root->val %2==0){
           sum += calculate_sum(root);
        }
        if(root->left){
            sum += dfs(root->left);
        }
        if(root->right){
            sum += dfs(root->right);
        }
        return sum;
        
    }
    int sumEvenGrandparent(TreeNode* root) {
          return dfs(root);
    }
};