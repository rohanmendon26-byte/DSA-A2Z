// Time Complexity: O(n)
// Space = O(n)



/**
 * 
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
    
    ListNode *reverseLinkedList(ListNode *head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode *newhead=reverseLinkedList(head->next);
        ListNode *front=head->next;
        front->next=head;
        head->next=NULL;

        return newhead;
    }

   
    
    bool isPalindrome(ListNode* head) {
        ListNode *fast=head;
        ListNode *slow=head;

        while(fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }

        ListNode *newhead=reverseLinkedList(slow->next);
        ListNode *first=head;
        ListNode *second=newhead;

        while(second!=NULL){
            if(first->val!=second->val){
                reverseLinkedList(newhead);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverseLinkedList(newhead);
        return true;
    }
};


// Example 1:


// Input: head = [1,2,2,1]
// Output: true
// Example 2:


// Input: head = [1,2]
// Output: false


// Input:
   
// Output: true
// Explanation: The given linked list is 1 -> 2 -> 1 -> 1 -> 2 -> 1, which is a palindrome.
// Input:
   
// Output: false
// Explanation: The given linked list is 10 -> 20 -> 30 -> 40 -> 50, which is not a palindrome.