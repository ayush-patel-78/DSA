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
    int ans ;
    vector<int> dfs(TreeNode* root){
        if(root==NULL){
            vector<int> v= {0,0};
            return v;
        }
        vector<vector<int>> left;
        vector<vector<int>> right;
        if(root->left){
            left.push_back(dfs(root->left));
        }
        if(root->right){
            right.push_back(dfs(root->right));
        }
        int sum = root->val;
        int nodes = 1;
        if(left.size()>0){
            sum += left[0][0];
            nodes += left[0][1];
        }
        if(right.size()>0){
            sum += right[0][0];
            nodes += right[0][1];
        }
        int avg = sum/nodes;
        if(avg == root->val) ans++;
        vector<int> res = {sum,nodes};
        return res;
        
    }
    int averageOfSubtree(TreeNode* root) {
        ans =0;
        dfs(root);
        return ans;
        
    }
};