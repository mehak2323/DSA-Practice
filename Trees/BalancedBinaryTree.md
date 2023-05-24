## Balanced Binary Tree
[Leetcode](https://leetcode.com/problems/balanced-binary-tree/)

Given a binary tree, determine if it is height-balanced.
A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

Example 1:
```
Input: root = [3,9,20,null,null,15,7]
Output: true
  3      
 / \     
9    20  
    /  \ 
   15   7
```
Example 2:
```
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
      1  
     / \ 
   2    2
  / \    
 3   3   
/ \      
4 4 
```
Example 3:
```
Input: root = []
Output: true
```
Constraints:
```
The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104
```

## Solution
```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

    private int getHeight(TreeNode root){
        //If curr node is null, return 0 height
        if(root==null) return 0;

        //Else return 1 for curr node and max height from left and right subtree
        return 1 + Math.max (getHeight(root.left), getHeight(root.right));
    }  

    public boolean isBalanced(TreeNode root) {
        //If root null, tree balanced
        if(root==null) return true;
        
        //Find abs diff of left and right subtree height
        int diff = Math.abs( getHeight(root.left) - getHeight(root.right) );

        if(diff>=2 || !isBalanced(root.left) || !isBalanced(root.right)) 
            return false;
        return true;
    }

    //Eg to consider: [1,2,2,3,null,null,3,4,null,null,4]
}
```
Another botton up recursion in editorial:
```java
// Utility class to store information from recursive calls
final class TreeInfo {
  public final int height;
  public final boolean balanced;

  public TreeInfo(int height, boolean balanced) {
    this.height = height;
    this.balanced = balanced;
  }
}

class Solution {
  // Return whether or not the tree at root is balanced while also storing
  // the tree's height in a reference variable.
  private TreeInfo isBalancedTreeHelper(TreeNode root) {
    // An empty tree is balanced and has height = -1
    if (root == null) {
      return new TreeInfo(-1, true);
    }

    // Check subtrees to see if they are balanced.
    TreeInfo left = isBalancedTreeHelper(root.left);
    if (!left.balanced) {
      return new TreeInfo(-1, false);
    }
    TreeInfo right = isBalancedTreeHelper(root.right);
    if (!right.balanced) {
      return new TreeInfo(-1, false);
    }

    // Use the height obtained from the recursive calls to
    // determine if the current node is also balanced.
    if (Math.abs(left.height - right.height) < 2) {
      return new TreeInfo(Math.max(left.height, right.height) + 1, true);
    }
    return new TreeInfo(-1, false);
  }

  public boolean isBalanced(TreeNode root) {
    return isBalancedTreeHelper(root).balanced;
  }
};
```

## Approach
- getHeight(left)-getHeight(right)<=2 && isBalanced(left) && isBalanced(right)

- `Time Complexity: O(n logn)` log n to find height for each node
- `Space Complexity: O(n) ` recursion stack
