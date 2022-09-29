/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;
        vector<vector<Node*>> result;
        vector<Node*> temp;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        bool check = false;
        
        while(!q.empty()){
            Node* top = q.front();
            q.pop();
            if(top==NULL && check==false){
                result.push_back(temp);
                temp.clear();
                check = true;
                q.push(NULL);
                continue;
            }
            if(top){
                check = false;
                temp.push_back(top);
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
        }
        for(int i=0;i<result.size();i++){
            for(int j=0;j<result[i].size();j++){
                if(j<result[i].size() && j+1<result[i].size()){
                    result[i][j]->next=result[i][j+1];
                }
                else break;
            }
        }
        return result[0][0];
    }
};