// class Solution {
// public:
 
//         int minStop(int target,int fuelLeft,vector<vector<int>>& stations,int travelled,int i,vector<vector<int>>& dp){
//              if(i!= stations.size() && (fuelLeft +travelled - stations[i][0])< 0) return -1;
//             if(travelled + fuelLeft >= target){
//                 return 0;
//             }
//             if(i==stations.size() && travelled+fuelLeft<target) return -1;
//             if(dp[fuelLeft][i]!=INT_MAX) return dp[fuelLeft][i];
//            int ans1 = minStop(target,fuelLeft-(stations[i][0] - travelled) ,stations,stations[i][0],i+1,dp);
            
//             int ans2 = minStop(target,fuelLeft-(stations[i][0] - travelled) +stations[i][1],stations,stations[i][0],i+1,dp);
//             if(ans1 == -1 && ans2 == -1){
//                 return dp[fuelLeft][i]=-1;
//             }
//             else if(ans1 != -1 && ans2 != -1) {
//                 return dp[fuelLeft][i]=min(ans1,ans2+1);
//             }
//             else if(ans1==-1){
//                 return dp[fuelLeft][i]=ans2+1;
//             }
//             else{
//                 return dp[fuelLeft][i]=ans1;
//             }
               
//     }
//     int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
//         int fuelLeft = startFuel ;
//         vector<vector<int>> dp(target,vector<int>(stations.size()+1,INT_MAX));
//         int travelled = 0;
//         return minStop(target,fuelLeft,stations,travelled,0,dp);
//     }
// };

// typedef unsigned long long ull;
// class Solution {
// public:
//     int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
//         int n = stations.size();
        
//         vector<vector<ull>> t(n+1, vector<ull>(n+1, 0));
//         //t[i][j] = Maximum distance reached if I stopped at 'j' fuelStops from total of 'i' fuelStops
//         //i.e. j <= i
        
//         //If j = 0, i.e. I did not use any fuelStops, Then maximum I can reach is 'startFuel' which I had initially
        
//         //So, initialize the dp array with this information
//         for(int i = 0; i<n+1; i++) {
//             t[i][0] = startFuel;
//         }
        
//         //There is no point of filling 1st row because 
//         //t[0][j] means I used j fuelStops from 0 fuelStops which doesn't make any sense for (j>0)
//         //That's why I start from i = 1 and obviously j = 1 because for j = 0 we already populated the dp array
        
//         for(int i = 1; i < n+1; i++) {
//             for(int j = 1; j <= i; j++) { //I can use j=1 to j=i fuel stops and find max distance for t[i][j]
//                 //case-1 (I don't refuel at current fuelstop)
//                 //If I didn't refuel at current stop, the max distance I can cover is equal to maximum
//                 //distance I could cover from previous state
//                 t[i][j] = t[i-1][j];
                
//                 //case-2 (I will refuel at current fuelStop)
//                 //But check if you can even reach this station (stations[i-1][0]) or not from your previous station
//                 if(t[i-1][j-1] >= stations[i-1][0]) {
//                     t[i][j] = max(t[i][j], t[i-1][j-1] + stations[i-1][1]);
//                 }
                
//             }
//         }
        
//         //After you end up with all stations, check which t[n][j] was best for reaching target
//         //Best means, minimum j used by you to reach target
//         for(int j = 0; j<n+1; j++) {
//             if(t[n][j] >= target)
//                 return j;
//         }
        
//         //You could never reach target, so return -1
//         return -1;
//     }
// };
//Approach-2 : O(n^2)dp
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        
        vector<long long> t(n+1, 0);
        //t[j] = max distance that I can reach using j fuelStops
        
        //When I don't use any fuelStop, I can travel as much as I had startFuel in the beginning
        t[0] = startFuel;
        
        for(int i = 1; i<n+1; i++) {
            //traverse on all fuel stops
            
            //I can use all i fuelStops, or (i-1), or (i-2) ... till 0 to find which gave me best result
            //So. j goes from j = i to j = 0
            for(int j = i; j>=0; j--) {
                //But first, I need to check If I can even reach curr station or not to use it
                if(t[j] >= stations[i-1][0]) {
                    //So, we can use this fuelStop and now we are using (j+1) fuelStops
                    t[j+1] = max(t[j+1], t[j] + stations[i-1][1]);
                }
            }
        }
        
        //After you end up with all stations, check which was best for reaching target
        //Best means, minimum j used by you to reach target
        
        for(int j = 0; j<n+1; j++) {
            if(t[j] >= target)
                return j;
        }
        
        return -1;
    }
};