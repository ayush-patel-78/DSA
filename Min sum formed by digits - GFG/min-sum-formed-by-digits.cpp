// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#define ll long long
class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        // Your code goes here
        sort(arr,arr+n);
        int i=0;
        ll first = 0;
        ll second = 0;
        ll j=0;
        while(j<n-1){
            
            first = first*10 + arr[j];
            j++;
            second = second*10 + arr[j];
            j++;
        }
        if(j==n-1){
            
           first = first*10 + arr[j]; 
        } 
        return first+second;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends