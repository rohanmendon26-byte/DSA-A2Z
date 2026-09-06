/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/

// Time  = O(n)
// Space = O(1)

class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        if(head==NULL || head->next==NULL)
           return NULL;
        
        Node *last=NULL;
        Node *current=head;
        while(current!=NULL){
            last=current->prev;
            current->prev=current->next;
            current->next=last;
            current=current->prev;
        }
        
        return last->prev;
    }
};

// Output: 
// 5 <-> 4 <-> 3
// 3 <-> 4 <-> 5

// Output: 
// 196 <-> 59 <-> 122 <-> 75
// 75 <-> 122 <-> 59 <-> 196