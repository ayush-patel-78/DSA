// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */
#define ll long long
class Solution{
  public:
    bool backtrack(vector<int>& arr,map<int,bool>& visited,ll target,int k,ll curr_sum,ll index){
        if(k==0) return true;
        if(curr_sum > target) return false;
        if(curr_sum==target) 
            return backtrack(arr,visited,target,k-1,0,0);
        
        for(int i=index;i<arr.size();i++){
            if(visited[i]==true) continue;
            visited[i]=true;
            if(backtrack(arr,visited,target,k,curr_sum+arr[i],i+1)) return true;
            visited[i]=false;
        }
        return false;
        
        
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
        if(k==1) return true;
         //Your code here
         vector<int> arr(n);
         ll total = 0;
         for(int i=0;i<n;i++){
             total += a[i];
             arr[i]=a[i];
         }
         ll target = total/k;
         if(total%k != 0) return false;
          map<int,bool> visited;
         
         for(int i=0;i<n;i++){
             if(arr[i]>target){
                 return false;
             }
             visited[i]=false;
         }
        ll curr_sum = 0;
        ll index = 0;
        return backtrack(arr,visited,target,k,curr_sum,index);
         
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
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends