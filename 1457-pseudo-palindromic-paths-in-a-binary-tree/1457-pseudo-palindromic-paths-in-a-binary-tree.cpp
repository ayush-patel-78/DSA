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
      vector<int> arr;
      void solve(TreeNode * root,int & count){
        if(root==NULL) return ;
        arr[root->val]++;
         solve(root->left,count);
          solve(root->right,count);
         int check = 0;
        if(root->left == NULL && root->right == NULL){
          for(int i=1;i<10;i++){
              if(arr[i]%2==1){
                  check++;
              }
          }
          if(check < 2) count++;
        }
       arr[root->val]--;
          
          return ;
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
         for(int i=0;i<10;i++){
             arr.push_back(0);
         }
         
         int count = 0;
         solve(root,count);
         return count;
    }
};