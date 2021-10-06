#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



class Solution{
    private:
        vector<TreeNode*> helper(int s, int e){
            vector<TreeNode*> vec;
            if(s > e){
                return { nullptr };
            }
            for(int i = s; i <= e; ++i){
                // Find all left trees => [s, i-1)
                for(TreeNode* l : helper(s, i-1)){
                    // Find all right trees => [i + 1, e)
                    for(TreeNode* r : helper(i + 1, e)){
                        vec.push_back(new TreeNode(i, l, r));
                    }
                }
            }
            return vec;
        }


    public:
        vector<TreeNode*> generateTrees(int n) {
            return helper(1, n);
        }
        
};


// Input!
int input = 3;

int main(int argc, char** argv){

    Solution sol;
    vector<TreeNode*> eqeq = sol.generateTrees(3);



    cout << "BP\n";
    return 0;
}