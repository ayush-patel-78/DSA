class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<pair<int,int>> left;
        vector<pair<int,int>> right;
        int left_p = 0;
        int right_p = 0;
        int count_l = 0;
        int count_r = 0;
        
        for(int i=0;i<dominoes.size();i++){
            if(dominoes[i]=='L'){
                count_l = 1;
                if(count_r == 0){
                    left.push_back({left_p,i});
                    count_l= 0;
                }
                left_p = i;
                if(count_r == 1 && count_l == 1){
                    int total = left_p + right_p;
                    if(total%2==0){
                        int mid = total/2;
                        right.push_back({right_p,mid-1});
                        left.push_back({mid + 1,left_p});
                    }
                    else{
                        int mid = total/2;
                        right.push_back({right_p,mid});
                        left.push_back({mid+1,left_p});
                    }
                    count_l = 0;
                    count_r = 0;
                }
            }
            if(dominoes[i]=='R'){
                count_r++;
                if(count_r > 1){
                    right.push_back({right_p,i});
                    count_r = 1;
                }
                right_p = i;
            }
        }
        if(count_r>0){
            right.push_back({right_p,dominoes.size()-1});
        }
//         cout<<"LEFT"<<endl;
//         for(int i=0;i<left.size();i++){
//             cout<<left[i].first<<" "<<left[i].second<<endl; 
//         }
//         cout<<"RIGHT "<<endl;
//         for(int i=0;i<right.size();i++){
//             cout<<right[i].first<<" "<<right[i].second<<endl; 
//         }
        
    
        for(int i=0;i<left.size();i++){
            int x = left[i].first;
            int y = left[i].second;
            for(int z=x;z<=y;z++){
                dominoes[z]='L';
            }
        }
         for(int i=0;i<right.size();i++){
            int x = right[i].first;
            int y = right[i].second;
            for(int z=x;z<=y;z++){
                dominoes[z]='R';
            }
        }
        return dominoes;
    }
};