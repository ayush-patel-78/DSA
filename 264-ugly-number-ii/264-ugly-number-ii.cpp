#define ll unsigned long long int
class Solution {
public:
    void solve_2(ll num,priority_queue<ll,vector<ll>,greater<ll>>& pq,int count ,int stop){
        if(count >= stop) return;
        
        num = num * 2;
        pq.push(num);
        count++;
        solve_2(num,pq,count,stop);
        solve_3(num,pq,count,stop);
        solve_5(num,pq,count,stop);
    }
    void solve_3(ll num,priority_queue<ll,vector<ll>,greater<ll>>& pq,int count ,int stop){
        if(count >= stop) return;
        num = num * 3;
        pq.push(num);
         count++;
         // solve_2(num,pq,count,stop);
        solve_3(num,pq,count,stop);
        solve_5(num,pq,count,stop);
    }
    void solve_5(ll num,priority_queue<ll,vector<ll>,greater<ll>>& pq,int count ,int stop){
        if(count >= stop) return;
        num = num * 5;
        pq.push(num);
         count++;
        // solve_2(num,pq,count,stop);
        // solve_3(num,pq,count,stop);
        solve_5(num,pq,count,stop);
    }
    int nthUglyNumber(int n) {
        bool check_2 = true;
        bool check_3 = true;
        bool check_5 = true;
        int count = 0;
        int stop = 32;
        priority_queue<ll,vector<ll>,greater<ll>> pq;
    
        ll num = 1;
        pq.push(1);
        solve_2(num,pq,count,stop);
        solve_3(num,pq,count,stop);
        solve_5(num,pq,count,stop);
        cout<<pq.size()<<endl;
        n--;
        while(n--){
            pq.pop();
        }
        return pq.top();
        
    }
};