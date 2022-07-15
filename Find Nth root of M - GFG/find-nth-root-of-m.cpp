// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#define ll long long
class Solution{
 	public:
	int NthRoot(int n, int m)
	{
	    // Code here.
	    ll low = 1;
	    ll high = m;
	    ll mid =m;
	    while(pow(mid,n)!=m){
	        mid = (low+high)/2;
	        if(pow(mid,n)>m){
	            high = mid;
	        }
	        if(pow(mid,n)<m){
	            low = mid;
	        }
	        if((high - low) <= 1){
	            return -1;
	        }
	    }
	    return mid;
	}  
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends