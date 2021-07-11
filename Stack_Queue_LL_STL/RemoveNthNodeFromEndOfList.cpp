/* REMOVE Nth NODE FROM END OF LIST

Given the head of a linked list, remove the nth node from the end of the list and
return its head.

Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
*/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        //If one or zero elements
        if(head==NULL || head->next==NULL)
            return NULL;

        //For edge case where deleting head
        ListNode dummy(0,head);

        int count=0;
        ListNode* slow= &dummy, *fast= &dummy;
        //ListNode* slow=head, *fast=head; //error version

        //Make fast, n+1 nodes ahead
        while(count!=n+1 && fast!=NULL)
        {
            count++;
            fast = fast->next;
        }
        //Start both slow and fast simultaneously
        while(fast!=NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        //Delete/skip the nth node
        slow->next = slow->next->next;

        //return dummy's next not head or dummy
        return dummy.next;
    }

    //Another ans: first traverse to find length then traverse
    //till one node before the one to be deleted, O(2n)
};

/*
Test Case:
    Input: head = [1,2,3,4,5], n = 2
    Output: [1,2,3,5]

    Input: head = [1], n = 1
    Output: []

    Input: head = [1,2], n = 1
    Output: [1]

Time Complexity: O(n)
Space Complexity: O(1)
*/
