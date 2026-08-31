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

//Delete by K places

Node *removek(Node *head,int k){
    if(head==NULL)
      return head;
    if(k==1){
        Node*temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    Node *temp=head;
    Node *prev=NULL;
    int cnt=0;

    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
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

Node *insertHead(Node *head,int val){
    return new Node(val,head);
}

Node *insertTail(Node *head,int val){
    if(head==NULL)
       return new Node(val);

    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node *newNode=new Node(val);
    temp->next=newNode;
    return head;
}

Node *insertPosition(Node *head,int el,int k){
    if(head==NULL){
        if(k==1){
            return new Node(el);
        }
        else{
            return head;
        }
    }

    if(k==1)
       return new Node(el,head);
    
    int cnt=0;
    Node *temp=head;

    while(temp!=NULL){
        cnt++;
        if(cnt==k-1){
            Node *x=new Node(el,temp->next);
            temp->next=x;
            break;
        }
        temp=temp->next;
    }

    return head;
}


Node *insertBeforeValue(Node *head,int el,int val){
    if(head==NULL){
        return NULL;
    }

    if(head->data==val)
       return new Node(el,head);
    
    Node *temp=head;

    while(temp->next!=NULL){
        
        if(temp->next->data==val){
            Node *x=new Node(el,temp->next);
            temp->next=x;
            break;
        }
        temp=temp->next;
    }

    return head;
}


int main(){
    vector<int>arr={2,5,8,7};
    // Node *y=new Node(arr[1],nullptr);
    Node *head=convertArr2LL(arr);
    // cout<<lengthofall(head);
    // cout<<search(head,2)<<endl;
    // head=removeshead(head);
    // head=removetail(head);
    // head=removek(head,3);
    // head=insertHead(head,23);
    // head=insertTail(head,23);
    // head=insertPosition(head,45,4);   //O(n)
    // head=insertBeforeValue(head,100,7);
    printList(head);
}