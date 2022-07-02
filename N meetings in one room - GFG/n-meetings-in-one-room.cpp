// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    bool static compare(vector<int>& m1,vector<int>& m2){
        if(m1[1]<m2[1]){
            return true;
        }
        else if(m1[1]==m2[1]){
            if(m1[2]<m2[2]) return true;
            else return false;
        }
        else return false;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<vector<int>> meetings;
        for(int i=0;i<n;i++){
            vector<int> temp;
            temp.push_back(start[i]);
            temp.push_back(end[i]);
            temp.push_back(i+1);
            meetings.push_back(temp);
        }
        sort(meetings.begin(),meetings.end(),compare);
        int count = 0;
        int prev=-1;
        for(int i=0;i<n;i++){
            if(meetings[i][0]>prev){
                count++;
                prev = meetings[i][1];
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends