// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	void findCombination(vector<int>& coin,vector<vector<int>>& st,vector<int>& ans,int index,int target,int n,int& minimum_coin){

	   if(target==0){
	            st.push_back(ans);
	            if(ans.size() <= minimum_coin){
	                minimum_coin = ans.size();
	            }
	            return;
	   }
	   if(index==n) return;
	    
	    if(target - coin[index] >= 0){
	        ans.push_back(coin[index]);
	        if(ans.size()<=minimum_coin){
	           findCombination(coin,st,ans,index,target-coin[index],n,minimum_coin); 
	        }
	        ans.pop_back();
	    }
	    findCombination(coin,st,ans,index+1,target,n,minimum_coin);
	}
	bool static compare(int& c1,int& c2){
	    return c1>c2;
	}
	int minCoins(int coins[], int n, int target) 
	{ 
	    vector<int> coin;
	    for(int i=0;i<n;i++){
	        coin.push_back(coins[i]);
	    }
	    sort(coin.begin(),coin.end(),compare);
	    vector<vector<int>> st;
	    vector<int> ans;
        int minimum_coin = INT_MAX;
	    findCombination(coin,st,ans,0,target,n,minimum_coin);
	   // int min_coin = INT_MAX;
	   // for(auto x:st){
	   //     if(x.size()<min_coin){
	   //         min_coin = x.size();
	   //     }
	   // }
	    if(st.size()==0) return -1;
	    return minimum_coin;
	    
	    
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends