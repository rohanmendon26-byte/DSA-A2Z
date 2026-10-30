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


    ListNode* findkthnode(ListNode* temp, int k){
        k=k-1;
        while(temp!=NULL && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }

    ListNode* reverselinkedlist(ListNode* head){
        if(head==NULL || head->next==NULL)
           return NULL;
        
        ListNode *current=head;
        ListNode *prev=NULL;
        while(current!=NULL){
            ListNode *temp=current->next;
            current->next=prev;
            prev=current;
            current=temp;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp=head;
        ListNode *prevlast=NULL;

        while(temp!=NULL){
            ListNode *kthnode=findkthnode(temp,k);
            if(kthnode==NULL){
                if(prevlast)
                   prevlast->next=temp;
                   break;
            }
            ListNode *nextnode=kthnode->next;
            kthnode->next=NULL;
            reverselinkedlist(temp);
            if(temp==head)
              head=kthnode;
            else
              prevlast->next=kthnode;
            
            prevlast=temp;
            temp=nextnode;

            }
            return head;
        }
};


// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]


// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]


// -------------------------------------------------------------------------------------------

// Complexity	Value
// Time	\(O(n)\)
// Auxiliary space	\(O(1)\)


class Solution {
  public:

    Node *findkthnode(Node *temp, int k){
        k = k - 1;

        while(temp != NULL && k > 0){
            k--;
            temp = temp->next;
        }

        return temp;
    }

    Node *reverselinkedlist(Node *head){
        Node *current = head;
        Node *prev = NULL;

        while(current != NULL){
            Node *temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }

        return prev;
    }

    Node *reverseKGroup(Node *head, int k) {

        Node *temp = head;
        Node *prevlast = NULL;

        while(temp != NULL){

            Node *kthnode = findkthnode(temp, k);

            // If fewer than k nodes remain,
            // find the last node of the remaining list
            if(kthnode == NULL){
                kthnode = temp;

                while(kthnode->next != NULL){
                    kthnode = kthnode->next;
                }
            }

            Node *nextnode = kthnode->next;
            kthnode->next = NULL;

            reverselinkedlist(temp);

            if(temp == head){
                head = kthnode;
            }
            else{
                prevlast->next = kthnode;
            }

            prevlast = temp;
            temp = nextnode;
        }

        return head;
    }
};
