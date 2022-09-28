/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* curr_node,unordered_map<Node*,Node*> & vis){
        
        int curr_val = curr_node->val;
        // cout<<curr_val<<endl;
        Node* new_node = new Node(curr_val);
        
        for(int i=0;i<curr_node->neighbors.size();i++){
            if(vis.find(curr_node->neighbors[i])==vis.end()){
                vis[curr_node]=new_node;
                new_node->neighbors.push_back(dfs(curr_node->neighbors[i],vis));
            }
            else{
                new_node->neighbors.push_back(vis[curr_node->neighbors[i]]);
            }
        }
        vis[curr_node]=new_node;
        return new_node;
        
    }
    Node* cloneGraph(Node* node) {
        // vector<Node*> vis(101,NULL);
        if(node==NULL) return NULL;
        unordered_map<Node*,Node*> vis;
        return dfs(node,vis);
        // cout<<new_node->neighbors[0]->val<<endl;
        
    }
};