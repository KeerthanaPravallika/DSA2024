/* 
Problem Description

Given a binary tree, return the reverse level order traversal of its nodes values. (i.e, from left to right and from last level to starting level).

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
vector<int> Solution::solve(TreeNode* root) {
    
    vector<int> res;
    if(root == NULL){
            return res;
        }
        queue<TreeNode*> q ;
        stack<TreeNode*> s;
        
        q.push(root);
        while(!q.empty()){
            root = q.front();
            q.pop();
            if(root->right != NULL){
                q.push(root->right);
            }
            if(root->left != NULL){
                q.push(root->left);
            }
            s.push(root);
        }
        while(!s.empty()){
            root = s.top();
            res.push_back(root->val);
            s.pop();
        }
    return res;
}
