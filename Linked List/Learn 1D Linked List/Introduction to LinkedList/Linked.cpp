#include<bits/stdc++.h>
#include <ostream>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};

Node *convertArr2LL(vector<int>arr){
    Node *head=new Node(arr[0]);
    Node *mover=head;
    for(int i=1;i<arr.size();i++){
        Node *temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

int lengthofall(Node *head){
    int cnt=0;
    Node*temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
        cnt++;
    }
    return cnt;
}

int search(Node *head,int val){
    Node*temp=head;
    while(temp){
        if(temp->data==val)
           return 1;
        temp=temp->next;
    }
    return 0;
}


Node *removeshead(Node *head){
    if(head==NULL)
      return head;
    Node *temp=head;
    head=head->next;
    delete temp;
    return head;
}

Node *removetail(Node *head){
    if(head==NULL || head->next==NULL)
       return NULL;
    Node *temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }

    delete temp->next;
    temp->next=nullptr;

    return head;
}


void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    vector<int>arr={2,5,8,7};
    // Node *y=new Node(arr[1],nullptr);
    Node *head=convertArr2LL(arr);
    // cout<<lengthofall(head);
    // cout<<search(head,2)<<endl;
    // head=removeshead(head);
    head=removetail(head);
    printList(head);
}