/* MERGE TWO SORTED LISTS

Merge two sorted linked lists and return it as a sorted list. The list should be
made by splicing together the nodes of the first two lists.

Link: https://leetcode.com/problems/merge-two-sorted-lists/
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

/*
Test Case:
    Input: l1 = [1,2,4], l2 = [1,3,4]
    Output: [1,1,2,3,4,4]

    Input: l1 = [], l2 = []
    Output: []

    Input: l1 = [], l2 = [0]
    Output: [0]

Time Complexity: O(n1 + n2)
Space Complexity: O(1)
*/
