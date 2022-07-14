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
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder,int ps,int pe,int is,int ie,unordered_map<int,int>& mpp){
        TreeNode* root = new TreeNode(preorder[ps]);
        int root_index = mpp[preorder[ps]];
        if(ps<pe && is<ie){
            
       
        // root->left variables
        if(root_index - is >0){
            int psl=ps+1;
            int pel=ps+(root_index - is);
            int isl=is;
            int iel=root_index - 1;
            
        root->left=buildTreeHelper(preorder,inorder,psl,pel,isl,iel,mpp);
        }
        //root->right variables
        if(ps+(root_index-is)+1<=pe){
            int psr=ps+(root_index-is)+1;
            // int per=psr+(ie-root_index)-1;
            int per = pe;
            int isr=root_index+1;
            int ier=ie;
        
        root->right=buildTreeHelper(preorder,inorder,psr,per,isr,ier,mpp);
        }
    }
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      unordered_map<int,int> mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
         return buildTreeHelper(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1,mpp);
    }
};