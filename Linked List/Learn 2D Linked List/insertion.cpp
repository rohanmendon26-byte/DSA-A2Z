#include <bits/stdc++.h> 
/************************************************************

    Following is the linkedList class structure:

    class Node {
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int val) {
            this->data = val;
            next = NULL;
            prev = NULL;
        }
        ~Node() {
            if(next != NULL || prev != NULL){
                delete next;
            }
        }
};

************************************************************/

Node *insertBeforehead(int k, int val, Node *head){
    Node *newnode=new Node(val);

    newnode->next=head;
    head->prev=newnode;

    return newnode;
}

Node* insert(int k, int val, Node *head) {
    // Write Your Code Here.
    if(k==0)
       return insertBeforehead(k,val,head);
    int cnt=0;
    Node *temp=head;
    while(temp!=NULL && cnt<k){
        cnt++;
        temp=temp->next;
    }
    Node *newnode=new Node(val);
    
    if(temp==NULL){
        Node *last=head;
        while(last->next!=NULL){
            last=last->next;
        }

        last->next=newnode;
        newnode->prev=last;
        return head;
    }

    Node *prev= temp->prev;
    prev->next=newnode;
    newnode->prev=prev;
    newnode->next=temp;
    temp->prev=newnode;

    return head;

}

// ‘K’ = 3, ‘VAL’ = 4
// list = [1, 2, 3]
// Output: [1, 2, 3, 4]

// ‘K’ = 3, ‘VAL’ = 4
// list = [10, 11, 5]
// Output: [10, 11, 4, 5]

