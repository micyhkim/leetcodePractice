#include <bits/stdc++.h>

using namespace std;

struct Elem{
    int val;
    int id;
    int ind;
    Elem(int _val, int _id, int _ind): val(_val), id(_id), ind(_ind) {}
};

struct Comp{
    bool operator()(const Elem& lhs, const Elem& rhs) const{
        return lhs.val > rhs.val;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Elem, vector<Elem>, Comp> pq;
        int cur_min_range = INT_MAX;
        // Initialize the pq with the first element in K lists
        int cur_max = INT_MIN;
        for(int i = 0; i < nums.size(); ++i){
            cur_max = max(cur_max, nums[i][0]);
            pq.push(Elem(nums[i][0], i, 0));
        }

        vector<int> ret = {pq.top().val, cur_max};
        while(true){
            const Elem& top = pq.top();
            int id = top.id;
            int ind = top.ind;
            int cur = top.val;
            pq.pop();
            // Check the new range to update the min range if possible
            if(cur_min_range > cur_max - cur){
                ret[0] = cur;
                ret[1] = cur_max;
                cur_min_range = cur_max - cur;
            }
            // End point when we can't increase the lower bound anymore
            if(ind+1 > nums[id].size()-1){
                break;
            }
            
            int next = nums[id][ind+1];
            cur_max = max(cur_max, next);
            pq.push(Elem(next, id, ind+1));
        }
        return ret;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> t1 = {{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
    vector<int> sol1 = sol.smallestRange(t1);
    cout << "Range is: " << sol1[0] << " - " << sol1[1] << endl;

    return 0;
}