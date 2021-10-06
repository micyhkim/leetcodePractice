#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int length = 0;
        vector<bool> visited(nums.size(), false);
        
        for(int i = 0; i < nums.size(); ++i){
            int local_l = 0;
            int s = i;
            while(!visited[s]){
                visited[s] = true;
                s = nums[s];
                local_l++;
            }
            length = max(length, local_l);
        }
        return length;
    }
};

vector<int> vec ={5, 4, 0, 3, 1, 6, 2};

int main(int argc, char** argv){
    Solution sol;
    int x = sol.arrayNesting(vec);
    cout << "BP\n";
    return 0;
}