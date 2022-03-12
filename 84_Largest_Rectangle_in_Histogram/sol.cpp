#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        int max_area = 0;
        for(int i = 0; i < heights.size(); ++i){
            // We want strictly increasing stack
            while(st.top() != -1 && heights[st.top()] >= heights[i]){
                int back_idx = st.top();
                st.pop();
                // calculation of area = height of index * (current position - previous position(height smaller than now) - 1)
                int cur_area = heights[back_idx] * (i - (st.top()) - 1);
                max_area = max(cur_area, max_area);
            }
            st.push(i);
        }

        while(st.top() != -1){
            int back_idx = st.top();
            st.pop();
            int cur_area = heights[back_idx] * (heights.size() - st.top() - 1);
            max_area = max(cur_area, max_area);
        }

        return max_area;
    }
};

int main(){
    cout << "Test Initiated\n";
    Solution sol;

    // Testing example 1
    vector<int> height_t1 = {2,1,5,6,2,3};
    if(sol.largestRectangleArea(height_t1) != 10){
        cout << "Testcase 1 failed\n";
    }

    // Testing incremental
    vector<int> height_t2 = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    if(sol.largestRectangleArea(height_t2) != 64){
        cout << "Testcase 2 failed\n";
    }
}