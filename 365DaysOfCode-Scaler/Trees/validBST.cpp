/*

Link : https://www.interviewbit.com/problems/valid-binary-search-tree/
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node’s key.
The right subtree of a node contains only nodes with keys greater than the node’s key.
Both the left and right subtrees must also be binary search trees.

*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 bool isValid(TreeNode* root, long minVal, long maxVal) {
        if (root == nullptr) {
            // Base case: an empty
            // tree is a valid BST
            return true; 
        }
        
        // Checks if the current node
        // violates the BST property
        if (root->val >= maxVal || root->val <= minVal) {
            return false; 
        }

        // Recursively checks left and right
        // subtrees with updated constraints
        // that every value on its left subtree
        // should be smaller than the current node
        // and every value on its right subtree
        // should be greater than the current node
        return isValid(root->left, minVal, root->val)
                && isValid(root->right, root->val, maxVal);
    }
    
    
int Solution::isValidBST(TreeNode* root) {
    if(isValid(root, INT_MIN, INT_MAX))
        return 1;
    return 0;
        
}
