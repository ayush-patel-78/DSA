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
    TreeNode* make_linked_list(TreeNode* root){
        if(root==NULL) return NULL;
        TreeNode* start = root;
        TreeNode* left_part = make_linked_list(root->left);
        TreeNode* right_part = make_linked_list(root->right);
        if(left_part !=NULL){
            root->right = left_part;
            while(root->right !=NULL){
                root = root->right;
            }
            if(right_part != NULL){
                root->right = right_part;
            }
        }
        else if(right_part != NULL){
            root->right = right_part;
        }
        start->left = NULL;
        return start;
          
    }
    void flatten(TreeNode* root) {
        make_linked_list(root);
    }
};