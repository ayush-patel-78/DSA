class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> original;
        vector<int> doubled;
        int count_zeroes=0;
        map<int,int> mpp;
        sort(changed.begin(),changed.end());
        for(int i=0;i<changed.size();i++){
            mpp[changed[i]]++;
            if(changed[i]==0)
                count_zeroes++;
        }
        if(changed.size() % 2 == 1) return original;
        if(count_zeroes%2==1) return original;
        for(int i=0;i<changed.size();i++){
            int x = changed[i];
            if(mpp.find((2*x))!=mpp.end()&& x!=0 && mpp[x]>0 && mpp[2*x]>0 ){
                cout<<2*x<<endl;
                mpp[x]--;
                mpp[2*x]--;
                original.push_back(x);
                doubled.push_back(2*x);
            }
        }
        int zeroes = count_zeroes/2;
        while(zeroes--){
            original.push_back(0);
        }
        
        if(2*original.size() == changed.size()){
            return original;
        }
        vector<int> ans;
        return ans;
    }
};