//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class DisjointSet {
    private: 
          vector<int> rank,parent,child;
    public: 

          DisjointSet(int n){
              parent.resize(n+1);
              rank.resize(n+1,0);
              child.resize(n+1,1);

              for(int i=0;i<=n;i++){
                  parent[i]=i;
              }
          }
          int findUPar(int node){
              if(node == parent[node]) return node;
              return parent[node] = findUPar(parent[node]);
          }

          void unionByRank(int v,int u){
              int parV = findUPar(v);
              int parU = findUPar(u);
              if(parV == parU) return;

              if(rank[parV] > rank[parU]){
                  parent[parU] = parV;
              }
              else if(rank[parU] > rank[parV]){
                  parent[parV] = parU;
              }
              else{
                  parent[parU] = parV;
                  rank[parV]++;
              }
              

          }

          void unionBySize(int v,int u) {
              int parV = findUPar(v);
              int parU = findUPar(u);
              if(parV == parU) return;
              if(child[parV] <= child[parU]){
                  parent[parV] = parU;
                  child[parU]+=child[parV];
              }
              else if(child[parU]<child[parV]){
                  parent[parU] = parV;
                  child[parV]+=child[parU];
              }
              
          }
};
class Solution {
public:
    int maxRemove(vector<vector<int>>& stones, int n) {
       int maxRow = 0;
        int maxCol = 0;

        for(auto it: stones){
            maxRow = max(maxRow,it[0]);
            maxCol = max(maxCol,it[1]);
        }
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int,int> vis;
        // col = col + maxRow + 1
        for(auto it: stones){
            int nodeRow = it[0];
            int nodeCol = it[1]+maxRow +1;
            ds.unionByRank(nodeRow,nodeCol);
            vis[nodeRow]=1;
            vis[nodeCol] = 1;

        }
        int components = 0;
        for(auto it:vis){ 
            if(ds.findUPar(it.first)==it.first) components++;
        }
        
        return n - components;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x; cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj,n) << "\n";
    }
}
// } Driver Code Ends