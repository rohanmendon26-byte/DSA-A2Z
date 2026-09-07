/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node* insertAtPos(Node* head, int p, int x) {
        // code here
        
        Node *temp=head;
        
        for(int i=0;i<p;i++){
            temp=temp->next;
        }
        
        Node *newnode=new Node(x);
        newnode->next=temp->next;
        newnode->prev=temp;
        if(temp->next !=NULL){
        temp->next->prev=newnode;
        }
        temp->next=newnode;
        
        return head;
    }
};


// Input: p = 2, x = 6
// 2 <-> 4 <->5
// Output: 2 <-> 4 <-> 5 <-> 6


// Input: p = 0, x = 44 
// 1 <-> 2 <-> 3 <-> 4
// Output: 1 <-> 44 <-> 2 <-> 3 <-> 4