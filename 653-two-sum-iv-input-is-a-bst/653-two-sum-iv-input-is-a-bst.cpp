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
    void inorder(TreeNode* root,vector<int>& in){
        if(root == NULL)return;
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
        
    }
    bool search(vector<int>& in,int k){
        int left = 0;
        int right = in.size()-1;
        for(;left<right;){
            if(in[left]+in[right]==k) return true;
            else if(in[left]+in[right] > k){
                right--;
            }
            else left++;
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> in;
        inorder(root,in);
        return search(in,k);
    }
};