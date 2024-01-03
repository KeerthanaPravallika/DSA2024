/* 

Link : https://www.interviewbit.com/problems/postorder-traversal/
Given a binary tree, return the Postorder traversal of its nodes values.

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

vector<int> Solution::postorderTraversal(TreeNode* root) {
    
    vector<int> postorderTraversalData;
    
    if(root == NULL)
        return postorderTraversalData;    
    
    stack<TreeNode*> s1,s2;
    
    s1.push(root);
    
    while(!s1.empty())
    {
        root = s1.top();
        s1.pop();
        s2.push(root);
        
        if(root->left != NULL)
            s1.push(root->left);
        
        if(root->right != NULL)
            s1.push(root->right);
        
    }
    
    while(!s2.empty())
    {
        postorderTraversalData.push_back(s2.top()->val);
        s2.pop();
    }
    
    
    return postorderTraversalData;
}
