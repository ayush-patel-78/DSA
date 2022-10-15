class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> index;
        for(int i=0,j=numbers.size()-1;i<numbers.size() && j>=0;){
            if(numbers[i]+numbers[j]==target){
                index.push_back(i+1);
                index.push_back(j+1);
                break;
            }
            if(numbers[i]+numbers[j]>target){
                j--;
            }
            else{
                i++;
            }
        }
        return index;
    }
};