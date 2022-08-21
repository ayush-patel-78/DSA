class Solution {
public:
    bool canReplace(string& target,int pos,string stamp){
        for(int i=0;i<stamp.size();i++){
            if(target[i+pos] != '?' && target[i+pos] != stamp[i]){
                // cout<<target<<endl;
               return false; 
            }
                
        }
        // cout<<"hehe"<<endl;
        return true;
    }
    int replace(string& target,int len,int pos,int count){
        for(int i=0;i<len;i++){
            if(target[i+pos]!='?'){
                target[i+pos]='?';
                count++;
            }
        }
        return count;
        
    }
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> ans;
        vector<bool> vis(target.size());
        int count = 0;
        while(count != target.size()){
            bool didChange = false;
            for(int i=0;i<=target.size()-stamp.size();i++){
                // cout<< "pos:"<<i<<endl;
                if(!vis[i] && canReplace(target,i,stamp)){
                    count = replace(target,stamp.size(),i,count);
                    // cout<<i<<" ";
                    ans.push_back(i);
                    vis[i]=true;
                    didChange = true;
                }
                if(count == target.size()) break;
            }
            if(!didChange){
                vector<int> s;
                return s;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
         
        
        
    }
};