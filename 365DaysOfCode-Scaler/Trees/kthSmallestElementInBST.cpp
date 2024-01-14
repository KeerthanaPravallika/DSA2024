/* 
Link : https://www.interviewbit.com/problems/kth-smallest-element-in-tree/

Given a binary search tree, write a function to find the kth smallest element in the tree.
NOTE: You may assume 1 <= k <= Total number of nodes in BST

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
 
void inorder(TreeNode* root, int &count, int &ans, int k){
        if(root == NULL)    return;
        //left, root, right 
        inorder(root->left, count, ans, k);
        count++;
        if(count == k){
            ans = root->val;
            return;
        }
        inorder(root->right, count, ans, k);
    }
    
int Solution::kthsmallest(TreeNode* root, int k) {
    int count = 0;        
        int ans;
        inorder(root, count, ans, k);
        return ans;
}
