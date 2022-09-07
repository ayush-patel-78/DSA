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
    string preorderright(TreeNode* root){
        string str ="";
        if(root==NULL) return str;
        str+="(";
        str+= to_string(root->val);
        
        if(root->left || root->right){
             str+="(";
            str+=preorderleft(root->left);
            str+=")";
            str+= preorderright(root->right);
        }
        str+=")";
        return str;
        
    }
    string preorderleft(TreeNode* root){
        string str ="";
        if(root==NULL) return str;
        str += to_string(root->val);
        if(root->left || root->right){
            str+="(";
            str+=preorderleft(root->left);
            str+=")";
            str+= preorderright(root->right);
        }
        return str;
    }
    string tree2str(TreeNode* root) {
        
        string s = "";
        if(root==NULL) return s;
        s+=to_string(root->val);
        if(root->left || root->right){
            s+="(";
            s+=preorderleft(root->left);
            s+=")";
            s+=preorderright(root->right);
        }
        
        return s;
    }
};