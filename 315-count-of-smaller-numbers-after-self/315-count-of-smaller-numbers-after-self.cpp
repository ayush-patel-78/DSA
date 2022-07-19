class Solution {
public:
    void merge(vector<int>&count,vector<pair<int,int>>& v,int left,int mid,int right){
        vector<pair<int,int>> temp(right-left+1);
        int i = left;
        int j = mid+1;
        int k = 0;
        
        while(i<=mid && j<=right){
            if(v[i].first <= v[j].first){
                temp[k++] = v[j++];
            }
            else{
                // main 
                count[v[i].second] += right - j + 1;
                temp[k++]=v[i++];
            }
        }
        while(i<=mid){
            temp[k++]=v[i++];
        }
        while(j<=right){
            temp[k++]=v[j++];
        }
        for(int i= left ;i<=right;i++){
            v[i] = temp[i-left];
        }
        
    }
    void mergeSort(vector<int>&count,vector<pair<int,int>>& v,int left,int right){
        if(left < right){
            int mid = left + (right - left)/2;
            mergeSort(count,v,left,mid);
            mergeSort(count,v,mid+1,right);
            merge(count,v,left,mid,right);
        }
        
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>> v;
	    for(int i=0;i<nums.size();i++){
	       pair<int,int> p;
	       p.first = nums[i];
	       p.second = i;
	       v.push_back(p);
	    }
	    vector<int> count(nums.size(),0);
	    mergeSort(count,v,0,nums.size()-1);
	    return count;
    }
};