#define ll long long
class Solution {
public:
   
    bool help(vector<int>& matchsticks,ll length,vector<int>& sides,ll index){
        if(index==matchsticks.size()){
            if(sides[0]==sides[1] && sides[1]==sides[2] && sides[2]==sides[3]){
                return true;
            }
            return false;
        }
        for(int i=0;i<sides.size();i++){
            int j=i-1;
            while(j>=0){
                if(sides[j]==sides[i]){
                    break;
                }
                j--;
            }
            if(j!=-1) {
                continue;
            }
            sides[i]+=matchsticks[index];
            if(sides[i]<=length && help(matchsticks,length,sides,index+1)){
                return true;
            }
            sides[i]-=matchsticks[index];
        }
        return false;
        
    }
    bool makesquare(vector<int>& matchsticks) {
        ll sum = 0;
        ll maximum_value = 0;
        for(int i=0;i<matchsticks.size();i++){
            sum+=matchsticks[i];
            if(matchsticks[i]>maximum_value){
                maximum_value = matchsticks[i];
            }
        }
        if((sum%4)!=0 || maximum_value>sum/4) return false;
        ll length = sum/4;
        vector<int> sides(4);
        ll index = 0;
        return help(matchsticks,length,sides,index);
    }
};