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
        
        // O(sqrt(n)) cases using math
        // Init divisor array
        vector<int> sub;
        int rooted = (int) sqrt(n);
        // Iterate over 1 - sqrt(n), decrement k, if k reaches 0, that is kth factor
        for(int i = 1; i <= rooted; ++i){
            if(n % i == 0){
                sub.push_back(i);
                k--;
                if(k == 0){
                    return i;
                }
            }
        }
        // In case of n is perfect square we need to ignore the duplicate after divisor length 
        if(rooted * rooted == n){
            k += 1;
        }
        
        if(k > sub.size()){
            return -1;
        }
        else{
        // Return answer for k greater than sub.size by dividing the element by n
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