class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,string> mpp;
        
        mpp[1]="I";
        mpp[5]="V";
        mpp[10]="X";
        mpp[50]="L";
        mpp[100]="C";
        mpp[500]="D";
        mpp[1000]="M";
        string ans;
        vector<int> vec={1000,500,100,50,10,5,1};
        vector<string> hehe;
        for(int i=0;i<vec.size();i+=2){
            string s="";
            int x = num/vec[i];
            num = num - (x*vec[i]);
            if(x<=3){
                for(int j=0;j<x;j++){
                    s += mpp[vec[i]];
                }
            }
            else if(x==4){
                s =  mpp[vec[i]] + mpp[vec[i-1]] ;
            }
            else if(x==5){
                s = mpp[vec[i-1]];
            }
            else if(x<=8){
                s+= mpp[vec[i-1]];
                for(int j=5;j<x;j++){
                    s += mpp[vec[i]];
                }
            }
            else if(x==9){
                s = mpp[vec[i]] + mpp[vec[i-2]];
            }
            
            hehe.push_back(s);
            ans += s;
        }
        return ans;
        
    }
};