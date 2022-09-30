
// My solution TLE 



/*template<typename T>
class custom_priority_queue : public std::priority_queue<T, std::vector<T>>
{
  public:

      bool remove(const T& value) {
          auto it = std::find(this->c.begin(), this->c.end(), value);
       
          if (it == this->c.end()) {
              return false;
          }
          if (it == this->c.begin()) {
              // deque the top element
              this->pop();
          }    
          else {
              // remove element and re-heap
              this->c.erase(it);
              std::make_heap(this->c.begin(), this->c.end(), this->comp);
         }
         return true;
     }
};
class comparator{
public:
    bool operator()(vector<int>& v1,vector<int>& v2){
        if(v1[0]>v2[0]) return true;
        else if(v1[0]==v2[0] && v1[1]<=v2[1]) return true;
        return false;
    }
};*/
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
//         vector<pair<int,int>> vec;
//         for(int i=0;i<buildings.size();i++){
//             vec.push_back({buildings[i][0],-buildings[i][2]});
//             vec.push_back({buildings[i][1],buildings[i][2]});
//         }
//         sort(vec.begin(),vec.end());
//         custom_priority_queue<int> pq;
//         int curr_height = 0;
//         pq.push(0);
//         vector<vector<int>> ans;
//         for(int i=0;i<vec.size();i++){
//             int x = vec[i].first;
//             int h = vec[i].second;
            
//             if(h<0){
//                 pq.push(-h);
//             }
//             else{
//                 pq.remove(h);
//             }
            
//             if(curr_height != pq.top()){
//                 vector<int> temp;
//                 temp.push_back(x);;
//                 temp.push_back(pq.top());
//                 ans.push_back(temp);
//                 curr_height = pq.top();
//             }
//         }
        
//         return ans;
        
         // use walls to record buildings; left wall is an insertion event, and right wall is a deletion event
        vector<pair<int, int>> walls, ans;                  // first: x, second: height
        for (auto b : buildings) {
            // push in left / right walls
            // let left wall has negative height to ensure left wall goes to multiset first if with same 'x' as right wall
            walls.push_back(make_pair(b[0], -b[2]));
            walls.push_back(make_pair(b[1], b[2]));
        }
        sort(walls.begin(), walls.end());                   // sort walls
        
        multiset<int> leftWallHeights = {0};                // keep left wall heights sorted; dummy '0' for convenience
        int top = 0;                                        // current max height among leftWallHeights
        for (auto w : walls) {
            if (w.second < 0) {                             // it's a left wall, insert the height
                leftWallHeights.insert(-w.second);
            } else {                                        // it's a right wall, delete the height
                leftWallHeights.erase(leftWallHeights.find(w.second));
            }
            
            if (*leftWallHeights.rbegin() != top) {         // mark a skyline point if top changes
                ans.push_back(make_pair(w.first, top = *leftWallHeights.rbegin()));
            }
        }
        
        // return ans;
        vector<vector<int>> result;
        for(int i=0;i<ans.size();i++){
            vector<int> temp;
            temp.push_back(ans[i].first);
            temp.push_back(ans[i].second);
            result.push_back(temp);
        }
        return result;
        
        
    }
};