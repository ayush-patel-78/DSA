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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,unordered_map<int,int>& mpp,int ins,int ine,int pos,int poe){
        if(ins > ine || pos > poe) return NULL;
        TreeNode* head = new TreeNode(postorder[poe]);
        int head_index = mpp[postorder[poe]];
        int ins_left = ins;
        int ine_left = head_index - 1;
        int ins_right = head_index + 1;
        int ine_right = ine;
        
        int pos_left = pos;
        int poe_left = pos + (ine_left-ins_left);
        int pos_right = poe_left + 1;
        int poe_right = poe-1;
        
        head->left=build(inorder,postorder,mpp,ins_left,ine_left,pos_left,poe_left);
    head->right=build(inorder,postorder,mpp,ins_right,ine_right,pos_right,poe_right);
        return head;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mpp;
        for(int i=0;i<=inorder.size()-1;i++){
            mpp[inorder[i]]=i;
        }
        int ins = 0;
        int ine = inorder.size()-1;
        int pos = 0;
        int poe = postorder.size()-1;
       return  build(inorder,postorder,mpp,ins,ine,pos,poe);
    }
};