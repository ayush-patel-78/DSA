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
    int minCol = 1000;
    int maxCol = -1000;
    void treeStore(TreeNode* node, int col,int row, map<pair<int,int>,vector<int>>& ans){
        ans[{col, row}].push_back(node->val);
        if(col<minCol) minCol = col;
        if(col>maxCol) maxCol = col;
        if(node->left) treeStore(node->left, col-1,row+1, ans);
        if(node->right) treeStore(node->right, col+1,row+1, ans);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<pair<int,int>,vector<int>> ans_map;
        if(root) treeStore(root, 0,0, ans_map);
        vector<vector<int>> ans(maxCol+ abs(minCol)+1);
        for(auto x:ans_map)
            {
                sort(x.second.begin(),x.second.end());
                int temp = x.first.first + abs(minCol);
                for(auto y: x.second)   
                    ans[temp].push_back(y);
            }
        return ans;
    }
};