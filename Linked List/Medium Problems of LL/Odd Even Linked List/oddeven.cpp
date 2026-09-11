// Time: O(n)
// Space: O(1) — we only create pointers; we don't create new nodes.


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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL)
           return head;
        ListNode *even=head->next;
        ListNode *odd=head;
        ListNode *evenHead=head->next;
        
        while(even!=NULL && even->next!=NULL){
            odd->next=odd->next->next;
            even->next=even->next->next;

            odd=odd->next;
            even=even->next;
        }

        odd->next=evenHead;

        return head;
    }
};

// Input: head = [1,2,3,4,5]
// Output: [1,3,5,2,4]

// Input: head = [2,1,3,5,6,4,7]
// Output: [2,3,6,7,1,5,4]