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
    bool check(TreeNode* p, TreeNode* q,bool & ck){
        if(p==NULL && q==NULL) return true;
        else if(p==NULL || q==NULL) return false;
        if(p->val != q->val){
            ck=false;
            return false;
        }
        bool left = check(p->left,q->left,ck);
        bool right = check(p->right,q->right,ck);
        if(left==false || right==false){
            return false;
        }
        return true;
        
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ck=true;
        return check(p,q,ck);
    }
};