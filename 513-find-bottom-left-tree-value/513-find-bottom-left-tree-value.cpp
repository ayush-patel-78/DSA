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
    int findBottomLeftValue(TreeNode* root) {
         vector<int> ans;
 
   // Your code here
   // level order traversal 
   queue<TreeNode*> q;
   q.push(root);
   q.push(NULL);
   vector<vector<int>> result;
   vector<int> temp;
   bool check = false;
   while(!q.empty()){
       TreeNode* top = q.front();
       q.pop();
       if(top==NULL && check == false){
           check = true;
           result.push_back(temp);
           temp.clear();
           q.push(NULL);
           continue;
       }
      if(top){
          temp.push_back(top->val);
          check = false;
          if(top->left) q.push(top->left);
          if(top->right) q.push(top->right);
      }
   }
  
   for(int i=0;i<result.size();i++){
       ans.push_back(result[i][0]);
   }
   return ans[ans.size()-1];
    }
};