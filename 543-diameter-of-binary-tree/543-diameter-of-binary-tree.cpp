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
    int solve(TreeNode* root,int & answer){
        if(root == NULL) return 0;
        int left_cnt = solve(root->left,answer);
        int right_cnt = solve(root->right,answer);
        if(left_cnt + right_cnt > answer){
            answer = left_cnt + right_cnt;
        }
        return max(left_cnt,right_cnt)+1;
        
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int answer =0;
         solve(root,answer);
        return answer;
    }
};