### Invert Binary Tree
[Ques](https://leetcode.com/problems/invert-binary-tree/description/)

Given the root of a binary tree, invert the tree, and return its root.

Example 1:
```
Input: root = [4,2,7,1,3,6,9]
   4   
  / \  
 2   7 
/ \ / \
1 3 6 9
Output: [4,7,2,9,6,3,1]
   4   
  / \  
 7   2 
/ \ / \
9 6 3 1
```
Example 2:
```
Input: root = [2,1,3]
Output: [2,3,1]
````
Example 3:
```
Input: root = []
Output: []
``` 

Constraints:
```
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
```

### Solution: 
Java:

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
    //Iterative
    public TreeNode invertTree(TreeNode root) {
        Queue<TreeNode> bfs = new LinkedList<>();
        bfs.add(root);
        TreeNode currNode = root;

        //While bfs not finished
        while(!bfs.isEmpty()){
            if(currNode!=null){
                //Add children to queue
                bfs.add(currNode.left);
                bfs.add(currNode.right);

                //Swap left and right
                TreeNode temp = currNode.left;
                currNode.left = currNode.right;
                currNode.right = temp;
            }

            //Remove curr node from queue and make next node in bfs as current
            bfs.remove();
            currNode = bfs.peek();
        }

        return root;
    }
```

```java
    //Recursive
    public TreeNode invertTree(TreeNode root) {
        //Base case if current root node is null
        if(root == null) return root;

        //Save current nodes left and right and invert tree for them
        TreeNode left = root.left;
        TreeNode right = root.right;

        left = invertTree(left);
        right = invertTree(right);

        //Now switch left and right for current node
        root.left = right;
        root.right = left;
        
        return root;
    }
}
```

### Approach
- Recursion: call invert tree for left, for right, then swap left right for current node. base case when curr reaches null.
- Iterative: Use queue to traverse, first add left and right of curr to queue, then swap current's left and right, then remove curr from queue and loop for children.

Case to consider: 
```
Input: [3,null,1,2]  
3  
 \ 
  1
 / 
 2
Output: [3,1,null,null,2] 
  3
 / 
1  
 \ 
 2
 ```
 null can come in queue, so null check added.
 
 
`Time Complexity: O(n)` |
`Space Complexity: O(n)`
