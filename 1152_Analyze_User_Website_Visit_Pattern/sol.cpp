#include <bits/stdc++.h>

using namespace std;

struct Elem{
    string username;
    string website;
    int timestamp;
    Elem(){}
    Elem(string& _username, string& _website, int _timestamp):
        username(_username), website(_website), timestamp(_timestamp){}
};

struct Comp{
    bool operator()(const Elem& lhs, const Elem& rhs){
        return lhs.timestamp < rhs.timestamp;
    }
};

class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        //1. Sort tuples in timestamp
        //2. User : list of website
        //3. Check all patterns of user and increase the counter.
        int n = username.size();
        vector<Elem> combined;
        combined.reserve(n);
        for(int i = 0; i < n; ++i){
            combined.push_back(Elem(username[i], website[i], timestamp[i]));
        }

        Comp comp;
        sort(combined.begin(), combined.end(), comp);
        unordered_map<string, vector<string>> user_record;
        for(const Elem& e : combined){
            user_record[e.username].push_back(e.website);
        }

        unordered_map<string, unordered_map<string, unordered_map<string, unordered_set<string>>>> count;
        for(const auto& it : user_record){
            for(int i = 0; i < it.second.size(); ++i){
                for(int j = i+1; j < it.second.size(); ++j){
                    for(int k = j+1; k < it.second.size(); ++k){
                        count[it.second[i]][it.second[j]][it.second[k]].insert(it.first);
                    }
                }
            }
        }

        set<string> website_sorted(website.begin(), website.end());
        int max_c = 0;
        vector<string> ret;
        for(const string& a : website_sorted){
            for(const string& b : website_sorted){
                for(const string& c : website_sorted){
                    int loc = count[a][b][c].size();
                    if(loc > max_c){
                        max_c = loc;
                        ret = {a, b, c};
                    }
                }
            }
        }
        
        return ret;
    }
};

int main(){
    cout << "Test Initiated\n";
    Solution sol;
    vector<string> username_t1 = {"joe","joe","joe","james","james","james","james","mary","mary","mary"};
    vector<int> timestamp_t1 = {1,2,3,4,5,6,7,8,9,10};
    vector<string> website_t1 = {"home","about","career","home","cart","maps","home","home","about","career"};
    vector<string> exprected_res1 = {"about","home","career"};
    vector<string> res1 = sol.mostVisitedPattern(username_t1, timestamp_t1, website_t1);
    for(int i = 0 ; i < res1.size(); ++i){
        cout << res1[i] << endl;
    }

    vector<string> username_t2 = {"h","eiy","cq","h","cq","txldsscx","cq","txldsscx","h","cq","cq"};
    vector<int> timestamp_t2 = {527896567,334462937,517687281,134127993,859112386,159548699,51100299,444082139,926837079,317455832,411747930};
    vector<string> website_t2 = {"hibympufi","hibympufi","hibympufi","hibympufi","hibympufi","hibympufi","hibympufi","hibympufi","yljmntrclw","hibympufi","yljmntrclw"};
    vector<string> res2 = sol.mostVisitedPattern(username_t2, timestamp_t2, website_t2);
    for(string& s : res2){
        cout << s << endl;
    }


    return 0;
}