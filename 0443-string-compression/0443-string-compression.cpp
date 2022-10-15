class Solution {
public:
    int solve(vector<char>& chars,int count,int i,int prev,vector<char>& v){
        stack<int> s;
        if(i >= chars.size()) {
            v.push_back(prev);
            if(count != 1){
                while(count > 0){
                  int rem = count%10;
                    count = count/10;
                    s.push(rem+48);
                }
                while(!s.empty()){
                    v.push_back(s.top());
                    s.pop();
                }
            }
            return 0;
        }
        int len = 0;
        if(chars[i] == prev){
            if(count ==1 || count == 9 || count==99 || count==999){
                len +=1;
            }
            len = len + solve(chars,count+1,i+1,prev,v);
            
        }
        
        else{
            v.push_back(prev);
            if(count != 1){
                while(count > 0){
                  int rem = count%10;
                    count = count/10;
                    s.push(rem+48);
                }
                while(!s.empty()){
                    v.push_back(s.top());
                    s.pop();
                }
            }
            len = 1 + solve(chars,1,i+1,chars[i],v);
        }
        return len;
    }
    int compress(vector<char>& chars) {
        if(chars.size()==1) return 1;
        vector<char> v;
        int ans = solve(chars,0,0,26,v);
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        for(int i=1,j=0;i<v.size();i++,j++){
            chars[j]=v[i];
        }
        return ans;
        
    }
};