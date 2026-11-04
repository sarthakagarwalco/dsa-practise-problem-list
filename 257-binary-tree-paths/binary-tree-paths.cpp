#include <vector>
#include <string>

using namespace std;

class Solution {
    void dfs(TreeNode* node, string path, vector<string>& res) {
        if (!node) return;
        
        path += to_string(node->val);
        
        if (!node->left && !node->right) {
            res.push_back(path);
            return;
        }
        
        path += "->";
        dfs(node->left, path, res);
        dfs(node->right, path, res);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(root, "", res);
        return res;
    }
};