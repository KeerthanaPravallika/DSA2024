/*
Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.



For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

 

Example 1:


Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
Output: true


*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void findLeaf_dfs(TreeNode* nodeNow, std::vector<int>& nodeList) {
        if (!nodeNow) {
            return;
        }

        if (!nodeNow->left && !nodeNow->right) {
            nodeList.push_back(nodeNow->val);
            return;
        }

        findLeaf_dfs(nodeNow->left, nodeList);
        findLeaf_dfs(nodeNow->right, nodeList);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> nodeList_root1, nodeList_root2;
        findLeaf_dfs(root1, nodeList_root1);
        findLeaf_dfs(root2, nodeList_root2);
        return nodeList_root1 == nodeList_root2;
    }
};
