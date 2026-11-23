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


// Complexity	Value	Reason
// Time	O(N + M)	Visit each node at most once
// Space	O(1)	No new list nodes are created, except the dummy node


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *t1=list1;
        ListNode *t2=list2;
        ListNode *dummynode=new ListNode(-1);
        ListNode *temp=dummynode;

        while(t1!=NULL && t2!=NULL){
            if(t1->val < t2->val){
                temp->next=t1;
                temp=t1;
                t1=t1->next;
            }
            else{
                temp->next=t2;
                temp=t2;
                t2=t2->next;
            }
        }

        if(t1){
            temp->next=t1;
        }
        else{
            temp->next=t2;
        }
        return dummynode->next;
    }
};


// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]

// Input: list1 = [], list2 = []
// Output: []

// Input: list1 = [], list2 = [0]
// Output: [0]