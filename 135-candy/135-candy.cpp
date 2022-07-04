#define ll long long
class Solution {
public:
    // vector<int> solve(,vector<int>& ratings,vector<int>& dp,int i){
    //     if(i>=dp.size()){
    //         if(vector)
    //     }
    // }
    int candy(vector<int>& ratings) {
       vector<int> candies_left(ratings.size(),1);
        vector<int> candies_right(ratings.size(),1);
        for(int i=1;i<ratings.size();i++){
            if(ratings[i]>ratings[i-1]){
                candies_left[i]=candies_left[i-1]+1;
            }   
        }
        for(int i=ratings.size()-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                candies_right[i]=candies_right[i+1]+1;
            }   
        }
        ll candies_total = 0;
        for(int i=0;i<ratings.size();i++){
            candies_total+=max(candies_left[i],candies_right[i]);
            
        }
        return candies_total;
        
    }
};