class Solution {
public:
    string breakPalindrome(string palindrome) {
        int size = palindrome.size();
        if(size==1) return "";
        bool check_odd=true;
        bool did = false;
        if(size % 2 == 0){
            check_odd = false;
        }
        if(check_odd == false){
            for(int i=0;i<size ; i++){
                if(palindrome[i]!='a'){
                    palindrome[i]='a';
                    did = true;
                    break;
                }
            }
            if(did == false){
                palindrome[size - 1]='b';
            }
        }
        else{
            int mid = size/2;
            for(int i=0;i<size ; i++){
                if(i==mid) continue;
                if(palindrome[i]!='a'){
                    palindrome[i]='a';
                    did = true;
                    break;
                }
            }
            if(did == false){
                palindrome[size - 1]='b';
            }
        }
        return palindrome;
    }
};