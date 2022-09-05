/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
// #include <bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        bool check = false;
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        vector<int> hehe;
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            if(temp == NULL && check == false){
                ans.push_back(hehe);
                hehe.clear();
                check = true;
                q.push(NULL);

            }
            if(temp){
                check = false;
            
                hehe.push_back(temp->val);
                for(int i=0;i<temp->children.size();i++){
                    q.push(temp->children[i]);
            }
            
            }
        }
        return ans;
    }
};