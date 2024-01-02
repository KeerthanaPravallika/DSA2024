/*

Link : https://www.interviewbit.com/problems/inorder-traversal/
Given a binary tree, return the inorder traversal of its nodes values.

NOTE: Using recursion is not allowed.

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


vector<int> Solution::inorderTraversal(TreeNode* root) {
    
    vector<int> inorderTraversals;
    
    stack<TreeNode*> s;
    TreeNode* curr = root;
 
    while (curr != NULL || s.empty() == false) {
         
        // left subtree
        while (curr != NULL) {
             
            s.push(curr);
            curr = curr->left;
        }
 
        // root node
        curr = s.top();
        s.pop();
 
        inorderTraversals.push_back(curr->val);
 
        // right subtree
        curr = curr->right;
 
    }
    
    return inorderTraversals;
    
}
