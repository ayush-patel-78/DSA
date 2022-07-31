class NumArray {
public:
    int n;
    vector<int> seg;
    int build(vector<int>& nums,int left,int right,int node){
        int middle;
        int left_sum,right_sum;
        if(left == right) return seg[node]=nums[left];
        middle = left + (right - left)/2;
        left_sum = build(nums,left,middle,2 * node + 1);
        right_sum = build(nums,middle+1,right,2 * node + 2);
        return seg[node]=left_sum + right_sum;
    }
    int sumRange(int left,int right,int ss,int se,int node){
        int middle;
        int left_sum,right_sum;
        
        if(left > se || right < ss) return 0;
        if(left<=ss && right>=se) return seg[node];
        
        middle = ss + (se - ss)/2;
        left_sum = sumRange(left,right,ss,middle,2 * node + 1);
        right_sum = sumRange(left,right,middle+1,se,2 * node + 2);
        return left_sum + right_sum;
    }
    
    int update(int index,int newValue,int ss,int se,int node){
        int left_sum,right_sum;
        int middle;
        
        if(index < ss || index > se) return seg[node];
        if(ss == se) return seg[node]=newValue;
        
        middle = ss + (se - ss)/2;
        left_sum = update(index,newValue,ss,middle,2 * node +1);
        right_sum = update(index,newValue,middle+1,se,2 * node + 2);
        
        return seg[node]=left_sum + right_sum;
    }
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4 * n);  
        build(nums,0,n-1,0);
    }
    
    void update(int index, int val) {
        update(index,val,0,n-1,0);
    }
    
    int sumRange(int left, int right) {
        return sumRange(left,right,0,n-1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */