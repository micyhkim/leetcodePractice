#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int kthFactor(int n, int k) {
        /*
        The brute force O(N) approaches
        
        vector<int> sub;
        for(int i = 1; i <=n; ++i){
            if(n % i == 0){
                sub.push_back(i);
            }
        }
        return sub.size() < k ? -1 : sub[k-1];
        */
        
        vector<int> sub;
        int rooted = (int) sqrt(n);
        for(int i = 1; i <= rooted; ++i){
            if(n % i == 0){
                sub.push_back(i);
                k--;
                if(k == 0){
                    return i;
                }
            }
        }
        
        if(rooted * rooted == n){
            k += 1;
        }
        
        if(k > sub.size()){
            return -1;
        }
        else{
            return n/sub[sub.size()-k];
        }      
    }
};

int main(){
    cout << "Test Initiated\n";
    // t1: regular cases
    Solution sol;
    vector<int> t_set1 = {15, 34, 87, 111, 654, 150, 976};
    vector<int> t_k1 = {2, 3, 2, 5, 3, 4, 2};
    for(int i = 0; i < t_set1.size(); ++i){
        cout << sol.kthFactor(t_set1[i], t_k1[i]);
    }

    cout << sol.kthFactor(9, 3);
    cout << sol.kthFactor(36, 6);
    return 0;
}