/* 

Link : https://www.interviewbit.com/problems/symmetric-binary-tree/
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).


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
    boolean isMirror(TreeNode node1, TreeNode node2)
    {
        // if both trees are empty, then they are mirror image
        if (node1 == null && node2 == null)
            return true;
 
        if (node1 != null && node2 != null
            && node1.val == node2.val)
            return (isMirror(node1.left, node2.right)
                    && isMirror(node1.right, node2.left));
 

        return false;
    }
    
    public int isSymmetric(TreeNode A) {
        if(isMirror(A, A))
            return 1;
        return 0;
    }
}
