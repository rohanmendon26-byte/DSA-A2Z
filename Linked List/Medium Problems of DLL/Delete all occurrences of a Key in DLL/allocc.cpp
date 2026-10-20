/*Structure of the doubly linked list  Node 
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};*/

// Time complexity: \(O(n)\), because each node is visited once.

// Auxiliary space: \(O(1)\), because only a few pointers are used.

class Solution {
  public:
    Node* deleteAllOccurOfX(Node* head, int x) {
        // code here
        Node *temp=head;
        while(temp!=NULL){
            if(temp->data==x){
                if(temp==head){
                    head=head->next;
                }
                Node *nextnode=temp->next;
                Node *prevnode=temp->prev;
                
                if(nextnode)
                    nextnode->prev=prevnode;
                if(prevnode)
                    prevnode->next=nextnode;
                free(temp);
                temp=nextnode;
            }
            else{
                temp=temp->next;
            }
        }
        return head;
    }
};


// Input: 2<->2<->10<->8<->4<->2<->5<->2, x = 2
// Output:  10<->8<->4<->5
// Explanation: 
// All Occurrences of 2 have been deleted.


// Input: head = 9<->1<->3<->4<->5<->1<->8<->4, x = 9
// Output: 1<->3<->4<->5<->1<->8<->4
// Explanation: 
// All Occurrences of 9 have been deleted.