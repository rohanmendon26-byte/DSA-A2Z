/* Structure of a link list node
class Node {
  public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
*/
class Solution {
  public:
    Node* removeDuplicates(Node* headRef) {
        // code here
        Node *temp=headRef;
        while(temp!=NULL && temp->next!=NULL){
            Node *nextnode=temp->next;
            while(nextnode!=NULL && nextnode->data==temp->data){
                Node *duplicate=nextnode;
                nextnode=nextnode->next;
                delete duplicate;
            }
            temp->next=nextnode;
            if(nextnode!=NULL)
               nextnode->prev=temp;
            temp=temp->next;
        }
        return headRef;
    }
};


// Input: head: 1<->1<->1<->2<->3<->4
// Output: 1<->2<->3<->4
// Explanation: Only the first occurance of node with value 1 is retained along with other distinct values. 

// Input: head: 1<->2<->2<->3<->3<->4<->4
// Output: 1<->2<->3<->4
// Explanation:
// Only the first occurance of node