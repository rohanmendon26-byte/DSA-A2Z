/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/


// Time: O(n) — one traversal of the list
// Space: O(1) extra space — we reuse the existing nodes; the three dummy nodes are constant extra space.

Node* sortList(Node *head){
    // Write your code he
    if(head==NULL || head->next==NULL)
       return head;

    Node *zerohead=new Node(-1);
    Node *onehead=new Node(-1);
    Node *twohead=new Node(-1);
    Node *zero=zerohead;
    Node *one=onehead;
    Node *two=twohead;

    Node *temp=head;

    while(temp!=NULL){
        if(temp->data==0){
            zero->next=temp;
            zero=zero->next;
        }
        else if(temp->data==1){
            one->next=temp;
            one=one->next;
        }
        else{
            two->next=temp;
            two=two->next;
        }

        temp=temp->next;
    }

    zero->next=(onehead->next)?(onehead->next):(twohead->next);
    one->next=twohead->next;
    two->next=NULL;

    Node *newnode=zerohead->next;

    delete zerohead;
    delete onehead;
    delete twohead;

    return newnode;
}


// Input: head = 1 → 2 → 2 → 1 → 2 → 0 → 2 → 2
// Output: 0 → 1 → 1 → 2 → 2 → 2 → 2 → 2
// Explanation: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between. The final list will be:

// Input: head = 2 → 2 → 0 → 1
// Output: 0 → 1 → 2 → 2
// Explanation: After arranging all the 0s, 1s and 2s in the given format, the output will be: