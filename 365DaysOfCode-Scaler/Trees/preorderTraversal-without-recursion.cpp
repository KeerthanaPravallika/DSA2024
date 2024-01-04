/*

Link : https://www.interviewbit.com/problems/preorder-traversal/

Given a binary tree, return the preorder traversal of its nodes’ values.

Example :

Given binary tree

   1
    \
     2
    /
   3
return [1,2,3].

Using recursion is not allowed.

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
vector<int> Solution::preorderTraversal(TreeNode* A) {
    
    vector<int> preorderData;
    if(A == NULL)
        return preorderData;
    
    stack<TreeNode*> st;
    st.push(A);
    
    while(!st.empty())
    {
        A = st.top();
        st.pop();
        preorderData.push_back(A->val);
        
        if(A->right != NULL)
            st.push(A->right);
        if(A->left != NULL)
            st.push(A->left);
    }
    
    return preorderData;
}
