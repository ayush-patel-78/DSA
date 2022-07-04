// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    bool static compare(Item& i1,Item& i2){
        return ((float)i1.value/i1.weight)>((float)i2.value/i2.weight);
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        double profit = 0;
        sort(arr,arr+n,compare);
        for(int i=0;i<n;i++){
            if(arr[i].weight<=W && W!=0){
                profit += arr[i].value;
                W -=arr[i].weight;
            }
            else{
                profit += ((float)arr[i].value/arr[i].weight)*W;
                break;
            }
        }
        return profit;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends