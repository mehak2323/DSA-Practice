/* ROTATE LIST

Given the head of a linked list, rotate the list to the right by k places.

Link: https://leetcode.com/problems/rotate-list/
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
    ListNode* rotateRight(ListNode* head, int k) {

        //If zero or one node, or no rotation
        if(head == NULL || head->next == NULL || k==0)
            return head;

        //First find length of the list as k can be bigger than size
        int count = 1;
        ListNode* temp = head;

        while(temp->next !=NULL)
        {
            count++;
            temp = temp->next;
        }

        //make a cycle (end joined to head)
        temp->next= head;

        //get how many moves from start we need, removing repeated rotation
        k = k%count;
        k = count-k;

        //Reach the position where we have to rotate
        ListNode* reached = head, *newhead;
        while(reached->next!=NULL && --k)
            reached = reached -> next;

        //update next of reached node
        newhead = reached->next;
        reached->next = NULL;

        return newhead;

        /*
        //Not needed if we make cycle beforehand
        //Also failed a case

        //get to last node after breaking
        ListNode *rest = newhead;
        while(rest->next!=NULL)
        {
            rest = rest->next;
        }

        //link second half to first half
        rest->next = head;
        */
    }

    //Another ans: (Brute force) get last node, put it in front, k times
};

/*
Test Case:
    Input: head = [1,2,3,4,5], k = 2
    Output: [4,5,1,2,3]

    Input: head = [0,1,2], k = 4
    Output: [2,0,1]

Time Complexity: O(n) //O(2n)
Space Complexity: O(1)
*/
