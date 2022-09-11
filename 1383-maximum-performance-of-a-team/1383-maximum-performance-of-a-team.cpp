#define ll long long
#include <bits/stdc++.h>
class comparator{
    public:
    bool operator()(pair<ll,ll>const & p1,pair<ll,ll>const & p2){
        if( p1.second>p2.second) return true;
        else if(p1.second==p2.second && p1.first>p2.first) return true;
        return false;
    }
};
class Solution {
public:
    bool static compare(pair<ll,ll> & p1,pair<ll,ll> & p2){
         if( p1.first>p2.first) return true;
        else if(p1.first==p2.first && p1.second>p2.second) return true;
        return false;
    }
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
       
        vector<pair<ll,ll>> hehe(n);
        for(int i=0;i<n;i++){
            hehe[i].first = efficiency[i];
            hehe[i].second = speed[i];
        }
        
        sort(hehe.begin(),hehe.end(),compare);
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        ll speed_sum =0;
        ll result = 0;
       
        for(int i=0;i<n;i++){
            speed_sum += hehe[i].second ;
            pq.push(hehe[i].second);

            if(pq.size()>k) {
                speed_sum -= pq.top();
                pq.pop();
            }
            result = max(result , speed_sum*hehe[i].first);
        }
        return result%1000000007;
    
    }
};