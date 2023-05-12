### Merge Two Sorted Lists

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Example 1:
```
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
```
Example 2:
```
Input: list1 = [], list2 = []
Output: []
```
Example 3:
```
Input: list1 = [], list2 = [0]
Output: [0]
```

Constraints:
- The number of nodes in both lists is in the range [0, 50].
- -100 <= Node.val <= 100
- Both list1 and list2 are sorted in non-decreasing order.

  
### Solution
Java: 

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        //No nodes in either
        if(list1==null) return list2;
        if(list2==null) return list1;

        //Take head1 or head2 based on which node is bigger, initialize prev
        ListNode prev = new ListNode(-101);
        ListNode head = prev;

        //Till one of the lists ends
        while(list1!=null && list2!=null){
            //If second node smaller, add it
            if(list2.val < list1.val){
                prev.next = list2;
                list2 = list2.next;
            }
            //Else iterate in first one
            else{
                prev.next = list1;
                list1 = list1.next;
            }
            prev = prev.next;
        }

        //Add remaining list to end
        prev.next = list1==null ? list2 : list1;

        return head.next;
    }
}
```
Another, Recursion, mentioned in Editorial
```java
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        }
        else if (l2 == null) {
            return l1;
        }
        else if (l1.val < l2.val) {
            l1.next = mergeTwoLists(l1.next, l2);
            return l1;
        }
        else {
            l2.next = mergeTwoLists(l1, l2.next);
            return l2;
        }

    }
}
```

Cpp, previous:
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        if(l1==NULL) return l2; //If l1 empty, ans is l2
        if(l2==NULL) return l1; //If l2 empty, ans is l1

        //We assign ans head to l1, if l2 is smaller, swap
        if(l1->val >l2->val)
            swap(l1,l2);

        ListNode * ans = l1, *temp=NULL;

        //While both don't reach end
        while(l1!=NULL && l2!=NULL)
        {
            //keep moving till l1 has value less than l2
            while(l1!= NULL && l1->val <= l2->val)
            {
                //store current node, in case we need to assign it's next
                temp=l1;
                //move l1 pointer ahead
                l1=l1->next;
            }
            //Now, l2 has smaller than l1 element
            //assign l1's previous node's next to l2
            temp->next = l2;
            //swap l1 and l2 as l1 should be smaller node
            swap(l1,l2);
        }

        return ans;
    }
    //Another ans: To make a new linked list based on every l1 or l2 values (brute force)
};
```

### Approach:
1. Recursion , as mentioned above code, (uses n+m stack space extra) - pass l1.next or l2.next in function based on which is smaller
2. Make a common head and previous node, while both lists are remaining, check which is smaller and iterate l1 or l2 accordingly while changing prev's next and moving prev node to l1 or l2. Then add remaining list.
3. Take l1 as main list, swap with l2 if bigger, keep iterating l1 till l2 is smaller, then change prev's next to l2 and swap l1 and l2 to make l1 main path.

- `Time complexity : O(n+m)` 
Because exactly one of l1 and l2 is incremented on each loop iteration, the while loop runs for a number of iterations equal to the sum of the lengths of the two lists. All other work is constant, so the overall complexity is linear.

- `Space complexity : O(1)` 
The iterative approach only allocates a few pointers, so it has a constant overall memory footprint.
