class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<vector<int>> st;
        if(nums[0]>0) return ans;
        if(nums[0]==0 && nums[1]==0 && nums[2]==0) {
            ans.push_back({0,0,0});
            return ans;
        }
       
        int sum = 0;
        int prevk = INT_MAX;
        for(int k=0;k<nums.size();k++){
            // while(k<nums.size() && nums[k]==prevk){
            //     k++;
            // }

            for(int i=k+1,j=nums.size()-1;i<j ;){
                if(j==k){
                    j--;
                    continue;
                }
                sum = nums[i]+nums[j]+nums[k];
                if(sum == 0){
                    vector<int> hehe;
                    hehe.push_back(nums[i]);
                    hehe.push_back(nums[j]);
                    hehe.push_back(nums[k]);
                    sort(hehe.begin(),hehe.end());
                    if(st.find(hehe)==st.end()){
                        ans.push_back(hehe);
                        st.insert(hehe);
                    }
                    int previ = nums[i];
                    int prevj = nums[j]; 
                    while(i<j && nums[i] == previ){
                        i++;
                    }
                    while(i<j && nums[j] == prevj){
                        j--;
                    }
                    
                   
                }
                else if(sum > 0){    
                    j--;
                }
                else if(sum < 0){
                    i++;
                }
            
            }
            prevk = nums[k];
        }
        return ans;
    }
};