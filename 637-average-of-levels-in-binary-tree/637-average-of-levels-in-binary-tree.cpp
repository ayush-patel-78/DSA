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
    vector<double> averageOfLevels(TreeNode* root) {
          queue<TreeNode*> q;
        vector<double> ans;
        q.push(root);
        q.push(NULL);
        double count = 0;
        double sum = 0;
        bool check = false;
        while(!q.empty()){
            TreeNode* temp = q.front();
            
            q.pop();
            if(temp==NULL && check ==true) break;
            if(temp==NULL){
                double avg = sum/count;
                ans.push_back(avg);
                count=0;
                sum = 0;
                check=true;
                q.push(NULL);
                continue;
            }
            check = false;
            count++;
            sum += temp->val;
            if(temp->right !=NULL) q.push(temp->right);
            if(temp->left !=NULL) q.push(temp->left);
        }
        return ans;
    }
};