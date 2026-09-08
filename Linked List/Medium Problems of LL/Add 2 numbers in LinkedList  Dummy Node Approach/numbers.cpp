/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
  public:
  
    Node *reverse(Node *head){
        Node *last=NULL;
        Node *current=head;
        while(current!=NULL){
            Node *temp=current->next;
            current->next=last;
            last=current;
            current=temp;
        }
        return last;
    }
    
    Node* addTwoLists(Node* head1, Node* head2) {
        // code here
        Node *temp1=reverse(head1);
        Node *temp2=reverse(head2);
        
        Node *dummynode=new Node(-1);
        Node *cur=dummynode;
        int carry=0;
        while(temp1!=NULL || temp2!=NULL){
            int sum=carry;
            
            if(temp1)
              sum+=temp1->data;
            if(temp2)
               sum+=temp2->data;
            
            Node *newnode=new Node(sum%10);
            carry=sum/10;
            
            cur->next=newnode;
            cur=cur->next;
            
            if(temp1)
              temp1=temp1->next;
            if(temp2)
              temp2=temp2->next;
        }
        
        if(carry){
            Node *newnode=new Node(carry);
            cur->next=newnode;
        }
        
        Node *ans=reverse(dummynode->next);
        while (ans != NULL && ans->data == 0 && ans->next != NULL) {
                   ans = ans->next;
        }
        return ans;
    }
};

input:1->2->3
      9->9->9
Output:  1 -> 1 -> 2 -> 2
Explanation: Given numbers are 123 and 999. There sum is 1122.
    
Input: 0 -> 0 -> 6 -> 3
       0 -> 7
    
Output: 7 -> 0 
Explanation: Given numbers are 63 and 7. There sum is 70.
    