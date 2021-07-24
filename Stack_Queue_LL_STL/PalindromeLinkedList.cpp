/** PALINDROME LINKED LIST

Given the head of a singly linked list, return true if it is a palindrome.

Link: https://leetcode.com/problems/palindrome-linked-list/
*/

/*
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
    bool isPalindrome(ListNode* head) {

        int length = 1;
        ListNode *temp=head;

        //Find total length to get mid
        while(temp->next != NULL)
        {
            length++;
            temp=temp->next;
        }

        ListNode * second= head, *first = head, *prev = head;
        int mid = length/2, count = 0;

        //While we reach mid, reverse the previous nodes
        while(count!=mid)
        {
            first = second;
            second = second ->next;
            first ->next = prev;
            prev = first;
            count++;
        }
        head->next = NULL;

        //Now compare if the values are equal

        //If odd , move one node ahead
        if(length%2 !=0)
            second=second->next;

        //For rest of half lists
        while(first!=NULL && second!=NULL)
        {
            if(first->val != second->val)
                return false;
            first = first->next;
            second = second->next;
        }

        return true;
    }

    //Note: I did 2 pass, it can be done with one traversal
    //If we use slow and fast pointer to get mid and the same
    //time, keep reversing nodes till slow pointer node, then check
    //for both lists from mid to end points if palindrome
};

/**
Test Cases:
    Input: head = [1,2,2,1]
    Output: true

    Input: head = [1,2]
    Output: false

Time Complexity: O(n) //For me O(2n), can be done O(n + n/2)
Space Complexity: O(1)
*/
