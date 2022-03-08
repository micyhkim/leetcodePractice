#include <bits/stdc++.h>

using namespace std;

struct Elem{
    int nle;
    int ple; 
    int nge; 
    int pge; 

    Elem():
        nle(0), ple(0), nge(0), pge(0){}
};

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        // O(n) solution : Motivation is to calculate the contribution of each values in the subarrays
        vector<Elem> contribs(nums.size());
        for(int i = 0; i < nums.size(); ++i){
            contribs[i].nle = nums.size();
            contribs[i].nge = nums.size();
            contribs[i].ple = -1;
            contribs[i].pge = -1;
        }

        stack<int> st_l;
        long long res = 0;
        for(int i = 0; i < nums.size(); ++i){
            while(!st_l.empty() && nums[st_l.top()] >= nums[i]){
                contribs[st_l.top()].nle = i;
                st_l.pop();
            }
            if(st_l.empty()){
                contribs[i].ple = -1;
            }
            else{
                contribs[i].ple = st_l.top();
            }
            st_l.push(i);
        }
        stack<int> st_g;
        for(int i = 0; i < nums.size(); ++i){
            while(!st_g.empty() && nums[st_g.top()] <= nums[i]){
                contribs[st_g.top()].nge = i;
                st_g.pop();
            }

            if(st_g.empty()){
                contribs[i].pge = -1;
            }
            else{
                contribs[i].pge = st_g.top();
            }
            st_g.push(i);
        }

        for(int i = 0; i < nums.size(); ++i){
            long long leftminCount = i - contribs[i].ple;
            long long righminCount = contribs[i].nle - i;
            long long leftgCount = i - contribs[i].pge;
            long long rightgCount = contribs[i].nge - i;

            res += (long long)nums[i] * ((rightgCount * leftgCount) - (leftminCount * righminCount));
        }

        return res;
    }
};

int main(){
    Solution sol;

    cout << "Test Initiated\n";
    vector<vector<int>> tests{
        {1,2,3,4},
        {2,5,1,4,7,4,2,3},
        {9,8,7},
        {1,2,2,3}
    };

    vector<long long> sols{
        10,
        128,
        4,
        6
    };

    for(int i = 0; i < tests.size(); ++i){
        long long ou = sol.subArrayRanges(tests[i]);
        if(ou != sols[i]){
            cout << "Test case " << i << " failed. Expected: " << sols[i] << " but got " << ou << "\n";
        }
    }

    return 0;
}