//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    string convert(string s, int n) {
        
        vector<vector<char>> vec(n);
        int j=0;
        while(j<s.size()){
            for(int i=0;i<n && j<s.size();i++){
                vec[i].push_back(s[j]);
                j++;
            }
            for(int i=n-2;i>0 && j<s.size();i--){
                vec[i].push_back(s[j]);
                j++;
            }
        }
        string ans ;
        for(int i=0;i<n;i++){
            for(int j=0;j<vec[i].size();j++){
                ans += vec[i][j];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while (t--){
        string str;
        cin>>str;
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.convert(str, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends