class Solution {
public:
    bool validUtf8(vector<int>& data) {
        string str = "";
        for(int j=0;j<data.size();j++){
            string newstr ="";
            int hehe = data[j];
            for(int i=1;i<=8;i++){
                  
                    int rem = hehe%2;
                   hehe = hehe/2;
                  
                   newstr = to_string(rem) + newstr;
            }
            str += newstr;
        }
        cout<<str<<endl;
        int count = 0;
        int index=0;
        while(index < str.size()){
            count =0;
            for(int i = index;i<str.size();i++){
                if(str[i]=='1'){
                    count++;
                }
                 else break;
            }
            if(count >4) return false;
            if(count==1) return false;
            index += ((count/8 )+ 1)*8;
            bool check = true;
            for(;index<str.size() && count >1;){
                if(str[index]!='1'){
                    check = false;
                    return check;
                }
                if(str[index+1]!='0'){
                    check = false;
                    return check;
                }
                index +=8;
                count--;
            }
        }
        if(count > 1) return false;
        return true;
        
    }
};