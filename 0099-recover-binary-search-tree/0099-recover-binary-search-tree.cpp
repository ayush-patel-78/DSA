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
    void change_inorder(TreeNode* root,vector<int> & vec,int& i){
        if(root==NULL) return;
        change_inorder(root->left,vec,i);
        if(root->val != vec[i]){
            root->val = vec[i];
        }
        i++;
        change_inorder(root->right,vec,i);
    }
    void inorder(TreeNode* root,vector<int> & vec){
        if(root==NULL) return;
        inorder(root->left,vec);
        vec.push_back(root->val);
        inorder(root->right,vec);
    }
    void recoverTree(TreeNode* root) {
        vector<int> vec;
        inorder(root,vec);
        int i=0;
        sort(vec.begin(),vec.end());
        change_inorder(root,vec,i);
    }
};