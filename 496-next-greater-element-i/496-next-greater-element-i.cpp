class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        unordered_map<int,int> mpp;
        for(int i=0;i<nums1.size();i++){
            mpp[nums1[i]]=-2;
        }
        vector<int>ans;
        
        for(int i = nums2.size()-1; i>=0; i--)
        {
            int curr = nums2[i];
            if(mpp.find(curr)==mpp.end()){
                s.push(curr);
               continue; 
            } 
            else{
                   while(!s.empty()){
                       int front = s.top();
                       if(front > curr){
                           mpp[curr]=front;  
                           break;
                       }
                       else{
                           s.pop();
                       }
                    }
                    if(s.empty()) {
                        mpp[curr]=-1;
                    }
                    s.push(curr);
            }
            
        }
        // for(auto x: mpp){
        //     cout<<x.first<< " "<<x.second<<endl;
        // }
        for(int i=0;i<nums1.size();i++){
            ans.push_back(mpp[nums1[i]]);
        }
        return ans;
    }
};