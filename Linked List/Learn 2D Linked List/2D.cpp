#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *back;

    public:
    Node(int data1,Node *next1,Node *back1){
        data=data1;
        next=next1;
        back=back1;
    }

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};

Node *ConvertArr2DLL(vector<int>arr){
    Node *head=new Node(arr[0]);
    Node *prev=head;
    for(int i=1;i<arr.size();i++){
        Node *temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}

Node *DeleteHead(Node *head){
    if(head==NULL || head->next==NULL)
       return NULL;
    
    Node *prev=head;
    head=head->next;

    head->back=nullptr;
    prev->next=nullptr;
    return head;
}

Node *DeleteTail(Node *head){
    Node *tail=head;
    Node *prev;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    prev=tail->back;
    prev->next=nullptr;
    tail->back=nullptr;
    delete tail;
    return head;

}

Node *DeletekthElement(Node *head,int k){
    if(head==NULL)
       return NULL;
    int cnt=0;

    Node *temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k)
            break;
        temp=temp->next;
    }

    Node *prev=temp->back;
    Node *front=temp->next;

    if(prev==NULL && front==NULL)
       return NULL;
    else if(prev==NULL)
       return DeleteHead(head);
    else if(front==NULL)
       return DeleteTail(head);
    
    prev->next=front;
    front->back=prev;

    temp->next=nullptr;
    temp->back=nullptr;

    delete temp;
    return head;
}


void deleteNode(Node *temp){
    Node *prev=temp->back;
    Node *front=temp->next;

    if(front==NULL){
        prev->next=nullptr;
        temp->back=nullptr;
        delete temp;
        return;
    }

    prev->next=front;
    front->back=prev;
    delete temp;
}


Node *InsertbeforeHead(Node *head,int val){
    Node *newnode=new Node(val,head,nullptr);
    newnode->next=head;
    head->back=newnode;

    return newnode;
}

Node *InsertbeforeTail(Node *head,int val){
    Node *tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node *prev=tail->back;
    Node *newnode=new Node(val,tail,prev);
    prev->next=newnode;
    tail->back=newnode;
    return head;

}


Node *InsertBeforeKthElement(Node *head,int k,int val){
    if(k==1){
        return InsertbeforeHead(head,val);
    }
    Node *temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==k)
           break;
        temp=temp->next;
    }

    Node *prev=temp->back;
    Node *newnode=new Node(val,temp,prev);
    prev->next=newnode;
    temp->back=newnode;
    return head;
}

void InsertBeforeNode(Node *node,int val){
    Node *prev=node->back;
    Node *newnode=new Node(val,node,prev);
    prev->next=newnode;
    node->back=newnode;
}

void print(Node *head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
}


int main(){
    vector<int>arr={12,5,8,7,9};
    Node *head=ConvertArr2DLL(arr);
    // head=DeleteHead(head);
    // head=DeleteTail(head);
    // head=DeletekthElement(head,5);
    // deleteNode(head->next->next);
    // head=InsertbeforeHead(head,43);
    // head=InsertbeforeTail(head,4);
    // head=InsertBeforeKthElement(head,4,20);
    InsertBeforeNode(head,100);
    print(head);
}