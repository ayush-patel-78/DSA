/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        
        // cout<<customfunction.f(1,4)<<endl;
         vector<vector<int>> hue;
        for(int i=1;i<=1000;i++){
            vector<int> hehe;
            for(int j=1;j<=1000;j++){
                if(customfunction.f(i,j)==z){
                    hehe.push_back(i);
                    hehe.push_back(j);
                }
            }
            if(hehe.size()>0) hue.push_back(hehe);
 
        }
        return hue;
    }
};