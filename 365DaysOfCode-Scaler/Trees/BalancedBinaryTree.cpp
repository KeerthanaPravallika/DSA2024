/* 

Link : https://www.interviewbit.com/problems/balanced-binary-tree/

Given a root of binary tree A, determine if it is height-balanced.

A height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

*/

/**
 * Definition for binary tree
 * class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) {
 *      val = x;
 *      left=null;
 *      right=null;
 *     }
 * }
 */
public class Solution {
    public int isBalanced(TreeNode root) {
        int lh; /* for height of left subtree */
 
        int rh; /* for height of right subtree */
 
        /* If tree is empty then return true */
        if (root == null)
            return 1;
 
        /* Get the height of left and right sub trees */
        lh = height(root.left);
        rh = height(root.right);
 
        if (Math.abs(lh - rh) <= 1 && isBalanced(root.left) == 1
            && isBalanced(root.right) == 1)
            return 1;
 
        /* If we reach here then tree is not height-balanced
         */
        return 0;
    }
     int height(TreeNode node)
    {
        /* base case tree is empty */
        if (node == null)
            return 0;
 
        /* If tree is not empty then height = 1 + max of
         left height and right heights */
        return 1
            + Math.max(height(node.left),
                       height(node.right));
    }
}
