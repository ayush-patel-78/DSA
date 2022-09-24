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
    void dfs(TreeNode* root,int curr_sum,int targetSum,vector<int>& vec,vector<vector<int>> & ans){
        if(root == NULL) return;
        curr_sum += root->val;
        vec.push_back(root->val);
        if(curr_sum == targetSum && root->left==NULL && root->right==NULL){
            ans.push_back(vec);
        }
        dfs(root->left,curr_sum,targetSum,vec,ans);
        dfs(root->right,curr_sum,targetSum,vec,ans);
        vec.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
         vector<vector<int>> ans ;
         int curr_sum = 0;
         vector<int> vec;
         dfs(root,curr_sum,targetSum,vec,ans);
        return ans;
    }
};