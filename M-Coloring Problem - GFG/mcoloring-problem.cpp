// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
#define ll long long
#include<bits/stdc++.h>
bool isPossible(int i,int j,map<int,int>& color,bool graph[101][101],int n){
    for(int x=0;x<n;x++){
        if(graph[i][x]==1){
            if(color[x]==j) return false;
        }
    }
    return true;
    
}
bool solve(bool graph[101][101], int& m, int& n,map<int,int>& color,int index){
    
     if(index==n) return true;  
    for(int j=1;j<=m;j++){
        
        if(isPossible(index,j,color,graph,n)){
            color[index]=j;
             if(solve(graph,m,n,color,index+1))return true;
        } 
        color[index]=0;
    }
    return false;

}
bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    map<int,int> color;
    for(int i=0;i<n;i++){
        color[i]=0;
    }
    return solve(graph,m,n,color,0);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends