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
    TreeNode* solve(vector<int>& nums,int mid,int start,int end){
        // if(mid == prev) return NULL;
        if(mid < start || mid > end) return NULL;
        TreeNode* root = new TreeNode(nums[mid]);
        int mid_left = (start + mid-1)/2;
        root->left = solve(nums,mid_left,start,mid -1);
        int mid_right = (mid+1 + end)/2;
        root->right = solve(nums,mid_right,mid+1,end);
        
        return root;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int mid = (0 + nums.size()-1)/2;
        
        int start = 0;
        int end = nums.size()-1;
        return solve(nums,mid,start,end);
    }
};