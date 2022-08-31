class Solution {
public:
    void primt(vector<vector<int>>& matrix){
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i=0;i< row;i++){
            for(int j = 0 ;j< col ; j++){
                cout<< matrix[i][j]<< " ";
            }
            cout << endl;
        }
    }
    // solve fn 
    /* solve fn
    int solve(vector<vector<int>>& heights,vector<vector<bool>>& vis,int i,int j,vector<vector<int>>& ans,vector<vector<int>>& dp){
        int row = heights.size();
        int col = heights[0].size();
        if(i<0 || j<0) return 0;
        else if(i>=row || j>=col) return 1;
        else if(vis[i][j]) return dp[i][j];
        
        vis[i][j]=true;
        
        bool pac = false;
        bool atl = false;
        vector<int> hehe = {1,-1,0,0};
        vector<int> hue = {0,0,1,-1};
        for(int k=0;k<4;k++){
                cout<<"hehe:"<<i+hehe[k]<<"hue:"<<j+hue[k]<<endl;
                if(i+hehe[k] >= row || i+hehe[k]<0 || j+hue[k] < 0 || j+hue[k] >= col || (heights[i+hehe[k]][j+hue[k]] <= heights[i][j])){
                    int a;
                    // if(i+hehe[k] < row && i+hehe[k]>0 && j+hue[k] > 0 && j+hue[k] < col && vis[i+hehe[k]][j+hue[k]]){
                    //     a = dp[i+hehe[k]][j+hue[k]];
                    // }

                     a = solve(heights,vis,i+hehe[k],j+hue[k],ans,dp); 
                    cout<<i+hehe[k]<<" "<<j+hue[k]<<" -> "<<a<<endl;
                    if(a==0){
                        pac = true;
                    }
                    else if(a==1){
                        atl = true;
                    }
                    else if(a==3){
                        pac = true;
                        atl = true;
                    }
                    
                }
            
        }
        if(atl && pac){
           return dp[i][j]=3;
        }
        else if(pac){
            return dp[i][j]=0;
        }
        else {
            return dp[i][j]=1;
        }
        
    }
    
    */
    // main fn
    /*    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        
         vector<vector<bool>> vis(row,vector<bool>(col,false));
        vector<vector<int>> ans ;
        vector<vector<int>> dp(row,vector<int>(col,-1)) ;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!vis[i][j]) {
                    solve(heights,vis,i,j,ans,dp);
                }
            }
        }
        
        for(int i=0;i<row;i++){
            for(int j = 0;j<col ; j++){
                
                vector<int> temp;
                if(dp[i][j]==3){
                    temp.push_back(i);
                    temp.push_back(j);
                }
                if(temp.size()>0)
                         ans.push_back(temp);
            }
        }
        primt(dp);
        return ans;
    } 
    */
    void p_pac(vector<vector<int>>& heights,int i,int j,vector<vector<int>>& dp){
        int row = heights.size();
        int col = heights[0].size();
        if(i<0 || i>=row || j<0 || j>=col) return ;
        cout<<i<<" "<<j<<endl;
        if(dp[i][j]==1) return;
        dp[i][j]=1;
        vector<int> updn = {1,-1,0,0};
        vector<int> lr = {0,0,1,-1};
        
       for(int k=0;k<4;k++){
            if(i+updn[k]>=0 && i+updn[k]<row && j+lr[k]>=0 && j+lr[k]<col && heights[i+updn[k]][j+lr[k]]>=heights[i][j]){
                p_pac(heights,i+updn[k],j+lr[k],dp);
            }
        }
    }
    
    
    void p_atl(vector<vector<int>>& heights,int i,int j,vector<vector<int>>& dp){
        int row = heights.size();
        int col = heights[0].size();
        if(i<0 || i>=row || j<0 || j>=col) return ;
        if(dp[i][j]==2 || dp[i][j]==3) return;
        if(dp[i][j]==1){
            dp[i][j]=3;
        }else{
            dp[i][j]=2;
        }
         vector<int> updn = {1,-1,0,0};
        vector<int> lr = {0,0,1,-1};
        
        for(int k=0;k<4;k++){
            if(i+updn[k]>0 && i+updn[k]<row && j+lr[k]>0 && j+lr[k]<col && heights[i+updn[k]][j+lr[k]]>=heights[i][j]){
                p_atl(heights,i+updn[k],j+lr[k],dp);
            }
        }
        
        
    }
   
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int>> dpp(row,vector<int> (col,0));
        vector<vector<int>> dpa(row,vector<int> (col,0));
        
        // pacific
        for(int i=0;i<row;i++){
            p_pac(heights,i,0,dpp);
        }
        for(int i=0;i<col;i++){
            p_pac(heights,0,i,dpp);
        }
        primt(dpp);
        cout <<endl;
        //Atlantic 
        for(int i=row-1;i>=0;i--){
        
            p_pac(heights,i,col-1,dpa);
        }
        for(int i=col-1;i>=0;i--){
            p_pac(heights,row-1,i,dpa);
        }
                primt(dpa);

        // final 
        vector<vector<int>> ans;
        for(int i=0;i<row;i++){
            for(int j = 0;j<col ; j++){
                
                vector<int> temp;
                if(dpp[i][j]==1 &&dpa[i][j]==1){
                    temp.push_back(i);
                    temp.push_back(j);
                }
                if(temp.size()>0)
                         ans.push_back(temp);
            }
        }
        

        return ans;
        
        
    }
};