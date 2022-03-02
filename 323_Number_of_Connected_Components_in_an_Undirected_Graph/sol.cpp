#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> is_visited(n, false);
        unordered_map<int, vector<int>> graph;
        // build the relationship based on nodes
        for(int i = 0; i < edges.size(); ++i){
            vector<int>& cur_relation = edges[i];
            graph[cur_relation[0]].push_back(cur_relation[1]);
            graph[cur_relation[1]].push_back(cur_relation[0]);
        }
        queue<int> q;
        int ret = 0;
        for(int i = 0; i < n; ++i){
            if(is_visited[i]){
                continue;
            }
            q.push(i);
            is_visited[i] = true;
            // dfs approach to find the union
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                vector<int>& adj = graph[cur];
                for(int j = 0; j < adj.size(); ++j){
                    if(!is_visited[adj[j]]){
                        q.push(adj[j]);
                        is_visited[adj[j]] = true;
                    }
                }
            }
            ret += 1;
        }
        return ret;
    }
};

int main(){

    Solution sol;
    int n1 = 5;
    vector<vector<int>> edges1 = {{0,1},{1,2},{2,3},{3,4}};
    cout << sol.countComponents(n1, edges1) << "\n";

    int n2 = 5;
    vector<vector<int>> edges2 = {{0,1},{1,2},{3,4}};
    cout << sol.countComponents(n2, edges2) << "\n";


    return 0;
}