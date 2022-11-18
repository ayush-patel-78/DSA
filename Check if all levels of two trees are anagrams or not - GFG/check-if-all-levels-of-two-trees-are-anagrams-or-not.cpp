//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    vector<vector<int>> bfs(Node *root){
        vector<vector<int>> hehe;
        queue<Node*> q;
        if(root==NULL) return hehe;
        q.push(root);
        q.push(NULL);
        bool check = false;
        vector<int> temp;
        while(!q.empty()){
            Node* root = q.front();
            q.pop();
            if(root==NULL){
                if(check){
                    hehe.push_back(temp);
                    temp.clear();
                    q.push(NULL);
                    check = false;
                }
                else break;
            }
            else{
                temp.push_back(root->data);
                if(root->left!=NULL){
                    q.push(root->left);
                    check = true;
                }
                if(root->right!=NULL){
                    q.push(root->right);
                    check = true;
                }
            }
        }
        hehe.push_back(temp);
        return hehe;
    }
    bool areAnagrams(Node *root1, Node *root2)
    {
        vector<vector<int>> tree1 = bfs(root1);
        vector<vector<int>> tree2 = bfs(root2);
        
        if(tree1.size() != tree2.size()) return false;
        for(int i=0;i<tree1.size();i++){
            sort(tree1[i].begin(),tree1[i].end());
            sort(tree2[i].begin(),tree2[i].end());
            
            if(tree1[i].size() != tree2[i].size()) return false;
            for(int j=0;j<tree1[i].size();j++){
                if(tree1[i][j]!=tree2[i][j]) return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node *root1 = buildTree(treeString1);
        getline(cin, treeString2);
        Node *root2 = buildTree(treeString2);
        Solution ob;
        cout << ob.areAnagrams(root1, root2) << endl;
    }
    return 0;
}

// } Driver Code Ends