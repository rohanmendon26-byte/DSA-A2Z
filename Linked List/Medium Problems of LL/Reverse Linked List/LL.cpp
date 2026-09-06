// Time  = O(n)
// Space = O(1)

#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    if(head==NULL || head->next==NULL)
       return NULL;
    
    LinkedListNode *prev=NULL;
    LinkedListNode *current=head;
    while(current!=NULL){
        LinkedListNode *temp=current->next;
        current->next=prev;
        prev=current;
        current=temp;
    }

    return prev;
}


// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]

// Input: head = [1,2]
// Output: [2,1]