#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node *prev;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
                this->prev = NULL;
            }
        };

*****************************************************************/

void deleteNode(Node * ( & head), int pos) {
    // Write your code here.
    if(head==NULL){
        return;
    }
    int cnt=0;
    Node *temp=head;
    while(temp!=NULL && cnt<pos){
        cnt++;
        temp=temp->next;
    }

    if(temp==NULL)
      return;
    
    if(temp==head){
        head=head->next;
        temp->next=nullptr;
        head->prev=nullptr;
        delete temp;
        return;
    }

    if(temp->next==NULL){
        Node *prev=temp->prev;
        prev->next=temp->next;
        temp->prev=nullptr;
        delete temp;
        return;

    }

    Node *prev=temp->prev;
    Node *front=temp->next;
    prev->next=temp->next;
    front->prev=prev;
    temp->prev=nullptr;
    temp->next=nullptr;
    delete temp;

}