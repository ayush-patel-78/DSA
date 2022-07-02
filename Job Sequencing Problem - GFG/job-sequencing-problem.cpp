// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    bool static compare(Job& j1,Job& j2){
        
        if(j1.profit>j2.profit) return true;
        else return false;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        int jobs_done = 0;
        int profit = 0;
        int timer = 0;
        int max_deadline = 0;
        sort(arr,arr+n,compare);
        for(int i=0;i<n;i++){
            if(arr[i].dead>max_deadline){
                max_deadline = arr[i].dead;
            }
        }
        vector<int>vec(max_deadline,-1);
        for(int i=0;i<n;i++){
            int dead = arr[i].dead;
            int j = dead-1;
            while(j!=-1){
                if(vec[j]==-1){
                    vec[j]=arr[i].profit;
                    jobs_done++;
                    profit+=vec[j];
                    break;
                }
                else j--;
            }
        }
        vector<int> ans;
        ans.push_back(jobs_done);
        ans.push_back(profit);
        return ans;
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends