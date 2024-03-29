## Linked List Cycle

[Leetcode](https://leetcode.com/problems/linked-list-cycle/)

Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again
by continuously following the next pointer. Internally, pos is used to denote the index of the
node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

Test Cases:

    Input: head = [3,2,0,-4], pos = 1
    Output: true
    Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

    Input: head = [1,2], pos = 0
    Output: true
    Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

    Input: head = [1], pos = -1
    Output: false
    Explanation: There is no cycle in the linked list.

## Solution
java
```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head==null || head.next==null) return false;

        ListNode slow = head, fast = head.next;

        while(fast!=null && fast.next!=null){
            if(slow == fast)
                return true;
            slow = slow.next;
            fast = fast.next.next;
        }

        return false;
    }
}
```
cpp, prev code:

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        //If one element or no element, no cycle
        if(head == NULL || head->next == NULL)
            return false;

        ListNode *slow = head, *fast = head;

        //Loop till slow catches fast pointer
        //(Loop condition should be and, idk why i did or before)
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
                return true;
        }

        return false;

        //Noob solution, changed whole list
        /*
        if(head == NULL)
            return false;

        ListNode* temp = head;

        while(temp->next != NULL)
        {
            if(temp->val==INT_MAX)
            {
                return true;
            }
            temp->val=INT_MAX;
            temp=temp->next;
        }
        return false;
        */

        //Another Soln: store traversed nodes by hashing
    }
};
```
## Approach
- Keep a set of traversed nodes, if current node present in already traversed one, its loop. taken 0(n) space extra.
- Fast and slow pointer. start with same but increment slow once and fast twice. If they meet i.e. slow==fast. its a loop else if null reached no loop.

- `Time Complexity: O(n)` //more than it but approx
- `Space Complexity: O(1)`
