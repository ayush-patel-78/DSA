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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL) return result;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        bool check = false;
        vector<int> temp;
        int count = 0;
        while(!q.empty()){
            TreeNode* top = q.front();
            q.pop();
            
            if(top==NULL && check ==false){
                if(count%2==1) reverse(temp.begin(),temp.end());
                check = true;
                result.push_back(temp);
                temp.clear();
                q.push(NULL);
                count++;
                continue;
            }
            if(top){
                temp.push_back(top->val);
                check = false;
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
        }
        return result;
    }
};