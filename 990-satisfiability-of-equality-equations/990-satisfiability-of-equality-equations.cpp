class Solution {
public:
    int find_par(int x,vector<int>& parent){
        if(parent[x]==x) return x;
        return parent[x]=find_par(parent[x],parent);
    }
    void union_eqn(int x,int y,vector<int>& parent,vector<int>& rank){
        int px = find_par(x,parent);
        int py = find_par(y,parent);
        
        if(rank[px] > rank[py]){
            parent[py]=parent[px];
        }
        else if(rank[px] < rank[py]){
            parent[px]=parent[py];
        }
        else{
            parent[py]=parent[px];
            rank[px]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26);
        vector<int> rank(26,0);
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        for(string eqn:equations){
            if(eqn[1]=='='){
                union_eqn(eqn[0]-'a',eqn[3]-'a',parent,rank);
            }
        }
        for(string eqn:equations){
            if(eqn[1]=='!'){
                int px = find_par(eqn[0]-'a',parent);
                int py = find_par(eqn[3]-'a',parent);
                if(px == py) return false;
            }
        }
        return true;
        
    }
};