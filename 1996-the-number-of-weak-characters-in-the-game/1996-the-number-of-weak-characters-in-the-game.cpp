class comparator{
    public:
    bool operator()(vector<int>const& v1,vector<int>const& v2){
        if(v1[1]>v2[1]) return true;
        else if(v1[1]==v2[1] && v1[0]>v2[0]) return true;
        return false;
    }
};
class Solution {
public:
    bool static compare(vector<int>& v1,vector<int>& v2){
        if(v1[0]<v2[0]) return true;
        else if(v1[0]==v2[0] && v1[1]>v2[1]) return true;
        return false;
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),compare);
              
        int count = 0;
        long long max_def = INT_MIN;
        for(int i=properties.size()-1;i>=0;i--){
            if(properties[i][1]< max_def ) count++;
            else{
                max_def = properties[i][1];
            }
            
        }
        return count;
    }
};