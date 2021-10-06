#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

////***********************TreeNode Definition*********************** 
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode * right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) 
        : val(x), left(left), right(right) {}
};

//******************************************************************************

int null = 0xf0000000;

//***********************Helper Functions to create input files***********************
TreeNode* fromvec(vector<int>& vec){
    if(vec.size() == 0){
        return nullptr;
    }

    TreeNode* root = new TreeNode(vec[0]);
    queue<TreeNode*> q;
    q.push(root);
    for(int i = 1; i < vec.size(); ++i){
        TreeNode* cur = q.front();
        if(!cur -> left){
            cur -> left = new TreeNode(vec[i]);
            if(vec[i] != null){
                q.push(cur -> left);
            }
        }
        else if(!cur -> right){
            cur -> right = new TreeNode(vec[i]);
            if(vec[i] != null){
                q.push(cur -> right);
            }
            q.pop();
        }
    }
    return root;
}

TreeNode* trim_null(TreeNode* root){
    if(!root){
        return root;
    }
    else if(root -> val == null){
        delete root;
        return nullptr;
    }
    else{
        root -> left = trim_null(root -> left);
        root -> right = trim_null(root -> right);
        return root;
    }
}

//******************************************************************************


//*******************************The actual solution*******************************

class Solution {
    private:
        TreeNode *lo;
        TreeNode *hi;
        int prev = null;

    public:
        void recoverTree(TreeNode* root){
            inorder_l(root);
            prev = null;
            inorder_r(root);
            int tmp = lo -> val;
            lo -> val = hi -> val;
            hi -> val = tmp;
        }

        void inorder_l(TreeNode* root){
            if(!root){
                return;
            }
            else{
                inorder_l(root -> left);
                if(prev != null && root -> val < prev){
                    lo = root;
                }
                prev = root -> val;
                inorder_l(root -> right);
            }
        }

        void inorder_r(TreeNode* root){
            if(!root){
                return;
            }
            else{
                inorder_r(root -> right);
                if(prev != null && root -> val > prev){
                    hi = root;
                }
                prev = root -> val;
                inorder_r(root -> left);
            }
        }
};
//*******************************The actual solution_End*******************************


vector<int> exam_vec = {3,1,4,null,null,2};

int main(int argc, char** argv){
    
    TreeNode* root = fromvec(exam_vec);
    trim_null(root);
    Solution sol;
    sol.recoverTree(root);

    cout << "Done!\n";
    return 0;

}