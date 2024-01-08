/*

Link : https://www.interviewbit.com/problems/maximum-level-sum/
Problem Description

Given a Binary Tree denoted by root node A having integer value on nodes. You need to find maximum sum level in it.



Problem Constraints
1 <= number of nodes <= 105

1 <= value on nodes <= 105



Input Format
First and only argument is a root node of Binary Tree A.



Output Format
Return an integer denoting the maximum sum level in the tree.



Example Input
Input 1:

 Tree:      4
          /   \
         2     5
        / \   / \
       1  3  2   6
Input 2:

 Tree:      1
          /   \
         2     3
       /  \     \
      4    5     8
                / \
               6   7  


Example Output
Output 1:

 12
Output 2:

 17

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


int Solution::solve(TreeNode* root) {
    int maxLevelSum = 0;
    
    if(root == NULL)
        return 0;
    
    queue<TreeNode*> q;
    q.push(root);
    
    int levelSum = 0;
    
    while(!q.empty())
    {
        int size = q.size();
        levelSum = 0;
        for(int i=0;i<size;i++)
        {
            TreeNode* node = q.front();
            q.pop();
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
            levelSum += node->val;
        }
        if(maxLevelSum < levelSum)
            maxLevelSum = levelSum;
    }
    return maxLevelSum;
    
}


