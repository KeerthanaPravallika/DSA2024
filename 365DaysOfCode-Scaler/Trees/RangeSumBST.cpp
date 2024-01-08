/* 

Link : https://leetcode.com/problems/range-sum-of-bst/
Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

 

Example 1:


Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.

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
    int rangeSumBST(TreeNode* root, int low, int high) {

        int sum = 0;
    
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
    
            if(curr->val >= low && curr->val  <= high)
                sum += curr->val;
    
            // right subtree
            curr = curr->right;
 
        }

        return sum;
    }
};
