#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
private:
    
    void prepare(string& s){
        //iterate through string and record the frequency
        for(char s_i : s){
            m[s_i]++;
        }
        is_existing = vector<bool>(s.size() + 1, false);
    }
    unordered_map<char, int> m;
    vector<bool> is_existing;
public:
    int minDeletions(string s) {
        int sol = 0;
        prepare(s);
        /*
        Algorithm:
            1. Iterate unique characters and get frequency
            2. If we encounter any existing frequency, we decrease until we don't have anything matching (increase the deletion)
            3. Mark down the new frequency is occupied
            3-1. If frequency is zero, we don't want to because the character is deleted.
        */
        for(auto s_i : m){
            int freq = s_i.second;
            if(!is_existing[freq]){
                is_existing[freq] = true;
                continue;
            }
            while(is_existing[freq] && freq != 0){
                freq--;
                sol += 1;
            }
            if(freq != 0){
                is_existing[freq] = true;
            }
        }
        
        
        return sol;
    }
};

int main(){
    Solution sol;
    cout << sol.minDeletions("aabb") << endl;
    return 0;
}
