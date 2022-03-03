#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int ind = 0;
        bool contains_dot = false;
        bool met_digit = false;
        // Iterate until 'E' or 'e'.
        while(ind < s.size()){
            if(s[ind] < '0' || s[ind] > '9'){
                // case handling: 'E' or 'e'
                if(s[ind] == 'E' || s[ind] == 'e'){
                    // if we didn't see any digit or there is no more digit after e => false
                    if(ind == 0 || ind == s.size()-1 || !met_digit){
                        return false;
                    }
                    // We want to end the before-'E' part
                    break;
                }
                // Case handle 2: '.'
                else if(s[ind] == '.'){
                    // If there is already a dot, false
                    if(contains_dot){
                        return false;
                    }
                    else{
                        if(
                        /* If there is no digit in front of the dot and
                         * No digit after the dot, false*/
                            !((ind > 0 && (s[ind-1] >= '0' && s[ind-1] <= '9')) ||
                            (ind != s.size()-1 && (s[ind+1] >= '0' && s[ind+1] <= '9')))
                        ){
                            return false;
                        }
                        contains_dot = true;
                    }
                }
                // case handle 3: signs
                else if(s[ind] == '+' || s[ind] == '-'){
                    // Signs must come very first
                    if(ind != 0){
                        return false;
                    }
                }
                // case handle 4: other chars
                else{
                    return false;
                }
            }
            else{
                // indicate there is digit
                met_digit = true;
            }
            ind++;
        }
        
        ind++;
        // the start point of the portion after 'e' and 'E'
        int after_E_starts = ind;
        while(ind < s.size()){
            // case handle 1 : signs
            if(s[ind] == '-' || s[ind] == '+'){
                // the sign must come first of everything and cannot be the last character for the string
                if(ind != after_E_starts || ind == s.size()-1){
                    return false;
                }
            }
            else if(s[ind] < '0' || s[ind] > '9'){
                // If not digit, we return false
                return false;
            }
            ind++;
        }    
        return true;
    }
};


int main(){
    // test cases
    vector<string> s1 = {"2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"};
    Solution sol;
    for(string& s : s1){
        if(!sol.isNumber(s)){
            cout << "Wrong string case: " << s << endl;
        }
    }
    // wrong valid test cases
    vector<string> s2 = {"abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"};
    for(string& s: s2){
        if(sol.isNumber(s)){
            cout << "Wrong string case: " << s << endl;
        }
    }

    if(sol.isNumber(".")){
        cout << "Wrong string case: ." << endl;
    }

    if(sol.isNumber(".e")){
        cout << "Wrong string case: .e" << endl;
    }
    
    vector<string> edges_wrong = {"4e+, +E3"};
    for(string& s : edges_wrong){
        if(sol.isNumber(s)){
            cout << "Wrong string case: " << s << endl;
        }
    }

}