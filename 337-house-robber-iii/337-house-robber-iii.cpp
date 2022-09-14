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
    // int solve(vector<int> & arr,vector<int> & dp,int index){
    //     if(index >= arr.size()) return 0;
    //     if(dp[index]!=-1) return dp[index];
    //     int ans1 = solve(arr,dp,index+1);
    //     int ans2 = solve(arr,dp,index+2) + arr[index];
    //     return dp[index] = max(ans1,ans2);
    // }
    int solve(TreeNode* root,map<TreeNode*,int>& dp){
       if(root == NULL) return 0;
        if(dp.find(root)!=dp.end()) return dp[root];
        int ans1 =0;
        if(root->left !=NULL){
            ans1+= solve(root->left->left,dp)+solve(root->left->right,dp);
        }
        if(root->right !=NULL){
            ans1+= solve(root->right->left,dp)+solve(root->right->right,dp);
        }
        ans1+= root->val;
        int ans2 = solve(root->left,dp)+ solve(root->right,dp);
        
        return dp[root]=max(ans1,ans2);
    }
    int rob(TreeNode* root) {

        map<TreeNode*,int> dp;
        return solve(root,dp);
        
    }
};