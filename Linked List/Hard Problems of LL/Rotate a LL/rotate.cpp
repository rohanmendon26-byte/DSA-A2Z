
// Find length	O(N)
// Find kth node	O(N)
// Rotation and reconnection	O(1)
// Total time	O(N)
// Space	O(1)



class Solution {
public:

    ListNode* findkthnode(ListNode*temp,int k){
        int cnt=1;
        while(temp!=NULL){
            if(cnt==k)
               return temp;
            cnt++;
            temp=temp->next;
        }
        return temp;
    }
    

    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL ||k==0){
            return head;
        }
        ListNode *tail=head;
        int len=1;
        while(tail->next!=NULL){
            len++;
            tail=tail->next;
        }
        if(k%len==0)
           return head;
        k=k%len;
        tail->next=head;
        ListNode *newnode=findkthnode(head,len-k);
        head=newnode->next;
        newnode->next=NULL;
        return head;
    }
};

// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]

// Input: head = [0,1,2], k = 4
// Output: [2,0,1]