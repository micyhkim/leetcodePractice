#include <bits/stdc++.h>

using namespace std;

class Solution {
private:

    // This creates graph that relates prerequisites to the next connected course and how many prerequisites that next courses have
   void createGraph(vector<vector<int>>& relations, vector<vector<int>>& graph, vector<int>& inNodes){
       for(int i = 0; i < relations.size(); ++i){
           int from = relations[i][0];
           int to = relations[i][1];
           graph[from].push_back(to);
           inNodes[to] += 1;
       }
   }

    bool validation(vector<int>& inNodes){
        for(int i = 0; i < inNodes.size(); ++i){
            if(inNodes[i] > 0){
                return false;
            }
        }
        return true;
    }

public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> graph(n+1);
        vector<int> inNodes(n+1, 0);
        //vector<bool> is_checked(n, false);
        createGraph(relations, graph, inNodes);

        vector<int> q;
        for(int i = 1; i < inNodes.size(); ++i){
            if(inNodes[i] == 0){
                q.push_back(i);
            }
        }
        int res = 0;
        // Perform search algorithm over the elements inside the queue rn
        while(!q.empty()){
            res += 1;
            // Since we want to get the next courses in semester
            vector<int> next_q;
            // We iterate through all nodes in the queue
            for(int cur : q){
                for(int i = 0; i < graph[cur].size(); ++i){
                    inNodes[graph[cur][i]] -= 1;
                    // We put the node that doesn't have any innodes (we took the prerequisite)
                    if(inNodes[graph[cur][i]] == 0){
                        next_q.push_back(graph[cur][i]);
                    }
                }
            }
            q = next_q;
        }
        return validation(inNodes) ? res : -1;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> relation_test1 = {
        {0,1},
        {1,2},
        {1,3},
        {2,5},
        {3,5},
        {4,3},
        {6,7},
        {7,8}
    };
    int n_1 = 9;
    int res1 = sol.minimumSemesters(n_1, relation_test1);
    if(res1 != 4){
        cout << "Wrong answer expected: " << 4 << " but got " << res1 << "\n";
    }
    return 0;

}