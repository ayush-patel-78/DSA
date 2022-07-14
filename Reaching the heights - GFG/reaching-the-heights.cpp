// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++
#define ll long long
vector<int> reaching_height(int n, int a[]) {
    // Complete the function
    sort(a,a+n);
    vector<int> arr;
    ll i=0;
    ll j=n-1;
    ll down = 0;
    ll up = 0;
    for( i=0,j=n-1;i<n/2 && j>=n/2;i++,j--){
        arr.push_back(a[j]);
        up +=a[j];
        arr.push_back(a[i]);
        down+=a[i];
    }
    if(j==n/2) {
        arr.push_back(a[j]);
        up+=a[j];
    }
    if(up-down > 0) return arr;
    vector<int> vec(1,-1);
    return vec;
}
