#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1){
            return -1;
        }
        unordered_map<int, vector<int>> graph;
        for(const vector<int>& con : connections){
            graph[con[0]].push_back(con[1]);
            graph[con[1]].push_back(con[0]);
        }
        vector<int> unions(n);
        iota(unions.begin(), unions.end(), 0);
        vector<bool> is_visited(n, false);
        queue<int> q;
        
        for(int i = 0; i < n; ++i){
            if(!is_visited[i]){
                q.push(i);
                is_visited[i] = true;
                while(!q.empty()){
                    int cur = q.front();
                    q.pop();
                    for(int j = 0; j < graph[cur].size(); ++j){
                        if(!is_visited[graph[cur][j]]){
                            is_visited[graph[cur][j]] = true;
                            unions[graph[cur][j]] = unions[cur];
                            q.push(graph[cur][j]);
                        }
                    }
                }
            }
        }
        
        unordered_set<int> uniq(unions.begin(), unions.end());
        return uniq.size()-1;
    }
};

int main(){
    cout << "Test Initiated\n";
    Solution sol;
    vector<int> n_t = {
        6,
        7
    };

    vector<vector<vector<int>>> connections_t = {
        {{0,1},{0,2},{0,3},{1,2}},
        {{0,2},{1,3},{1,5},{0,7},{2,3}}
    };
    for(int i = 0; i < n_t.size(); ++i){
        cout << sol.makeConnected(n_t[i], connections_t[i]);
    }
    return 0;
}