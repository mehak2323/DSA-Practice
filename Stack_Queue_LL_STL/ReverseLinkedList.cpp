/* REVERSE LINKED LIST

Given the head of a singly linked list, reverse the list, and return the reversed list.

Link: https://leetcode.com/problems/reverse-linked-list/
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
    ListNode* reverseList(ListNode* head) {

        if(head==nullptr)
            return head;

        //Using 3 pointer for next, prev, newHead
        ListNode* newHead = head;
        ListNode* prev = head;
        ListNode* Next = head->next;
        prev->next = nullptr;

        while(Next != nullptr)
        {
            newHead = Next;
            Next = Next->next;
            newHead->next = prev;
            prev=newHead;
        }

        return newHead;

        /*
        ListNode * newHead = nullptr;

        while(head->next != nullptr)
        {
            ListNode * Next= head->next;
            head->next = newHead;
            newHead = head;
            head = Next;
        }

        return newHead;
        */
    }
};
/*
Test Cases:
    Input: head = [1,2,3,4,5]
    Output: [5,4,3,2,1]

    Input: head = [1,2]
    Output: [2,1]

    Input: head = []
    Output: []

Time Complexity: O(n)
Space Complexity: O(1)
*/
