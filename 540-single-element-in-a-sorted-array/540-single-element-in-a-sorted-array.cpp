#define ll long long
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        ll low = 0;
        ll high = nums.size()-1;
        ll mid;
        while(high-low >= 1){
            mid = (high+low)/2;
            if((mid-low)%2==0){
               if(nums[mid]==nums[mid+1]){
                    low = mid;
                }
                else if(nums[mid]==nums[mid-1]){
                    high = mid;
                }
                else return nums[mid]; 
            }
            else{
                if(nums[mid]==nums[mid-1]){
                    low = mid+1;
                }
                else if(nums[mid]==nums[mid+1]){
                    high = mid-1;
                }
                else return nums[mid];
            }
            
        }
        return nums[low];
    }
};